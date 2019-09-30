#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string S; cin >> S;
    int nofzero = 0, nofone = 0;
    for (int i = 0; i < (int)S.length(); i++) {
        if(S[i] == '0') {
            nofzero++;
        } else {
            nofone++;
        }
    }
    cout << min(nofzero, nofone) * 2 << endl;
}