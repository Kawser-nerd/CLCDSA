#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using ull = unsigned long long;
using P = pair<int, int>;


ull E = 1000000007;

int main() {
    int K, S;
    cin >> K >> S;
    int ans = 0;
    for (int X = 0; X <= K; ++X) {
        if (X > S) break;
        for (int Y = 0; Y <= K; ++Y) {
            if (X + Y > S) break;
            if (S - (X + Y) <= K) ++ans;
        }
    }
    cout << ans << endl;
}