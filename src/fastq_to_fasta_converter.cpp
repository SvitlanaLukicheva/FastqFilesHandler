#include <fstream>
#include <iostream>

#include "fastq_to_fasta_converter.hpp"

using namespace std;


bool FastqToFastaConverter::Convert(string input, string output)
{
    bool result;
    
    ifstream input_stream(input.c_str());
    ofstream output_stream(output.c_str());
    
    if(input_stream.is_open() && output_stream.is_open())
    {
        result = convert(&input_stream, &output_stream);
    }
    else
    {
        if(!input_stream.is_open())
            cout << "=== FAILURE: Unable to open the input file " << input << "\n";
        if(!output_stream.is_open())
            cout << "=== FAILURE: Unable to open the output file " << output << "\n";
        result = false;
    }
    
    return result;
}


bool FastqToFastaConverter::convert(ifstream* input, ofstream* output)
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
                    result = true;
                }
            }
        }
    }
    
    return result;
}