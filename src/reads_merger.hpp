#ifndef READS_MERGER_HPP
#define READS_MERGER_HPP


#include "main_job.hpp"

using std::list;
using std::string;


class ReadsMerger : MainJob
{
    public:
        ReadsMerger(list<string> input_files, string output_files);
        bool DoTheJob();

    private:
        std::list<string>   my_input_files;
        string              my_output_file;
        
        bool merge_reads(ifstream *input_1, ifstream *input_2, ofstream *output);
};


#endif	// READS_MERGER_HPP

