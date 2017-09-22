#include <cmath>
#include "seq_remover.hpp"

using namespace std;


/**
 * Constructor
 * @param input_files
 * @param output_folder
 * @param sequence_to_remove
 */
SeqRemover::SeqRemover(list<string> input_files, string output_folder, list<string> sequence_to_remove, int begin_index, int end_index)
{
    my_input_files          = input_files;
    my_output_folder        = output_folder;
    my_sequences_to_remove  = sequence_to_remove;
    my_begin_index          = begin_index;
    my_end_index            = end_index;
    sequences_removed       = 0;
}


/**
 * Reads the list of paired-end files and calls the method remove_sequence_from_files
 * to remove the DNA sequence provided by the user
 * @return 
 */
bool SeqRemover::DoTheJob()
{
    bool result = false;
    
    if(my_input_files.size() % 2 != 0)
    {
        char files_number_as_string[21];
        sprintf(files_number_as_string, "%d", my_input_files.size());
        output_formatter.DisplayError("Invalid number of input files provided: " + string(files_number_as_string));
    }
    else
    {
        for(list<string>::iterator it=my_input_files.begin(); it != my_input_files.end(); it++)
        {
            string file_1 = *it;
            it++;
            string file_2 = *it;

            ifstream input_1(file_1.c_str());
            ifstream input_2(file_2.c_str());

            string file_1_base_name = file_1.substr(file_1.find_last_of("/\\") + 1);
            string file_2_base_name = file_2.substr(file_2.find_last_of("/\\") + 1);
            string output_1_file_name = my_output_folder + "/filtered_" + file_1_base_name.c_str();
            string output_2_file_name = my_output_folder + "/filtered_" + file_2_base_name.c_str();
            ofstream output_1 (output_1_file_name.c_str());
            ofstream output_2 (output_2_file_name.c_str());

            if(input_1.is_open() && input_2.is_open())
            {
                if(output_1.is_open() && output_2.is_open())
                {
                    output_formatter.DisplayInfo("Handling files " + file_1 + " and " + file_2 + "...");
                    output_formatter.DisplayInfo("Output will be stored in files " + output_1_file_name + " and " + output_2_file_name);
                    result = remove_sequence_from_files (&input_1, &input_2, &output_1, &output_2);
                }
                else
                {
                    output_formatter.DisplayError("Unable to open output files: " + output_1_file_name + ", " + output_2_file_name);
                    break;
                }
            }
            else
            {
                output_formatter.DisplayError("Unable to open input files: " + file_1 + ", " + file_2.c_str());
                break;
            }
        }
    }
    
    if(result == true)
    {
        output_formatter.DisplayInfo("Sequences successfully removed from files");
        char sequences_removed_as_string[21];
        sprintf(sequences_removed_as_string, "%d", sequences_removed);
        output_formatter.DisplayInfo(string(sequences_removed_as_string) + " read pairs removed");
    }
    
    return result;
}


/**
 * Takes a pair of input paired-end files, searches all the instances of the sequence provided by the user
 * and removes each pair of reads containing this sequence. The resulting paired-end output files are
 * written to output_1 and output_2.
 * @param input_1
 * @param input_2
 * @param output_1
 * @param output_2
 * @return 
 */
bool SeqRemover::remove_sequence_from_files(ifstream* input_1, ifstream* input_2, ofstream* output_1, ofstream* output_2)
{
    bool result          = true;
    bool please_continue = true;
    bool first_read_ok, second_read_ok;
    string filtered_reads_file_name = my_output_folder + "/filtered_reads.fastq";
    
    string line_1_1, line_1_2, line_1_3, line_1_4;
    string line_2_1, line_2_2, line_2_3, line_2_4;
    
    ofstream filtered_reads_file (filtered_reads_file_name.c_str());
    
    while(please_continue)
    {
        first_read_ok = getline(*input_1, line_1_1) &&
                        getline(*input_1, line_1_2) &&
                        getline(*input_1, line_1_3) &&
                        getline(*input_1, line_1_4);
        second_read_ok = getline(*input_2, line_2_1) &&
                         getline(*input_2, line_2_2) && 
                         getline(*input_2, line_2_3) &&
                         getline(*input_2, line_2_4);
        if(first_read_ok && second_read_ok)
        {
            if(check_matches(line_1_2, line_2_2) == false)
            {
                result = write_lines(line_1_1, line_1_2, line_1_3, line_1_4, output_1);
                result = result && write_lines(line_2_1, line_2_2, line_2_3, line_2_4, output_2);
            }
            else
            {
                sequences_removed++;
                result = write_lines(line_1_1, line_1_2, line_1_3, line_1_4, &filtered_reads_file);
                result = result && write_lines(line_2_1, line_2_2, line_2_3, line_2_4, &filtered_reads_file);
                output_formatter.DisplayDebug("Removing sequences:");
                output_formatter.DisplayDebug("File 1: " + line_1_1);
                output_formatter.DisplayDebug("File 2: " + line_2_1);
            }
        }
        else
        {
            please_continue = false;
            if(first_read_ok)
            {
                output_formatter.DisplayError("Input files do not have the same length!! Second file is shorter!!");
                result = false;
            }
            if(second_read_ok)
            {
                output_formatter.DisplayError("Input files do not have the same length!! First file is shorter!!");
                result = false;
            }
        }
    }
    
    return result;
}


/**
 * Checks whether the first and/or the second read contain one of the specified
 * sequences to remove
 * @param first_read
 * @param second_read
 * @return 
 */
bool SeqRemover::check_matches(string first_read, string second_read)
{
    bool result = false;
    
    string sequence_to_search;
    for (list<string>::iterator it=my_sequences_to_remove.begin(); it != my_sequences_to_remove.end(); ++it)
    {
        int new_begin_index = fmin(my_begin_index, first_read.length());
        int new_end_index   = fmin(my_end_index, first_read.length());
        string first_sub_read = first_read.substr(new_begin_index, new_end_index - my_begin_index);
        new_begin_index = fmax(my_begin_index, second_read.length());
        new_end_index   = fmin(my_end_index, second_read.length());
        string second_sub_read = second_read.substr(new_begin_index, new_end_index - my_begin_index);
                
        sequence_to_search = *it;
        if(first_sub_read.find(sequence_to_search) != string::npos ||
           second_sub_read.find(sequence_to_search) != string::npos)  // a match is found
        {
            result = true;
            break;
        }
    }
    
    return result;
}