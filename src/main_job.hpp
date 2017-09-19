/* 
 * File:   main_job.hpp
 * Author: Svitlana
 *
 * Created on 11 septembre 2017, 18:09
 */

#ifndef MAIN_JOB_HPP
#define MAIN_JOB_HPP

#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include "output_formatter.hpp"

using std::ifstream;
using std::ofstream;


enum JobTypeEnum
{
    undefined,
    merger,
    converter,
    seq_remover
};


class MainJob
{
    public:
        bool virtual DoTheJob() = 0;
    
    protected:
        OutputFormatter output_formatter;
        
        bool write_lines (string line_1, string line_2, string line_3, string line_4, ofstream *output);
        bool read_and_write_lines (ifstream *input, ofstream *output);
};


#endif /* MAIN_JOB_HPP */

