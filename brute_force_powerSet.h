/*
Author: Jonathan Drouillard
Assignment Title: Common Brute Force Algorithms
Assignment Description: An implementation of the brute force algorithms for
    string matching, closest pair, powerset, and permutations.
Due Date: 2/3/12
Date Created: 2/3/12
Date Last Modified: 3/9/12
*/
#include <set>
using namespace std;


/*
PowerSet
    I will use the decrease-by-one version of Gray coding to implement
    the algorithm using a characer array instead of bit strings.
    I will start by placing all characters in the set into a character array.
    I start at the (n-n-1)th position and create a set with no characters to
    represent the empty set.
    At the n-(n-1) position iteration, I will have one character and append it
    to the empty set.  This set will be appended to the power set.
    At the n-(n-2) position iteration, I will create a new set and append the
    current character to a copy of each set of the previous iteration.
    This set will be appended to the power set.
    At the n-(n-3) position iteration, I will create a new set and append the
    current character to a copy of each set of the previous iteration.
    This set will be appended to the power set.
    I will repeat this process until I have traversed through every character
    position in my character array.
*/

//************************************************************
// description: Generate the powerset when given a set of    *
//              characters.                                  *
// return: set<set<char> >                                   *
// pre: Size of S >= 0.                                      *
// post: returns a set of sets of characters, one set for    *
//       each member of the power set.                       *
//                                                           *
//************************************************************
set<set<char> > brute_force_powerSet(set<char> S) {
    /*Variable Declaration*/
    //Stores the power set we will return.
    set<set<char> > pSet;
    //n stores the amount of elements in the set S.
    int n = S.size();
    //i is an iteration variable.
    int i = 0;
    //Create a character array of the size of the set
    char *c = new char[n];
    //Iterators for looping through the power set and the passed in set.
    set<char>::iterator iter;
    set<set<char> >::iterator iter2;
    
    //Loop through the passed in set of characters
    //For each iteration, store the current character in our
    //character array.  Increment i and the iterator through each loop.
    for(iter = S.begin(); iter != S.end(); iter++, i++) {
        c[i] = *iter;
    }

    //Begin at -1, which represents the empty set.
    //Otherwise, loop until we have reached n.
    //In each iteration, after the empty set,
    //build sets based off the previously store sets
    //by copying the previous sets and appending the current character.
    for(i = -1; i < n; i++) {
        //Somewhat of a base case.
        //Insert the empty set into the power set.
        if(i == -1) {
            set<char> temp;
            pSet.insert(temp);
        } else { //Otherwise,
            //Loop through the current power set.
            for(iter2 = pSet.begin(); iter2 != pSet.end(); iter2++) {
                //Through each iteration of the power set,
                //store the current sub set into a set.
                //Then, append the current character to these subsets.
                set<char> subset;
                //Make a set based off the current subset of the power set.
                for(iter = (*iter2).begin(); iter != (*iter2).end(); iter++) {
                    subset.insert(*iter);
                }
                //Append the current character to this subset.
                subset.insert(c[i]);
                //Insert this into the power set.
                pSet.insert(subset);
                //Repeat until we have reached the end of the power set.
            }
        }
    }
    //Clean up our memory.
    delete c;
    return pSet;
}
