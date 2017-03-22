/* 
 * File:   command_line_arguments.hpp
 * Author: Svitlana
 *
 * Created on 22 mars 2017, 17:49
 */

#ifndef COMMAND_LINE_ARGUMENTS_HPP
#define COMMAND_LINE_ARGUMENTS_HPP


#include <iostream>
#include <list>


enum JobType
{
    ReadsMerger,
    FastqToFastaConverter,
    Invalid
};

class CommandLineArguments
{    
public:
    JobType MyJobType;
    std::list<char*> InputFiles;
    char* OutputFile;
    
    CommandLineArguments();
    
    bool Parse(int argc, char* argv[]);
    void ShowUsage();
};


#endif /* COMMAND_LINE_ARGUMENTS_HPP */

