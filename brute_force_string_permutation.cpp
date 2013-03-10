#include <iostream>
#include <string>
#include <set>
using namespace std;

#include "brute_force_string_permutation.h"

int main() {
    set<string> out;
    set<char> in;
    in.insert('A');
    in.insert('B');
    in.insert('C');
    in.insert('D');
    in.insert('E');
    out = brute_force_string_permutation(in);

    set<string>::iterator iter;

    for(iter = out.begin(); iter != out.end(); iter++) {
        cout << *iter << endl;
    }

    cin.get();cin.get();
    return 0;
}
