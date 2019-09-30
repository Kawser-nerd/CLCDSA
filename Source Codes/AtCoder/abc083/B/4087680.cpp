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
    int N, A, B;
    cin >> N >> A >> B;

    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        string s = to_string(i);
        int n = 0;
        for (char c : s) {
            n += c - '0';
        }
        if (A <= n && n <= B) {
            ans += i;
        }
    }
    cout << ans << endl;
}