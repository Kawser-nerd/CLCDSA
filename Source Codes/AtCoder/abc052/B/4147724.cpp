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
    int x = 0;
    int N;
    string S;
    cin >> N;
    cin >> S;
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        if (S[i] == 'I') {
            ++x;
        } else {
            --x;
        }
        ans = max(ans, x);
    }
    cout << ans << endl;
}