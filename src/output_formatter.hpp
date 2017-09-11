/* 
 * File:   output_formatter.hpp
 * Author: Svitlana
 *
 * Created on 11 septembre 2017, 16:25
 */

#ifndef OUTPUT_FORMATTER_HPP
#define OUTPUT_FORMATTER_HPP

#include <iostream>
#include <string>

using std::string;


class OutputFormatter
{
public:
    static void DisplayInfo(string a_message);
    static void DisplayWarning(string a_message);
    static void DisplayError(string a_message);
    static void DisplayDebug(string a_message);
    
private:
    static const bool debug_is_enabled = true;
};

#endif /* OUTPUT_FORMATTER_HPP */

