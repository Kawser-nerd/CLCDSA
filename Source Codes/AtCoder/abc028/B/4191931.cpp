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


int main() {
    map<char, int> ans;
    string S;
    cin >> S;
    for (char c : S) {
        ++ans[c];
    }
    for (char c : {'A', 'B', 'C', 'D', 'E', 'F'}) {
        cout << ans[c] << " \n"[c == 'F'];
    }
}