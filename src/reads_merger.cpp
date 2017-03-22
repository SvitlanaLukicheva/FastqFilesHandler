#include "reads_merger.hpp"

using namespace std;


ReadsMerger::ReadsMerger(list<string> input_files, string output_file)
{
    my_input_files = input_files;
    my_output_file = output_file;
}


bool ReadsMerger::MergeReads()
{
    bool result = true;
    cout << "Merging the files....\n";
    
    ofstream output (my_output_file.c_str());
    if(output.is_open())
    {
        if(my_input_files.size() % 2 != 0)
        {
            cout << "FAILURE: Invalid number of input files provided: " << my_input_files.size() << "\n";
            result = -1;
        }
        else
        {
            for(list<string>::iterator it=my_input_files.begin(); it != my_input_files.end(); it++)
            {
                string file_1 = *it;
                it++;
                string file_2 = *it;
                cout << "=== Reading files " << file_1 << " and " << file_2 << "\n";
                ifstream input_1(file_1.c_str());
                ifstream input_2(file_2.c_str());
                if(input_1.is_open() && input_2.is_open())
                    merge_reads(&input_1, &input_2, &output);
                else
                {
                    cout << "=== FAILURE: Unable to open input files\n";
                    result = -1;
                    break;
                }
            }
        }
        output.close();
    }
    else
    {
        cout << "=== FAILURE: Unable to open the output file " << my_output_file << "\n";
        result = false;
    }
    
    if(result == true)
        cout << "=== SUCCESS: Files successfully merged\n";
    
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
            cout << "=== Reading failed\n";
            result = false;
        }
        else
        {
            please_continue = false;
        }
    }	

    return result;
}


bool ReadsMerger::read_and_write_lines(ifstream *input, ofstream *output)
{
    bool result = false;
    string line_1, line_2, line_3, line_4;

    if(getline(*input, line_1))  // comment
    {
        if(getline(*input, line_2))  // sequence
        {
            if(getline(*input, line_3))  // '+' symbol
            {
                if(getline(*input, line_4))  // scores
                {
                    *output << line_1 << "\n";  // comment
                    *output << line_2 << "\n";  // sequence
                    *output << line_3 << "\n";  // '+' symbol
                    *output << line_4 << "\n";  // scores
                    result = true;
                }
            }
        }
    }

    return result;
}
