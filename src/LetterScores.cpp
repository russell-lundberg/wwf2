#include <iostream>
#include <string>
#include <map>
#include "util.hpp"

/*
 * this works to load the letters with their assigned values.
 * it uses an unordered_map as an associative array
 * 
 * It might be more sensible to use an ordered map. IDK.
 */

//unordered_map assign_letter_scores () {
std::map<std::string,int> WWF::LetterScores() {

	std::map<std::string,int> LetterScore;

    LetterScore.insert(std::make_pair("blank",0));
    LetterScore.insert(std::make_pair("a",1));
    LetterScore.insert(std::make_pair("b",4));
    LetterScore.insert(std::make_pair("c",4));
    LetterScore.insert(std::make_pair("d",2));
    LetterScore.insert(std::make_pair("e",1));
    LetterScore.insert(std::make_pair("f",4));
    LetterScore.insert(std::make_pair("g",3));
    LetterScore.insert(std::make_pair("h",3));
    LetterScore.insert(std::make_pair("i",1));
    LetterScore.insert(std::make_pair("j",10));
    LetterScore.insert(std::make_pair("k",5));
    LetterScore.insert(std::make_pair("l",2));
    LetterScore.insert(std::make_pair("m",4));
    LetterScore.insert(std::make_pair("n",2));
    LetterScore.insert(std::make_pair("o",1));
    LetterScore.insert(std::make_pair("p",4));
    LetterScore.insert(std::make_pair("q",10));
    LetterScore.insert(std::make_pair("r",1));
    LetterScore.insert(std::make_pair("s",1));
    LetterScore.insert(std::make_pair("t",1));
    LetterScore.insert(std::make_pair("u",2));
    LetterScore.insert(std::make_pair("v",5));
    LetterScore.insert(std::make_pair("w",4));
    LetterScore.insert(std::make_pair("x",8));
    LetterScore.insert(std::make_pair("y",3));
    LetterScore.insert(std::make_pair("z",10));

    for ( const auto& elem : LetterScore ) {
	    std::cout << "Tile: " << elem.first
		    << ", Value: " << elem.second
		    << "\n";
    }

    return LetterScore;
} // end main()

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
