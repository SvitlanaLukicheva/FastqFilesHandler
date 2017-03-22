#include <iostream>
#include "command_line_arguments.hpp"

using namespace std;


CommandLineArguments::CommandLineArguments()
{
    JobType = -1;
}


bool CommandLineArguments::Parse(int argc, char* argv[])
{
    bool result = true;
    bool debug = false;
    
    if(argc <= 1)
    {
        cout << "=== FAILURE: invalid number of parameters provided: " << argc;
        result = false;
    }
    else
    {
        bool job_type_specified, input_specified, output_specified = false;
        
        for(int i = 1; i < argc; i++)
        {
            if(debug)
            {
                cout << "=== DEBUG: reading parameter " << argv[i] << "\n";
            }
            if(argv[i][0] == '-')
            {
                string parameter = argv[i];
                if(parameter ==  "-j")  // job type
                {
                    i++;
                    string job_type = argv[i];
                    if(debug)
                        cout << "=== DEBUG: job type is " << job_type << "\n";
                    if(job_type == "merger")
                    {
                        JobType = 0;
                        job_type_specified = true;
                    }
                    else if(job_type == "converter")
                    {
                        JobType = 1;
                        job_type_specified = true;
                    }
                    else
                    {
                        cout << "=== FAILURE: invalid job type specified: " << job_type << "\n";
                        result = false;
                    }
                }
                else if(parameter == "-o")  // output
                {
                    i++;
                    OutputFile = argv[i];
                    output_specified = true;
                }
                else if(parameter == "-i")  // input
                {
                    i++;
                    while(i < argc && argv[i][0] != '-')
                    {
                        string input_file = argv[i];
                        if(debug)
                            cout << "=== DEBUG: adding input file " << input_file << "\n";
                        InputFiles.push_back(input_file);
                        i++;
                    }
                    input_specified = true;
                }
                else
                {
                    cout << "=== FAILURE: unknown parameter " << parameter << "\n";
                    result = false;
                    break;
                }
            }
            else
            {
                cout << "=== FAILURE: invalid usage of program arguments at " << argv[i] << "\n";
                result = false;
            }
        }
        if(!job_type_specified || !input_specified || !output_specified)
        {
            cout << "=== FAILURE: mandatory arguments are missing \n";
            result = false;
        }
    }
    
    if(result == false)
        ShowUsage();
    
    return result;
}


void CommandLineArguments::ShowUsage()
{
    // TODO
    cout << "COUCOU\n";
}