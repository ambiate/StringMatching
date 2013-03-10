/*
Author: Jonathan Drouillard
Assignment Title: Common Brute Force Algorithms
Assignment Description: An implementation of the brute force algorithms for
    string matching, closest pair, powerset, and permutations.
Due Date: 2/3/12
Date Created: 2/3/12
Date Last Modified: 3/7/12
*/
#include <cmath>
#include <utility>
using namespace std;

/*
Closest Pair
    I will take an input of an array of pairs and a size.
    I can traverse the array and use a brute force method to compare each
    element to every other element in the array.
    By traversing every element in the array with every other element in the
    array, I ensure that I have checked every possibility for the closest pair.
    To calculate the distance between two points, I will use the Pythagorean
    distance formula.
    I will leave in the squareroot function to calculate the distance between
    two points, for the sake of clarity.  The sqrt function could be left out,
    and I would be left with the asymptotically same, yet faster, algorithm.
    I will set the closest pair on the first run to be the distance of the
    first two pairs.
*/

//************************************************************
// description: Brute force search for closest pair in an    *
//              array of points.                             *
// return: pair<int index1, int index2>                      *
// pre: size>=2.                                             *
// post: returns indices index1 and index2 in a pair to      *
//       signify the location of the closest pair of points  *
//       in the pair array.                                  *
//                                                           *
//************************************************************
pair<int,int> BF_closest_pair( pair<double,double> a[ ] , int size) {
    /*Variable Declaration*/
    //Stores the indices we will return.
    pair<int, int> closest;
    //Used to indicate this is the initial run -- we need to set delta.
    bool firstRun = true;
    //Stores the current calculated minimum distance for the current iteration.
    double current;
    //Stores the calculated minimum distance.
    double delta;
    //Loop through the array of points.
    for(int i = 0; i <= size-1; i++) {
        //By setting j to i+1, we will never compare i to itself.
        //Go through each point brute force.
        for(int j = i+1; j <= size; j++) {
                //If this is the current run, then delta is unset.
                //Assume that the first two points is the minimum distance.
                if(firstRun) {
                    //Distance formula
                    delta = sqrt(pow((a[i].first - a[j].first), 2) + pow((a[i].second - a[j].second), 2));
                    //This is no longer the first run.
                    firstRun = false;
                    //Assume the first two points are the minimum distance.
                    closest.first = i;
                    closest.second = j;
                }
                //Store the current calculated distance.
                current = sqrt(pow((a[i].first - a[j].first), 2) + pow((a[i].second - a[j].second), 2));
                //Check if the current distance is closer than the previous minimum.
                if (current < delta) {
                    //If so, use this as the new minimum distance, delta.
                    delta = current;
                    //Store the points of the 'new' minimum distance.
                    closest.first = i;
                    closest.second = j;
                }
        }
    }
    return closest;
}
