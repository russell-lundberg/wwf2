#include <iostream>
#include <string>
#include <map>
#include "util.hpp"
#include <utility>

/*
 * this works to load the letters with their assigned values.
 * it uses an unordered_map as an associative array
 * 
 * It might be more sensible to use an ordered map. IDK.
 */

namespace WWF {

//unordered_map assign_letter_scores () {
std::map<char,int> LetterScores() {

//	std::map<std::string,int> LetterScore;
	std::map<char,int>LetterScore;

//    LetterScore.insert(std::make_pair("blank",0));
    LetterScore.emplace(std::pair<char,int>('a',1));
    LetterScore.emplace(std::pair<char,int>('b',4));
    LetterScore.emplace(std::pair<char,int>('c',4));
    LetterScore.emplace(std::pair<char,int>('d',2));
    LetterScore.emplace(std::pair<char,int>('e',1));
    LetterScore.emplace(std::pair<char,int>('f',4));
    LetterScore.emplace(std::pair<char,int>('g',3));
    LetterScore.emplace(std::pair<char,int>('h',3));
    LetterScore.emplace(std::pair<char,int>('i',1));
    LetterScore.emplace(std::pair<char,int>('j',10));
    LetterScore.emplace(std::pair<char,int>('k',5));
    LetterScore.emplace(std::pair<char,int>('l',2));
    LetterScore.emplace(std::pair<char,int>('m',4));
    LetterScore.emplace(std::pair<char,int>('n',2));
    LetterScore.emplace(std::pair<char,int>('o',1));
    LetterScore.emplace(std::pair<char,int>('p',4));
    LetterScore.emplace(std::pair<char,int>('q',10));
    LetterScore.emplace(std::pair<char,int>('r',1));
    LetterScore.emplace(std::pair<char,int>('s',1));
    LetterScore.emplace(std::pair<char,int>('t',1));
    LetterScore.emplace(std::pair<char,int>('u',2));
    LetterScore.emplace(std::pair<char,int>('v',5));
    LetterScore.emplace(std::pair<char,int>('w',4));
    LetterScore.emplace(std::pair<char,int>('x',8));
    LetterScore.emplace(std::pair<char,int>('y',3));
    LetterScore.emplace(std::pair<char,int>('z',10));

    /*
    for ( const auto& elem : LetterScore ) {
	    std::cout << "Tile: " << elem.first
		    << ", Value: " << elem.second
		    << "\n";
    }
    */

    return LetterScore;
} // end main()

} // close namespace declaration
/*
blank => { points => 0, count => 2    },
a => { points => 1, count => 9 },
b => { points => 4, count => 2 },
c => { points => 4, count => 2 },
d => { points => 2, count => 5 },
e => { points => 1, count => 13 },
f => { points => 4, count => 2 },
g => { points => 3, count => 3 },
h => { points => 3, count => 4 },
i => { points => 1, count => 8 },
j => { points => 10, count => 1 },
k => { points => 5, count => 1 },
l => { points => 2, count => 4 },
m => { points => 4, count => 2 },
n => { points => 2, count => 5 },
o => { points => 1, count => 8 },
p => { points => 4, count => 2 },
q => { points => 10, count => 1 },
r => { points => 1, count => 6 },
s => { points => 1, count => 5 },
t => { points => 1, count => 7 },
u => { points => 2, count => 4 },
v => { points => 5, count => 2 },
w => { points => 4, count => 2 },
x => { points => 8, count => 1 },
y => { points => 3, count => 2 },
z => { points => 10, count => 1 },
    );
*/
