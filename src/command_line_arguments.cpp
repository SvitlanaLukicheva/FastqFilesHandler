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
    
    if(argc <= 1)
    {
        cout << "=== FAILURE: invalid number of parameters provided: " << argc;
        result = false;
    }
    else
    {
        bool job_type_specified, input_specified, output_specified = false;
        
        for(int i =  0; i < argc; i++)
        {
            if(sizeof(argv[i])/sizeof(*argv[i]) == 2 /* size */ && argv[i][0] == '-')
            {
                switch(argv[i][1])
                {
                    case 'j':  // job type
                    {
                        i++;
                        char* job_type = argv[i];
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
                            ShowUsage();
                            result = false;
                        }
                        delete job_type;
                        break;
                    }
                    case 'o':  // output
                    {
                        i++;
                        OutputFile = argv[i];
                        output_specified = true;
                        break;
                    }
                    case 'i':  // input
                    {
                        i++;
                        list<char*>::iterator it;
                        while(i < argc && argv[i][0] != '-')
                        {
                            InputFiles.insert(it, argv[i]);
                            it++;
                            i++;
                        }
                        input_specified = true;
                        break;
                    }
                    default:
                    {
                        ShowUsage();
                        result = false;
                        break;
                    }
                }
            }
            else
            {
                ShowUsage();
                result = false;
            }
        }
        if(!job_type_specified || !input_specified || !output_specified)
        {
            cout << "=== FAILURE: mandatory arguments are missing \n";
            ShowUsage();
            result = false;
        }
    }
    
    return result;
}


void CommandLineArguments::ShowUsage()
{
    // TODO
    cout << "COUCOU\n";
}