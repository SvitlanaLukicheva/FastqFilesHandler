#ifndef READS_MERGER_HPP
#define READS_MERGER_HPP


#include <fstream>
#include <iostream>
#include <list>
#include <string>


class ReadsMerger
{
    public:
        ReadsMerger(std::list<std::string> input_files, std::string output_files);
        bool MergeReads();

    private:
        std::list<std::string> my_input_files;
        std::string my_output_file;
        
        bool merge_reads(std::ifstream *input_1, std::ifstream *input_2, std::ofstream *output);
        bool read_and_write_lines(std::ifstream *input, std::ofstream *output);
};


#endif	// READS_MERGER_HPP

