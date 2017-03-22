#ifndef READS_MERGER_HPP
#define READS_MERGER_HPP

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class ReadsMerger
{
    public:
        bool MergeReads(ifstream *input_1, ifstream *input_2, ofstream *output);

    private:
        bool read_and_write_lines(ifstream *input, ofstream *output);
};

#endif	// READS_MERGER_HPP

