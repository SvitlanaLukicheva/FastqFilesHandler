#include <iostream>
#include "reads_merger.hpp"
using namespace std;


int main(int argc, char* argv[])
{
	int result = 0;

	cout << "=== Welcome to reads merger!\n";

	if(argc % 2 != 0 || argc == 1)
	{
		cout << "=== FAILURE: Wrong number of parameters specified: " << argc << "\n";
		result = -1;
	}
	else
	{
        	ofstream output (argv[1]);
		if(output.is_open())
		{
			cout << "=== Output file: " << argv[1] << "\n";

			ReadsMerger* merger = new ReadsMerger();
			for(int i=2; i < argc - 1; i+=2)
			{
				cout << "=== Reading files " << argv[i] << " and " << argv[i+1] << "\n";
				ifstream input_1(argv[i]);
       	 			ifstream input_2(argv[i+1]);
				if(input_1.is_open() && input_2.is_open())
					merger->MergeReads(&input_1, &input_2, &output);
				else
				{
					cout << "=== FAILURE: Unable to open input files\n";
					result = -1;
					break;
				}
			}
			output.close();
			delete merger;
		}
		else
		{
			cout << "=== FAILURE: Unable to open the output file " << argv[1] << "\n";
			result = -1;
		}
	}

	cout << "=== Done\n";
	return result;
}
