#include <iostream>
using namespace std;

// A and T, G and C
char counterpart(char c) {
    if (c == 'A') return 'T';
    if (c == 'T') return 'A';
    if (c == 'G') return 'C';
    return 'G';
}


int main() {
    char c; cin >> c;
    cout << counterpart(c) << endl;
    return 0;
}