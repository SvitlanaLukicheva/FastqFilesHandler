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
        
        
    private:
        list<string>    my_input_files;
        string          my_output_folder;
        string          my_sequence_to_remove;
        int             sequences_removed;
        
        bool remove_sequence_from_files(ifstream *input_1, ifstream *input_2, ofstream *output_1, ofstream *output_2);
};


#endif /* SEQ_REMOVER_HPP */

