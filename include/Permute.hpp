//
//  create_permutations.hpp
//  wwf4
//
//  Created by Russell Lundberg on 1/24/24.
//

#ifndef PERMUTE_HPP
#define PERMUTE_HPP

#include <vector>
#include <string>
#include <set>
#include <unordered_map>

namespace Permute

{

std::vector<std::string> Create( std::unordered_map<std::string,std::string> );
//std::vector<std::string> create_permutations( std::string, std::string );

std::string permutation( std::string letters, int perm_index );

std::vector<std::string> all_permutations( std::string letters );

std::set<std::string> all_substrings_s( std::string letters );

}


#endif /* PERMUTE_HPP */
