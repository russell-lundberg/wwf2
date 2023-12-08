#include <iostream>
#include <string>
#include <fstream> // get_dictionary()
#include "create_permutations.hpp"
#include "util.hpp"
#include <map>
#include <utility>
#include <set>

/*
// Comparison function for sorting the
// set by increasing order of its pair's
// second value
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
 
// Function to sort the map according
// to value in a (key-value) pairs
void sort(std::map<std::string, int>& M)
{
 
    // Declare set of pairs and insert
    // pairs according to the comparator
    // function comp()
    std::set<std::pair<std::string, int>, comp> S(M.begin(), M.end());
 
    // Print the sorted value
    for (auto& it : S) {
        std::cout << it.first << ' ' << it.second << "\n";
    }
} // end sort()
*/



int main(int argc, char *argv[])
{
    std::vector<std::string> Permutations = WWF::ingest_args( argc, argv );

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

    /*
    for ( auto it = valid_words.rbegin(); it != valid_words.rend(); it++ ) {
        std::cout << *it << "\n";
    }

    for ( std::string word : valid_words ) {
        std::cout << word << "\n";
    }
    */
    std::cout << "there are " << valid_words.size() << " valid words.\n";

    return 0;
}
