#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <regex>

using namespace std;

int main() {
    string S;
    cin >> S;

    bool ok = true;
    int c_cnt = 0;

    for(int i=0; i<S.size(); i++) {
        if(i==0) {
            if ( S[i] != 'A') {
                ok = false;
            }
        } else if(i >= 2 && i <= S.size()-2) {
            if (S[i] == 'C') {
                c_cnt ++;
            } else if ( (S[i] < 'a') || (S[i] > 'z') ) {
                ok = false;
            }
        } else {
            if ( (S[i] < 'a') || (S[i] > 'z') ) {
                ok = false;
            }
        }
    }

    if(c_cnt != 1) {
        ok = false;
    }

    cout << (ok ? "AC" : "WA") << endl;
}