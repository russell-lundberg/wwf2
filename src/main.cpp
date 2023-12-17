#include <iostream>
#include <string>
#include <fstream> // get_dictionary()
#include "create_permutations.hpp"
#include "util.hpp"
#include <map>
#include <unordered_map>
#include <utility>
#include <set>


int main(int argc, char *argv[])
{

    std::unordered_map<std::string,std::string> Options = {};
    
    // ingest_args() returns an unordered map of command line args and values
    Options = WWF::ingest_args( argc, argv );
//    for ( auto elem : Options) {
//        std::cout << "Element name: " << elem.first << ". Value=" << elem.second << "\n";
//    }

/*
    // the map values were type
    int blanks = 0;
    if ( Options.at("blanks") == "blank1") {
        blanks = 1;
        std::cout << "main() blanks chk: " << blanks << "\n";
    }
    if ( Options.at("blanks") == "blank2") {
        blanks = 2;
        std::cout << "main() blanks chk: " << blanks << "\n";
    }
*/


   std::vector<std::string> Permutations;
//   Permutations = WWF::create_permutations( Options["lettersIn"], Options["blanks"] );
    Permutations = WWF::create_permutations( Options );

    // ingest_args() should return what to do, or possibly the boost struct
    // then process based upon that returned value. The next step on main() 
    // would be a dispatch function takine the return value of ingest_options()
    // as an input. That return value s/b an associative array

    std::set<std::string> Dictionary = WWF::get_dictionary();

    // define the candidates structure, for permutations found in the dictionary
    // because the permutations are already sorted, sorting is not
    // required here. But the permutations must first be lower-cased to match 
    // in the dictionary
    // need to score words before searcing dictionary, so that the highest scored
    // word is selected.
    std::vector<std::string> valid_words;

    // let's reverse the sort by defining a map that sorts on descending
    // value
    for ( auto word : Permutations ) {
        // must find the word in lower case
        std::string word_lower = {};
        for ( const char ch : word ) { 
            word_lower += std::tolower(ch, std::locale());
        }
        if ( Dictionary.find(word_lower) != Dictionary.end() ) {
            valid_words.push_back(word);
        }
    }

    // score all the dictionary words in a map container
    std::map<std::string,int> Scored_Words;
    for ( auto elem : valid_words ) {
        std::map<std::string,int> Scored_Word = WWF::Score_Word( elem );
        Scored_Words.insert( Scored_Word.begin(), Scored_Word.end() );
    }

    // sort the scored words by ascending score
    WWF::sort( Scored_Words );

    std::cout << "there are " << valid_words.size() << " valid words.\n";

    std::cout << "You entered: ";
    for ( int i = 0 ; i<= argc ; i++ ) {
        std::cout << argv[i] << " ";
    }
    std::cout << "\nEnd.\n";

    return 0;
}
