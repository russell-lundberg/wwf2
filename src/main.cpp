//
//  main.cpp
//  wwf4
//
//  Created by Russell Lundberg on 1/24/24.
//

#include <iostream>
#include <string>
#include <fstream> // get_dictionary()
#include "create_permutations.hpp"
#include "util.hpp"
#include <map>
#include <unordered_map>
#include <utility>
#include <set>
#include "options.hpp"
#include <chrono>
// dictionary testing
#include <filesystem>
namespace fs = std::filesystem;



// comparison function to sort the valid words by score
/*
struct comp {
    template <typename T>
 
    // Comparator function
    bool operator()(const T& l, const T& r) const
    {
        if (l.second != r.second) {
            return l.second < r.second;
        }
        return l.first < r.first;
    }
};
*/
auto start = std::chrono::high_resolution_clock::now();


int main(int argc, char *argv[])
//int main(int argc, std::string* argv)
{

    std::unordered_map<std::string,std::string> Options = {};
    
    // dictionary testing
    const fs::path home(".");
    std::cout << "directory_iterator:\n";
    for ( auto const& dir_entry : fs::directory_iterator{home})
        std::cout << dir_entry.path() << "\n";

    
    // ingest_args() returns an unordered map of command line args and values
    Options = Options::process_argv( argc, argv );

    // std::cout << "Ingested arguments.\n";
    
    /*
    for ( auto elem : Options) {
        std::cout << "main() Options: " << elem.first << ". Value: " << elem.second << ".\n";
    }
    */

    std::vector<std::string> Permutations;
    Permutations = WWF::create_permutations( Options );
    
    //    std::cout << "created permutations.\n";

    // return the dictionary file as a SET container
    std::set<std::string> Dictionary = Util::get_dictionary();


//    std::cout << "Loaded dictionary.\n";

    // valid words are permutations found in the dictionary. Because permutations
    // are already sorted, sorting is not required here. But the permutations must
    // first be lower-cased to match words in the dictionary
    std::vector<std::string> valid_words;

    // Lower-casing the input and scoring each letter might best be done at the
    // same time, as they both require char-by-char processing.
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

//    std::cout << "Got permutations.\n";

    // score all the dictionary words in a map container
    std::map<std::string,int> Scored_Words;
    for ( auto elem : valid_words ) {
        std::map<std::string,int> Scored_Word = WWF::Score_Word( elem );
        Scored_Words.insert( Scored_Word.begin(), Scored_Word.end() );
    }

//    std::cout << "Scored words.\n";

    // sort the scored words by ascending score
    std::set<std::pair<std::string,int>> sorted_words;
    sorted_words = WWF::Words_Sorted( Scored_Words, Options );
    
    std::cout << "there are " << valid_words.size() << " valid words.\n";

/*
    // display the inputted command line, for reference
    std::cout << "You entered: ";
    for ( int i = 0 ; i<= argc ; i++ ) {
        std::cout << argv[i] << " ";
    }
    std::cout << "\nEnd.\n";
*/

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    float formatted = float( elapsed.count() ) / 1000.0;
    std::printf("Elapsed time: %2.3f\n", formatted );

    return 0;
}

