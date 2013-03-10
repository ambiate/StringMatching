/*
Author: Jonathan Drouillard
Assignment Title: Common Brute Force Algorithms
Assignment Description: An implementation of the brute force algorithms for
    string matching, closest pair, powerset, and permutations.
Due Date: 2/3/12
Date Created: 2/3/12
Date Last Modified: 3/9/12
*/
#include <algorithm>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;

/*
Permutation
    I will utilize the next_permutation function in the algorithms header
    to accomplish finding all permutations of a set of characters.
    My first goal is to get the set of characters into a container that
    the next_permutation function can handle.  I will utilize a vector to
    store all of the characters in the set.
    Once I have all of the characters into a vector, I will ensure the
    characters are alphabetically sorted.
    I call the next permutation function on my vector and allow it to
    generate the next permutation (which is based on the < operator (and the
    reason we sort the array)).
    Through each iteration of next permutation, I will build a string to
    push into a set of strings.  This set of strings will be returned by the
    function after the next_permutation function returns false, which indicates
    that there are no more permutations because it has reached the highest
    permutation for that set of characters.
*/

//************************************************************
// description: Generate the permutations for a set of       *
//              characters.                                  *
// return: set<string>                                       *
// pre: Size of S >= 0.                                      *
// post: returns a set of strings, one string for each       *
//       permutation                                         *
//                                                           *
//************************************************************
set<string> brute_force_string_permutation(set<char> S) {
    /*Variable Declaration*/
    //A place to store the output.
    set<string> output;
    //A place to store each of the characters in the set.
    vector<char> chars; //Also allows usage of next_permutation
    //Used to iterate through the set of characters.
    set<char>::iterator iter;
    
    //Check if the parameter is empty, if so, return the empty set.
    if(S.empty())
        return output;

    //Iterate through the set of characters,
    //and place each character into our chars vector.
    for(iter = S.begin(); iter != S.end(); iter++)
        chars.push_back(*iter);

    //Sort the vector to begin working on permutations
    //in ascending order.
    sort(chars.begin(), chars.end());

    do {
        //Used to iterate through the vector
        vector<char>::iterator iter2;
        //Used to store the current permutation
        string perm = "";
        //Iterate through the vector.
        //For each iteration, I hit a letter of the current
        //permutation and store it in the permutation string.
        for(iter2 = chars.begin(); iter2 != chars.end(); iter2++) {
            perm += *iter2;
        }
        //Place this permutation in our output set.
        output.insert(perm);
    } while(next_permutation(chars.begin(), chars.end())); //Generate next perm.
    return output;
}
