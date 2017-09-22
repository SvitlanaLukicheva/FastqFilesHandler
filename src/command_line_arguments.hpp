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
#include "main_job.hpp"
#include "output_formatter.hpp"

using std::list;
using std::string;


class CommandLineArguments
{    
public:
    JobTypeEnum     JobType;
    list<string>    InputFiles;
    string          OutputFile;
    
    list<string>    SeqToRemove;
 
    CommandLineArguments();
    
    bool Parse(int argc, char* argv[]);
    void ShowUsage();
    
private:
    OutputFormatter output_formatter;  // used to format the output
};


#endif /* COMMAND_LINE_ARGUMENTS_HPP */

