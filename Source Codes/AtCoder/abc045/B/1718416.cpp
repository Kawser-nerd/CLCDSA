//
// B - 3???????????? / Card Game for Three (ABC Edit)
//

#include <iostream>

using namespace std;

int main() {

    string S['c' + 1];
    int L['c' + 1];
    int P['c' + 1] = {0};

    for (int i = 'a'; i <= 'c'; i++) {
        cin >> S[i];
        L[i] = (int) S[i].length();
    }

    char prev = 'a';

    while (true) {
        if (P[prev] == L[prev]) break;
        char next = S[prev][P[prev]];
        P[prev]++;
        prev = next;
    }

    cout << (char) (prev - 32) << endl;
}