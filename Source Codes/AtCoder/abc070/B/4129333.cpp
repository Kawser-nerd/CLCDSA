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

int S[110];

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    for (int i = A; i < B; ++i) {
        ++S[i];
    }
    for (int i = C; i < D; ++i) {
        ++S[i];
    }
    int ans = 0;
    for (int i = 0; i < 110; ++i) {
        if (S[i] == 2) {
            ++ans;
        }
    }
    cout << ans << endl;
}