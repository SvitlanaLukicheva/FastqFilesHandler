#include "main_job.hpp"


/**
 * Writes the four lines provided as parameter to the output file
 * @param line_1 - FASTA comment
 * @param line_2 - DNA sequence
 * @param line_3 - '+' symbol
 * @param line_4 - scores
 * @param output
 * @return 
 */
bool MainJob::write_lines(string line_1, string line_2, string line_3, string line_4, ofstream* output)
{
    bool result; 
    
    if(output != NULL)
    {
        *output << line_1 << "\n";  // comment
        *output << line_2 << "\n";  // sequence
        *output << line_3 << "\n";  // '+' symbol
        *output << line_4 << "\n";  // scores
    }
    else
    {
        output_formatter.DisplayError("Invalid output file");
        result = -1;
    }
    
    return result;
}


/**
 * Reads four lines (corresponding to comment, sequence, '+' symbol and scores)
 * from the input file and writes them to the output file
 * @param input
 * @param output
 * @return 
 */
bool MainJob::read_and_write_lines(ifstream *input, ofstream *output)
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
                    result = write_lines(line_1, line_2, line_3, line_4, output);
                }
            }
        }
    }

    return result;
}