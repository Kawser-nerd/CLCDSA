#include <iostream>
using namespace std;

int main() {
    string S;

    cin >> S;

    int ans = 700;

    if (S[0] == 'o'){
        ans += 100;
    }
    if (S[1] == 'o'){
        ans += 100;
    }
    if (S[2] == 'o'){
        ans += 100;
    }

    cout << ans << endl;
    return 0;
}