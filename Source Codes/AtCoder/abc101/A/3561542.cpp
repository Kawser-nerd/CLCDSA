#include <iostream>
#include <string>
using namespace std;

int main() {
    string S; cin >> S;
    int p = 0, m = 0;
    for(int i = 0; i < 4; i++) {
        if(S[i] == '+') {
            p++;
        } else {
            m++;
        }
    }
    cout << p - m << endl;
}