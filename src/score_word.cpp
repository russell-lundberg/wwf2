#include "util.hpp"
#include <map>
#include <iostream>
#include <string>

// "word" consists of lower-case letters, unless a blank option was invoked.
std::map<std::string,int> WWF::Score_Word ( std::string word )
{
    // get the Letter scores
    std::map<char,int> LetterScore = WWF::LetterScores();

    // these vars constitute a map pair
    std::string scored_word = {};
    int Sum = 0;

    // loop though all the letters of the input. If upper case, value is zero,
    // so no need to add to the Sum
    for ( const char ch : word ) { 
        // Print current character 
        if ( isupper( ch )  ) {
            scored_word += std::tolower(ch, std::locale());
            // letter value derived from a blank is zero
        }
        else {
            Sum += LetterScore.at(ch);
            scored_word += ch;
        }
    }
    std::map<std::string,int> return_value = {};
    return_value.emplace(scored_word,Sum);
    return return_value;
}
