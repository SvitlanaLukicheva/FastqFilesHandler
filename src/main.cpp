#include "output_formatter.hpp"
#include "command_line_arguments.hpp"
#include "fastq_to_fasta_converter.hpp"
#include "reads_merger.hpp"
#include "seq_remover.hpp"


int main(int argc, char* argv[])
{
    bool result = true;
    OutputFormatter output_formatter;

    output_formatter.DisplayInfo("WELCOME TO FASTQ FILES CONVERTER!");
    CommandLineArguments* arguments = new CommandLineArguments();
    
    if(!arguments->Parse(argc, argv))
    {
        result = false;
    }
    else
    {
        if(arguments->JobType == merger)
        {
            ReadsMerger* merger = new ReadsMerger(arguments->InputFiles, arguments->OutputFile);
            result = merger->DoTheJob() ? 0 : -1;
            delete merger;
        }
        else if(arguments->JobType == converter)
        {
            if(arguments->InputFiles.size() != 1)
            {
                output_formatter.DisplayError("Invalid number of input files provided: " + arguments->InputFiles.size() + string(" instead of 1"));
                result = false;
            }
            else
            {
                FastqToFastaConverter* converter = new FastqToFastaConverter(*(arguments->InputFiles.begin()), arguments->OutputFile);
                converter->DoTheJob();
                delete converter;
            }
        }
        else if(arguments->JobType == seq_remover)
        {
            SeqRemover* seq_remover = new SeqRemover(arguments->InputFiles, arguments->OutputFile, arguments->SeqToRemove);
            seq_remover->DoTheJob();
            delete seq_remover;
        }
        else
        {
            output_formatter.DisplayError("Unknown job type (" + arguments->JobType);
            result = false;
        }
    }
    
    delete arguments;

    if(result == true)
        output_formatter.DisplayInfo("DONE");
    else
        output_formatter.DisplayError("EXECUTION ABORTED");
    
    return result == true ? 0 : -1;
}
