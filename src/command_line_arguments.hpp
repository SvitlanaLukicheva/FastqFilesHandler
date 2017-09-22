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
    // general settings
    JobTypeEnum     JobType;        // specifies the job to execute
    list<string>    InputFiles;     // specifies the input files to handle
    string          OutputFile;     // specifies the output file or folder, depending on job
    
    // seq_remover related
    list<string>    SeqToRemove;    // specifies one or several sequences to remove
    int             BeginIndex;     // specifies the index from which the search for patterns starts on the reads
    int             EndIndex;       // specifies the index until which the search for patterns is done
 
    CommandLineArguments();
    
    bool Parse(int argc, char* argv[]);
    void ShowUsage();
    
private:
    OutputFormatter output_formatter;  // used to format the output
};


#endif /* COMMAND_LINE_ARGUMENTS_HPP */

