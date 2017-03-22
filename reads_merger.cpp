#include "reads_merger.hpp"


bool ReadsMerger::MergeReads(ifstream *input_1, ifstream *input_2, ofstream *output)
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
