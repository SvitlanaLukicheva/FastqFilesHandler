/* 
 * File:   fastq_to_fasta_converter.hpp
 * Author: Svitlana
 *
 * Created on 22 mars 2017, 15:48
 */

#ifndef FASTQ_TO_FASTA_CONVERTER_HPP
#define FASTQ_TO_FASTA_CONVERTER_HPP


#include <string>
using namespace std;

class FastqToFastaConverter
{
public:
    bool Convert(string input, string output);
    
private:
    bool convert(ifstream *input, ofstream *output);
};

#endif /* FASTQ_TO_FASTA_CONVERTER_HPP */

