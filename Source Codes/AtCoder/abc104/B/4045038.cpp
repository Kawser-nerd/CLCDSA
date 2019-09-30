#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    string S;
    cin >> S;

    bool ans = true;
    if (S.front() != 'A') {
        ans = false;
    }
    multiset<char> cnt;
    for (int i = 2; i < S.size() - 1; ++i) {
        cnt.insert(S[i]);
    }
    if (cnt.count('C') != 1) {
        ans = false;
    }
    for (int i = 1; i < S.size(); ++i) {
        if (S[i] == 'C') continue;
        if (isupper(S[i])) {
            ans = false;
        }
    }
    if (ans) {
        cout << "AC" << endl;
    } else {
        cout << "WA" << endl;
    }
}