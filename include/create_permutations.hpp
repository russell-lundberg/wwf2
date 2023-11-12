#ifndef CREATE_PERMUTATIONS
#define CREATE_PERMUTATIONS

#include <vector>
#include <string>
#include <set>

namespace WWF 

{

//std::vector<std::string> create_permutations( std::string letters );
std::vector<std::string> create_permutations( std::string, int );

std::string permutation( std::string letters, int perm_index );

std::vector<std::string> all_permutations( std::string letters );

std::set<std::string> all_substrings_s( std::string letters );

//std::vector<std::string> all_subpermutations( std::string letters );

}

#endif