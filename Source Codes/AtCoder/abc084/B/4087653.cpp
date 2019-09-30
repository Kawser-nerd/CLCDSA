#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;
using ull = unsigned long long;

int main() {
    int A, B;
    cin >> A >> B;
    string S;
    cin >> S;

    bool ans = true;
    int i = 0;
    for (; i < A; ++i) {
        if (!isdigit(S[i])) {
            ans = false;
        }
    }
    if (S[i++] != '-') {
        ans = false;
    }
    for (; i < B + A + 1; ++i) {
        if (!isdigit(S[i])) {
            ans = false;
        }
    }
    if (ans) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}