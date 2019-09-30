#include <iostream>
using namespace std;

int main() {
    string S;
    cin >> S;

    int ans = 0;
    for (int i = 0; i < S.length(); i++){
        if (S[i]=='+'){
            ans++;
        }
        else{
            ans--;
        }
    }

    cout << ans << endl;
    return 0;
}