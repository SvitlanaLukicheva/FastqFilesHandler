/* 
 * File:   fastq_to_fasta_converter.hpp
 * Author: Svitlana
 *
 * Created on 22 mars 2017, 15:48
 */

#ifndef FASTQ_TO_FASTA_CONVERTER_HPP
#define FASTQ_TO_FASTA_CONVERTER_HPP


#include "main_job.hpp"

using std::ifstream;
using std::ofstream;
using std::string;


class FastqToFastaConverter : MainJob
{
    public:
        FastqToFastaConverter(string input, string output);
        bool DoTheJob();

    private:
        string my_input_file;
        string my_output_file;

        bool read_and_write_lines(ifstream *input, ofstream *output);
};


#endif /* FASTQ_TO_FASTA_CONVERTER_HPP */

