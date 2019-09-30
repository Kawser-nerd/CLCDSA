#include <iostream>
#include <string>
using namespace std;

int main() {
    string S; cin >> S;
    int sa = 0, sb = 0, sc = 0;
    for(int i = 0; i < 3; i++) {
        if(S[i] == 'a') sa++;
        if(S[i] == 'b') sb++;
        if(S[i] == 'c') sc++;
    }
    if(sa == 1 && sb == 1 && sc == 1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}