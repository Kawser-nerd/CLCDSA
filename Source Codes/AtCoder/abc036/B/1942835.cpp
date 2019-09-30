/**
 * B - ??
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    vector<string> s;

    cin >> N;

    for (int i = 0; i < N; i++) {
        string s_;
        cin >> s_;
        s.push_back(s_);
    }

    for (int j = 0; j < N; j++) {
        for (int i = N - 1; i >= 0; i--) {
            cout << s[i][j];
        }
        cout << endl;
    }
}