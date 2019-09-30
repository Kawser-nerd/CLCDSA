#include <iostream>
#include <vector>
#include <string>

using namespace std;

string S;

int main(){
    cin >> S;
    int ans = 0;
    char last = S[0];
    for (int i = 1; i < S.size(); ++i) {
        if (last != S[i]) {
            last = S[i];
            ans++;
        }
    }

    cout << ans << endl;
}