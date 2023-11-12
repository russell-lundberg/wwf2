#include <iostream>
#include <vector>
#include <boost/math/special_functions/factorials.hpp>
#include "words.hpp"

namespace WWF
{

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

} // close the namespace declaration