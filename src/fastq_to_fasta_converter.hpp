/* 
 * File:   fastq_to_fasta_converter.hpp
 * Author: Svitlana
 *
 * Created on 22 mars 2017, 15:48
 */

#ifndef FASTQ_TO_FASTA_CONVERTER_HPP
#define FASTQ_TO_FASTA_CONVERTER_HPP


#include <string>


class FastqToFastaConverter
{
public:
    FastqToFastaConverter(std::string input, std::string output);
    bool Convert();
    
private:
    std::string my_input_file;
    std::string my_output_file;
    
    bool read_and_write_lines(std::ifstream *input, std::ofstream *output);
};


#endif /* FASTQ_TO_FASTA_CONVERTER_HPP */

