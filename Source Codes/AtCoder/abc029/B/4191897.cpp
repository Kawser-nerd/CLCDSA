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
    int ans = 0;
    for (int i = 0; i < 12; ++i) {
        string S;
        cin >> S;
        for (char c : S) {
            if (c == 'r') {
                ++ans;
                break;
            }
        }
    }
    cout << ans << endl;
}