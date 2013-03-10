#include <iostream>
using namespace std;

#include "brute_force_powerSet.h"

int main() {
    set<char> in;
    in.insert('A');
    in.insert('B');
    in.insert('C');
    in.insert('D');
    in.insert('E');

    set<set<char> > b;
    b = powerSet(in);
    
    set<char>::iterator iter;
    set<set<char> >::iterator iter2;

    for(iter2 = b.begin(); iter2 != b.end(); iter2++) {
        for(iter = (*iter2).begin(); iter != (*iter2).end(); iter++) {
            cout << *iter;
        }
        cout << endl;
    }

    cin.get();cin.get();
    return 0;
}
