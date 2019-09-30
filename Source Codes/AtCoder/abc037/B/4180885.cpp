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

int a[101];

int main() {
    int N, Q;
    cin >> N >> Q;
    for (int i = 0; i < Q; ++i) {
        int L, R, T;
        cin >> L >> R >> T;
        for (int j = L; j <= R; ++j) {
            a[j] = T;
        }
    }
    for (int i = 1; i <= N; ++i) {
        cout << a[i] << endl;
    }
}