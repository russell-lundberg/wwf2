#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <algorithm>
#include "words.hpp"

bool cmp(const std::string lhs, const std::string rhs) {
   return lhs.size() > rhs.size();
}

// int main ( int argc, char* argv[] ) {
int main ( ) {

    std::string letters = "abcdefg";
    
    // container for permutations
    // intermidiate storage of permutations in set
    std::set<std::string> perm_s;

    // final storage of permutations in set
    std::set<std::string> final_s;

    // the trailing "_s" indicates return type "set"
    perm_s = WWF::all_substrings_s( letters );

    std::cout << perm_s.size() << " substrings generated.\n";

    // loop through all substrings feeding each to 
    // all_permutations().
    std::set<std::string>::iterator itr;
    for ( itr = perm_s.begin(); itr != perm_s.end(); itr++  ) {
        std::vector<std::string> wordlist;
        wordlist = WWF::all_permutations( *itr );
        for ( auto elem : wordlist ) {
            if (elem.size() == 0 ) continue;
            final_s.insert(elem);
        }
    }
    std::cout << final_s.size() << " permutations generated.\n";

    // create a map for reporting statistics
    std::map<int, int> stats;

    // unsigned long int is the implicit type of "size_type".
    // needed here to silence a warning
    for ( unsigned long int i = 1 ; i <= letters.size() ; i++ ) {
        stats[i] = 0;
    }

    // iterate the set container into a vector "words"
    std::vector<std::string> words;
//    for ( auto elem : perm_s ) {
    for ( auto elem : final_s ) {
        if (elem.size() == 0 ) continue;
        words.push_back(elem);
    }
    // now sort the vector by stringlength
    std::sort(words.begin(),
              words.end(),
              cmp );

    // this loop prints the unique permutations by
    // descending length, and populates the stats hash
//    int i = 1;
    for ( auto elem : words) {
        // printf() wants a char type for strings. So 
        // elem must be converted using cstring library
//        char temp[ elem.size() +1];
//        strcpy(temp, elem.c_str());
//        std::printf("%2i: %s\n", i++, temp);
        stats[ elem.size() ] += 1;
    }

    std::cout << "\n";

    // print the stats container
    std::map<int,int>::iterator pos;
    int total = 0;
    for ( pos = stats.begin() ; pos != stats.end() ; pos++ ) {
       std::cout << pos->first << ": " << pos->second << "\n";
       total += pos->second;
    }
    std::cout << total << " permutations generated.\n";

}
