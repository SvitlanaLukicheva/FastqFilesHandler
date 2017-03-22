#include <iostream>

#include "command_line_arguments.hpp"
#include "fastq_to_fasta_converter.hpp"
#include "reads_merger.hpp"

using namespace std;


int main(int argc, char* argv[])
{
    int result = 0;

    cout << "=== Welcome to reads merger!\n";
    CommandLineArguments* arguments = new CommandLineArguments();
    FastqToFastaConverter* converter;
    
    if(!arguments->Parse(argc, argv))
    {
        result = -1;
    }
    else
    {
        if(arguments->JobType == 0)   // reads merger
        {
            ReadsMerger* merger = new ReadsMerger(arguments->InputFiles, arguments->OutputFile);
            result = merger->MergeReads() ? 0 : -1;
            delete merger;
        }
        else if(arguments->JobType == 1)  // fastq to fasta converter
        {
            
        }
        else
        {
            cout << "=== FAILURE: Unknown job type (" << arguments->JobType << "\n";
            result = -1;
        }
    }
    
    delete arguments;

    cout << "=== Done\n";
    
    return result;
}
