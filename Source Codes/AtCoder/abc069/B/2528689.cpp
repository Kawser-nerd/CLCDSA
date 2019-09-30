#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    printf("%c%ld%c\n", *s.begin(), s.length() - 2, *(s.end() - 1));
    return 0;
}