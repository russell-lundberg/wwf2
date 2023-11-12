#include <iostream>
#include <vector>
#include "words.hpp"
#include <boost/math/special_functions/factorials.hpp>

namespace WWF
{

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


} // close namespace declaration