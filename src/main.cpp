#include "output_formatter.hpp"
#include "command_line_arguments.hpp"
#include "fastq_to_fasta_converter.hpp"
#include "reads_merger.hpp"


int main(int argc, char* argv[])
{
    int result = 0;
    OutputFormatter output_formatter;

    output_formatter.DisplayInfo("WELCOME TO FASTQ FILES CONVERTER!");
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
            result = merger->DoTheJob() ? 0 : -1;
            delete merger;
        }
        else if(arguments->JobType == 1)  // fastq to fasta converter
        {
            if(arguments->InputFiles.size() != 1)
            {
                output_formatter.DisplayError("Invalid number of input files provided: " + arguments->InputFiles.size() + string(" instead of 1"));
                result = -1;
            }
            else
            {
                FastqToFastaConverter* converter = new FastqToFastaConverter(*(arguments->InputFiles.begin()), arguments->OutputFile);
                converter->DoTheJob();
                delete converter;
            }
        }
        else
        {
            output_formatter.DisplayError("Unknown job type (" + arguments->JobType);
            result = -1;
        }
    }
    
    delete arguments;

    output_formatter.DisplayInfo("DONE");
    
    return result;
}
