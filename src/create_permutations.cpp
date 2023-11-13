#include <iostream>
#include <set>
#include <algorithm>
#include <iostream>
#include <vector>
#include <boost/math/special_functions/factorials.hpp>
#include "create_permutations.hpp"
#include <map>
#include <cstring>


bool cmp(const std::string lhs, const std::string rhs) {
   return lhs.size() > rhs.size();
}


namespace WWF {

//std::vector<std::string> create_permutations( std::string letters )
std::vector<std::string> create_permutations( std::string letters, int blanks )
{
//    std::string letters = "abcdefg";
    
    // container for permutations
    // intermidiate storage of permutations in set
    std::set<std::string> perm_s;

    // final storage of permutations in set
    std::set<std::string> final_s;

    // the trailing "_s" indicates return type "set"
//    perm_s = WWF::all_substrings_s( letters );

    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    if ( blanks > 0 ) {
    
        int j = 0;
        for ( auto letter1 : alphabet ) {
            std::string tmp1 = letters + letter1;
            if ( blanks == 2 ) {
                for ( auto letter2 : alphabet ) {
                    std::string tmp2 = tmp1 + letter2;
                    std::set<std::string> this_time = WWF::all_substrings_s( tmp2 );
                    for ( auto elem : this_time ) {
                        perm_s.insert(elem);
                    }
//                    std::cout << "tmp1.tmp2: " << tmp1 << "." << tmp2 << "\n";
                    j++;
                }
            }
            else {
                std::set<std::string> this_time = WWF::all_substrings_s( tmp1 );
                for ( auto elem : this_time ) {
                    perm_s.insert(elem);
                }
//                std::cout << "tmp1: " << tmp1 << "\n";
                    j++;
            }
        }
        std::cout << j << " loops processed\n.";
    }
    else {
                perm_s = WWF::all_substrings_s( letters );
    }



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
    // now sort the vector by string length
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

    return words;
}


std::string permutation( std::string word, int perm_idx )
{
    // return nothing if the word arg was blank
    if ( word.size() == 0 ) return "";

    unsigned long int length = word.size() ;

    double factored = boost::math::factorial<double>( length );
    if ( perm_idx >= (int) factored || perm_idx < 0 )
    {
//        std::cout << "permutations::invalid perm_index: " << perm_idx << "\n";
        return "";
    }

    factored = boost::math::factorial<double>( length - 1 );

    int current_idx = perm_idx / ( int)factored;

    int rest = perm_idx % (int)factored;

    std::string first_letter = word.substr(current_idx, 1 );

    word = word.replace(current_idx, 1, "");
//    word = word.erase( current_idx );

    std::string more_letters;
    more_letters =  WWF::permutation( word, rest);
    std::string many_letters = first_letter + more_letters;
    return many_letters;
}


std::vector<std::string> all_permutations( std::string letters ) 
{

    std::vector<std::string> permutations;

    double fact = boost::math::factorial<double>( letters.size() );

    for ( double i = 0 ; i <= fact ; i++ )
    {
        std::string temp;
        temp = WWF::permutation( letters, i );
        // print all permutations
//        std::cout << i << ": " << temp << "\n";
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

        this_loop = WWF::all_substrings_s( letters );
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