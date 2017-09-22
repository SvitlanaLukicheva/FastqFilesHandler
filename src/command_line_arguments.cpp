#include <iostream>
#include "command_line_arguments.hpp"

using namespace std;


/**
 * Constructor
 */
CommandLineArguments::CommandLineArguments()
{
    JobType = undefined;
}


/**
 * Command line parser
 * @param argc
 * @param argv
 * @return 
 */
bool CommandLineArguments::Parse(int argc, char* argv[])
{
    bool result = true;
    
    if(argc <= 1)
    {
        output_formatter.DisplayError("Invalid number of parameters provided: " + argc);
        result = false;
    }
    else
    {        
        for(int i = 1; i < argc; i++)
        {
            output_formatter.DisplayDebug("Reading parameter " + string(argv[i]));
            if(argv[i][0] == '-')
            {
                string parameter = argv[i];
                if(parameter ==  "-x")  // job type
                {
                    i++;
                    string job_type = argv[i];
                    output_formatter.DisplayDebug("Job type is " + job_type);
                    if(job_type == "merger")
                        JobType = merger;
                    else if(job_type == "converter")
                        JobType = converter;
                    else if(job_type == "seq_remover")
                        JobType = seq_remover;
                    else
                    {
                        output_formatter.DisplayError("Invalid job type specified: " + job_type);
                        result = false;
                    }
                }
                else if(parameter == "-o")  // output
                {
                    i++;
                    OutputFile = argv[i];
                }
                else if(parameter == "-i")  // input
                {
                    i++;
                    while(i < argc)
                    {
                        if(argv[i][0] == '-')  // new parameter
                        {
                            i--;
                            break;
                        }
                        else
                        {
                            string input_file = argv[i];
                            output_formatter.DisplayDebug("Adding input file " + input_file);
                            InputFiles.push_back(input_file);
                            i++;
                        }
                    }
                }
                else if(parameter == "-s")  // sequence to remove for seq_remover
                {
                    i++;
                    while(i < argc)
                    {
                        if(argv[i][0] == '-')  // new parameter
                        {
                            i--;
                            break;
                        }
                        else
                        {
                            string seq_to_remove = argv[i];
                            output_formatter.DisplayDebug("Adding sequence to remove " + seq_to_remove);
                            SeqToRemove.push_back(seq_to_remove);
                            i++;
                        }
                    }
                }
                else
                {
                    output_formatter.DisplayError("Unknown parameter " + parameter);
                    result = false;
                    break;
                }
            }
            else
            {
                output_formatter.DisplayError("Invalid usage of program arguments at " + string(argv[i]));
                result = false;
            }
        }
        if(JobType == -1 || InputFiles.empty() || OutputFile.empty())
        {
            output_formatter.DisplayError("Mandatory arguments are missing!!");
            result = false;
        }
    }
    
    if(result == false)
        ShowUsage();
    else
        output_formatter.DisplayDebug("Program parameters successfully read");
    
    return result;
}


/**
 * Shows the usage of the program
 */
void CommandLineArguments::ShowUsage()
{
    // TODO
    cout << "COUCOU\n";
}