#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string S, T;
    cin >> S >> T;

    for (size_t i = 0; i < S.size(); i++) {
        string S_slide;
        S_slide = S.substr(i, S.size()-i) + S.substr(0, i);
        if(S_slide == T) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}