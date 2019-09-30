#include <iostream>
#include <string>
using namespace std;

int main() {
    string S; cin >> S;
    int cnt = 0;
    for(int i = 0; i < 3; i++) {
        if(S[i] == 'o') cnt++;
    }

    cout << 700 + cnt * 100 << endl;
}