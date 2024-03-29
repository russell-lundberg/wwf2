/*
*  Permute.cpp
*  wwf2
*
*  Created by Russell Lundberg on 10/24/23.
* all functions are in the Permute:: namespace
*/


#include <set>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <vector>
#include "Permute.hpp"
#include "Util.hpp"
#include <map>
#include <unordered_map>
#include <cstring>


namespace Permute {

bool cmp(const std::string lhs, const std::string rhs) {
   return lhs.size() > rhs.size();
}


/*
* Permute::Create
*/
std::vector<std::string> Create( std::unordered_map<std::string,std::string> options )
{
//    std::cout << "create_Permutations(): starting.\n";

    if ( options.empty() ) {
        std::cout << "Permute::Create(): options arg was empty";
        exit(99);
    }

    /*
    for ( auto elem : options) {
        std::cout << "Permute::Create(): Option=" << elem.first << ". Value: " << elem.second << ".\n";
    }
    */

    std::string letters = "";
    
    if ( options.find("lettersIn") != options.end() ) {
        letters = options.at("lettersIn");
    }
    else {
        // for now, exit without any letters in. There may be future options
        // that will not require letters
        std::cout << "Create_Permutations(): no lettersIn: , exiting 98.\n";
        exit(98);
    }

    // std::string letters = options.at("lettersIn");

    // std::cout << "Create_Permutations(): lettersIn: " << letters << ".\n";

    // container for permutations
    // intermidiate storage of permutations in set
    std::set<std::string> perm_s;

    // final storage of permutations in set
    std::set<std::string> final_s;


    // std::cout << "Create_Permutations(): starting tests.\n";
    // the map values were type
    int blanks = 0;

    if ( options.find("blanks") != options.end() ) {

        // std::cout << "Found " << search->first << ' ' << search->second << '\n';

        if ( options.at("blanks") == "blank1" ) {
            blanks = 1;
            // std::cout << "main() blanks chk: " << blanks << "\n";
        }
        else if ( options.at("blanks") == "blank2") {


    // std::cout << "Create_Permutations(): tested blank1.\n";

        //if ( options.at("blanks") == "blank2") {
            blanks = 2;
            // std::cout << "main() blanks chk: " << blanks << "\n";
        }
        else {
            std::cout << "Permute::Create(): unexpected value for blanks: "
                << options.at("blanks") << ", exiting 97.\n";
            exit(97);
        }
    }

    // all uppercase to distinguish "blank" letter from letters having
    // non-zero value
    std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if ( blanks > 0 ) {
    
        for ( auto letter1 : alphabet ) {
            std::string tmp1 = letters + letter1;
            if ( blanks == 2 ) {
                for ( auto letter2 : alphabet ) {
                    std::string tmp2 = tmp1 + letter2;
                    std::set<std::string> this_time = Permute::all_substrings_s( tmp2 );
                    for ( auto elem : this_time ) {
                        perm_s.insert(elem);
                    }
                }
            }
            else {
                std::set<std::string> this_time = Permute::all_substrings_s( tmp1 );
                for ( auto elem : this_time ) {
                    perm_s.insert(elem);
                    // std::cout << "elem: " << elem << "\n";
                }
                // std::cout << "tmp1: " << tmp1 << "\n";
            }
        }
        // std::cout << j << " loops processed\n.";
    }
    else {
        perm_s = Permute::all_substrings_s( letters );
    }

    std::cout << perm_s.size() << " substrings generated.\n";

    // loop through all substrings, feeding each to all_permutations().
    std::set<std::string>::iterator itr;
    for ( itr = perm_s.begin(); itr != perm_s.end(); itr++  ) {
        std::vector<std::string> wordlist;
        wordlist = Permute::all_permutations( *itr );
        for ( auto elem : wordlist ) {
            if (elem.size() == 0 ) continue;
            final_s.insert(elem);
        }
    }

    // std::cout << final_s.size() << "Create_Permutations(): permutations generated.\n";

    // create a map for reporting statistics
    std::map<int, int> stats;

    // unsigned long int is the implicit type of "size_type".
    // needed here to silence a warning
    for ( int i = 1 ; i <= int( letters.size() ) ; i++ ) {
        stats[i] = 0;
    }

    // iterate the set container into a vector "words"
    std::vector<std::string> words;
    for ( auto elem : final_s ) {
        if (elem.size() == 0 ) continue;
        words.push_back(elem);
    }

    // now sort the vector by string length
    std::sort(words.begin(),
              words.end(),
              Permute::cmp );

    // this loop prints the unique permutations by
    // descending length, and populates the stats hash
    for ( auto elem : words) {
        // printf() wants a char type for strings. So
        // elem must be converted using cstring library
        stats[ int( elem.size() ) ] += 1;
    }

    // std::cout << "\n";

    // print the stats container
    std::map<int,int>::iterator pos;
    for ( pos = stats.begin() ; pos != stats.end() ; pos++ ) {
       std::cout << pos->first << ": " << pos->second << "\n";
    }

    return words;
} // end Permute::Create()


std::string permutation( std::string word, int perm_idx )
{
    // return nothing if the word arg was blank
    if ( word.size() == 0 ) return "";

    unsigned long int length = word.size() ;

    int fact = Util::factorial( int(length) );

    if ( perm_idx >=  fact || perm_idx < 0 )
        return "";

    fact = Util::factorial( int ( length - 1 ) );

    int current_idx = perm_idx / fact;

    int rest = perm_idx % fact;

    std::string first_letter = word.substr(current_idx, 1 );

    word = word.replace(current_idx, 1, "");

    std::string more_letters;
    more_letters =  Permute::permutation( word, rest);
    std::string many_letters = first_letter + more_letters;
    return many_letters;
}


std::vector<std::string> all_permutations( std::string letters )
{

    std::vector<std::string> permutations;

    int fact = 0;
    fact = Util::factorial( int ( letters.size() ) );

    for ( double i = 0 ; i <= fact ; i++ )
    {
        std::string temp;
        temp = Permute::permutation( letters, i );
        // print all permutations
        // std::cout << i << ": " << temp << "\n";
        permutations.push_back( temp );
    }
    return permutations;
}


std::set<std::string> all_substrings_s (std::string letters )
{
    std::set<std::string> subs_s;
    subs_s.insert(letters);

    // if empty string passed, return immediately
    if ( letters == "" ) {
        subs_s.insert("");
        return subs_s;
    }

    std::string before;

    // assign the first remaining char to current, then
    // delete that char from letters
    std::string current = letters.substr(0,1);

    while ( current.size() != 0 ) {
        std::set<std::string> this_loop;
        subs_s.insert(current);

        // can remove the char here or at end of loop
        letters.erase(0,1);

        this_loop = Permute::all_substrings_s( letters );
        for ( auto elem : this_loop ) {
            subs_s.insert( before + elem );
        }
        before += current;
        subs_s.insert(before);
        current = letters.substr( 0, 1 );
    }
    return subs_s;
}


} // close the namespace declaration
