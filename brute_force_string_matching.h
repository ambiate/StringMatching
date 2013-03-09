/*
Author: Jonathan Drouillard
Assignment Title: Common Brute Force Algorithms
Assignment Description: An implementation of the brute force algorithms for
    string matching, closest pair, powerset, and permutations.
Due Date: 2/3/12
Date Created: 2/3/12
Date Last Modified: 3/7/13
*/
#include <cstring>

/*
String Matching
    It is very simple to brute force string match.
    If you have an two character arrays, you can compare them by shifting
    the character array to be searched to the left each iteration.
    I shift the top array (the text to be searched) to the left,
    and never touch the bottom array (the pattern).
          [0][1][2][3]
          [0][1]
       [0][1][2][3]
          [0][1]
    [0][1][2][3]
          [0][1]
    I can use a pointer pointing to the text to be searched and increment it
    each iteration to obtain this behavior.
    I can use the strncmp function to check if the current position in the
    text to be searched to the length of the pattern to be matched matches the
    pattern I am searching for!
*/

//************************************************************
// description: Brute force search s1 for pattern s2.        *
// return: char*                                             *
// pre: N/A, -- base cases handle nonsense.                  *
// post: returns char* to the location of the match in s1    *
//       where the first occurence of s2 was found or        *
//       NULL if no match was found                          *
//                                                           *
//************************************************************
char * BF_string_matching(char * s1, char * s2) {
    //Since we do not have prerequisites, we need base cases
    //to check that we have valid data.
    //Make sure s1 is not null.
    //Make sure s1 is not 0 length string.
    if(s1 == NULL || s1[0] == '\0') {
            return NULL;
    }

    //Used to store a pointer where the match was found.
    char *s3 = s1;
    //Loop through the string to be searched up to the point
    //where it would be useless to attempt to match.
    for(size_t i = 0; i < strlen(s1)-strlen(s2)+1; i++) {
        //Check if we have a match
        if(strncmp(s3,s2,strlen(s2)) == 0) {
            //If there was a match, return the pointer to the match.
            return s3;
        } else { //Otherwise, increment the pointer.
            //'Shift' the text to be searched to the 'left.'
            s3++;
        }
    }
    //Not found!
    return NULL;
}