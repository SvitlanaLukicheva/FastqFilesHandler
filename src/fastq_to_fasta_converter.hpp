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
    bool Convert(std::string input, std::string output);
    
private:
    bool convert(std::ifstream *input, std::ofstream *output);
};


#endif /* FASTQ_TO_FASTA_CONVERTER_HPP */

