#include <iostream>
#include <utility>
using namespace std;

#include "brute_force_closest_pair.h"

int main() {
    pair<double,double> a[4];
    a[0].first = 0.0;
    a[0].second = 5.5;
    a[1].first = 1.5;
    a[1].second = 1.5;
    a[2].first = 1.75;
    a[2].second = 5.75;
    a[3].first = 0.0;
    a[3].second = 1.1;

    pair<int,int> closest = BF_closest_pair( a, 3);

    cout << "(" << a[closest.first].first << "," << a[closest.first].second << ")" << " and ";
    cout << "(" << a[closest.second].first << "," << a[closest.second].second << ")" << endl;


    cin.get();cin.get();
    return 0;
}
