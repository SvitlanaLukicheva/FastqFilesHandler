#ifndef READS_MERGER_HPP
#define READS_MERGER_HPP


#include <fstream>
#include <iostream>
#include <list>
#include <string>

using namespace std;


class ReadsMerger
{
    public:
        ReadsMerger(list<char*> input_files, char* output_files);
        bool MergeReads();

    private:
        list<char*> my_input_files;
        char* my_output_file;
        
        bool merge_reads(std::ifstream *input_1, std::ifstream *input_2, std::ofstream *output);
        bool read_and_write_lines(std::ifstream *input, std::ofstream *output);
};


#endif	// READS_MERGER_HPP

