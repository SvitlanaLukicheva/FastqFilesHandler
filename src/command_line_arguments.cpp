#include <iostream>
#include "command_line_arguments.hpp"

using namespace std;


/**
 * Constructor
 */
CommandLineArguments::CommandLineArguments()
{
    JobType = -1;
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
    bool debug = false;
    
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
                if(parameter ==  "-j")  // job type
                {
                    i++;
                    string job_type = argv[i];
                    output_formatter.DisplayDebug("Job type is " + job_type);
                    if(job_type == "merger")
                    {
                        JobType = 0;
                    }
                    else if(job_type == "converter")
                    {
                        JobType = 1;
                    }
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
                    while(i < argc && argv[i][0] != '-')
                    {
                        string input_file = argv[i];
                        output_formatter.DisplayDebug("Adding input file " + input_file);
                        InputFiles.push_back(input_file);
                        i++;
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
    
    return result;
}


/**
 * Shows the usage of the program
 */
void CommandLineArguments::ShowUsage()
{
    // TODO
    cout << "\n";
    cout << "COUCOU\n";
}