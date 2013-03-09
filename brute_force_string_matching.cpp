#include <iostream>
using namespace std;

#include "brute_force_string_matching.h"

int main() {
    char s2[] = "Hello there";
    char s1[] = "Hi there o Hello there...";
    char *s3;
    s3 = BF_string_matching(s1, s2);

    cout << s3 << endl;

    cin.get();cin.get();
    return 0;
}
