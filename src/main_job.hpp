/* 
 * File:   main_job.hpp
 * Author: Svitlana
 *
 * Created on 11 septembre 2017, 18:09
 */

#ifndef MAIN_JOB_HPP
#define MAIN_JOB_HPP

#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include "output_formatter.hpp"


enum JobTypeEnum
{
    undefined,
    merger,
    converter,
    seq_remover
};


class MainJob
{
    public:
        bool virtual DoTheJob() = 0;
    
    protected:
        OutputFormatter output_formatter;
};


#endif /* MAIN_JOB_HPP */

