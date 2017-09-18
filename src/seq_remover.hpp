/* 
 * File:   seq_remover.hpp
 * Author: Svitlana
 *
 * Created on 18 septembre 2017, 18:31
 */

#ifndef SEQ_REMOVER_HPP
#define SEQ_REMOVER_HPP


#include "main_job.hpp"

using std::ifstream;
using std::ofstream;
using std::list;
using std::string;


class SeqRemover : MainJob
{
    public:
        SeqRemover(list<string> input_files, string output_folder, string sequence_to_remove);
        bool DoTheJob();
};


#endif /* SEQ_REMOVER_HPP */

