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

static constexpr ull MOD = 1000000007;
static constexpr double pi = 3.14159265359;

int main() {
    string S, T;
    cin >> S;
    cin >> T;

    map<char, int> MS, MT;
    for (char c : S) {
        MS[c]++;
    }
    for (char c : T) {
        MT[c]++;
    }
    vector<int> VS, VT;
    for (auto i : MS) {
        VS.push_back(i.second);
    }
    for (auto i : MT) {
        VT.push_back(i.second);
    }
    sort(VS.begin(), VS.end());
    sort(VT.begin(), VT.end());
    if (VS == VT) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}