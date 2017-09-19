#include "reads_merger.hpp"


ReadsMerger::ReadsMerger(list<string> input_files, string output_file)
{
    my_input_files = input_files;
    my_output_file = output_file;
}


bool ReadsMerger::DoTheJob()
{
    bool result = true;
    output_formatter.DisplayInfo("Merging the files....");
    
    ofstream output (my_output_file.c_str());
    if(output.is_open())
    {
        if(my_input_files.size() % 2 != 0)
        {
            output_formatter.DisplayError("Invalid number of input files provided: " + my_input_files.size());
            result = -1;
        }
        else
        {
            for(list<string>::iterator it=my_input_files.begin(); it != my_input_files.end(); it++)
            {
                string file_1 = *it;
                it++;
                string file_2 = *it;
                
                output_formatter.DisplayInfo("Reading files " + file_1 + " and " + file_2);
                ifstream input_1(file_1.c_str());
                ifstream input_2(file_2.c_str());
                
                if(input_1.is_open() && input_2.is_open())
                    merge_reads(&input_1, &input_2, &output);
                else
                {
                    output_formatter.DisplayError("Unable to open input files");
                    result = -1;
                    break;
                }
            }
        }
        output.close();
    }
    else
    {
        output_formatter.DisplayError("Unable to open the output file " + my_output_file);
        result = false;
    }
    
    if(result == true)
        output_formatter.DisplayInfo("Files successfully merged");
    
    return result;
}


bool ReadsMerger::merge_reads(ifstream *input_1, ifstream *input_2, ofstream *output)
{
    bool result = true;
    bool please_continue = true;

    while(please_continue)
    {
        bool write_1_ok = this->read_and_write_lines(input_1, output);
        bool write_2_ok = this->read_and_write_lines(input_2, output);
        if(write_1_ok && write_2_ok)
                please_continue = true;
        else if(write_1_ok || write_2_ok)
        {
            please_continue = false;
            output_formatter.DisplayError("Reading failed");
            result = false;
        }
        else
        {
            please_continue = false;
        }
    }	

    return result;
}
