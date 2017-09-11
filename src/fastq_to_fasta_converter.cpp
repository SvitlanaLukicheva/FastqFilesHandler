#include "fastq_to_fasta_converter.hpp"


FastqToFastaConverter::FastqToFastaConverter(string input, string output)
{
    my_input_file = input;
    my_output_file = output;
}


bool FastqToFastaConverter::DoTheJob()
{
    bool result;
    output_formatter.DisplayInfo("Converting the file....");
    
    ifstream input_stream(my_input_file.c_str());
    ofstream output_stream(my_output_file.c_str());
    
    if(input_stream.is_open() && output_stream.is_open())
    {
        bool please_continue = true;
        while(please_continue)
        {
            please_continue = read_and_write_lines(&input_stream, &output_stream);
        }
    }
    else
    {
        if(!input_stream.is_open())
            output_formatter.DisplayError("Unable to open the input file " + my_input_file);
        if(!output_stream.is_open())
            output_formatter.DisplayError("Unable to open the output file " + my_output_file);
        result = false;
    }
    
    if(result)
        output_formatter.DisplayInfo("File successfully converted!!");
    
    return result;
}


bool FastqToFastaConverter::read_and_write_lines(ifstream* input, ofstream* output)
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