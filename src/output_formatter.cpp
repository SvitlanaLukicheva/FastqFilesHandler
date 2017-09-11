#include "output_formatter.hpp"

using namespace std;


/**
 * Displays the provided string with info format
 * @param a_message
 * @return 
 */
void OutputFormatter::DisplayInfo(string a_message)
{
    cout << "=== INFO: " << a_message << "\n";
}


/**
 * Displays the provided string with warning format
 * @param a_message
 */
void OutputFormatter::DisplayWarning(string a_message)
{
    cout << "=== WARNING: " << a_message << "\n";
}


/**
 * Displays the provided string with error format
 * @param a_message
 */
void OutputFormatter::DisplayError(string a_message)
{
    cout << "=== FAILURE: " << a_message << "\n";
}


/**
 * Displays the provided string with debug format, if debug is enabled
 * @param a_message
 */
void OutputFormatter::DisplayDebug(string a_message)
{
    if(debug_is_enabled)
        cout << "=== DEBUG: " << a_message << "\n";
}