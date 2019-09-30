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
    string ans = "";
    int cnt;
    for (char c : S) {
        if (ans.size() == 0) {
            ans += c;
            cnt = 1;
        } else if (ans.back() == c) {
            ++cnt;
        } else {
            ans += to_string(cnt);
            ans += c;
            cnt = 1;
        }
    }
    ans += to_string(cnt);
    cout << ans << endl;
}