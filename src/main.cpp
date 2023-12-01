#include <iostream>
#include <string>
#include <fstream> // get_dictionary()
#include "create_permutations.hpp"
#include "util.hpp"


int main(int argc, char *argv[])
{
    std::vector<std::string> Permutations = WWF::ingest_args( argc, argv );

    // ingest_args() should return what to do, or possibly the boost struct
    // then process based upon that returned value. The next step on main() 
    // would be a dispatch function takine the return value of ingest_options()
    // as an input. That return value s/b an associative array

    /*
    std::string extension;
    // switch statement might be better. Also, 
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if ((arg == "-h") || (arg == "--help")) {
            WWF::show_usage(argv[i]);
        } else if ((arg == "-e") || (arg == "--extension")) {
            WWF::not_implemented(argv[i]);
        } else if ((arg == "-x") || (arg == "--regex")) {
            WWF::not_implemented(arg);
        } else if ((arg == "-b") || (arg == "--blank")) {
            WWF::not_implemented(arg);
        } else if ((arg == "-B") || (arg == "--blank2`")) {
            WWF::not_implemented(arg);
        } else if ((arg == "-d") || (arg == "--dictionary")) {
            // -d <regex> arg, to search dictionary for the inputted regex
            WWF::not_implemented(arg);
//            WWF::get_dictionary();
        } else if ((arg == "-l") || (arg == "--length")) {
            // -l 
            WWF::not_implemented(arg);
        } else {
//            sources.push_back(argv[i]);
        }
    }
    */

    std::set<std::string> Dictionary = WWF::get_dictionary();
    // define the candidates structure, for permutations found in the dictionary
    // because the permutations are already sorted, sorting is not
    // required here
    std::vector<std::string> valid_words;
    // let's reverse the sort by defining a map that sorts on descending
    // value

    for ( auto word : Permutations ) {
        if ( Dictionary.find(word) != Dictionary.end() ) {
            valid_words.push_back(word);
        }
    }

    for ( auto it = valid_words.rbegin(); it != valid_words.rend(); it++ ) {
        std::cout << *it << "\n";
    }

    /*
    for ( std::string word : valid_words ) {
        std::cout << word << "\n";
    }
    */
    std::cout << "there are " << valid_words.size() << " valid words.\n";

    return 0;
}
