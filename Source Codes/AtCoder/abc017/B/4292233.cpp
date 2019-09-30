#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <vector>

using namespace std;
using ull = unsigned long long;
using P = pair<int, int>;


ull E = 1000000007;
const double pi = 3.14159265359;

int main() {
    string S;
    cin >> S;
    int p = 0;
    bool ans = true;
    for (; p < S.size(); ++p) {
        if (S[p] == 'c') {
            if (S.size() > p + 1 && S[p + 1] == 'h') {
                ++p;
                continue;
            }
        }
        if (S[p] == 'o') continue;
        if (S[p] == 'k') continue;
        if (S[p] == 'u') continue;
        ans = false;
        break;
    }
    if (ans) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}