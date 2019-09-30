#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <array>
#include <vector>
#include <utility>
#include <bitset>
#include <queue>

using namespace std;

typedef long long ll;
typedef array<int, 20001> A;

constexpr int MAX = 1e9;
int N;
A p, a, b, ab, r;

// p 2 3 1
// r 1 2 3
//
// p 1 2 3
// r 3 1 2

int main(void) {
    cin >> N;
    ab[0] = 1;

    for (int i = 1; i <= N; i++) {
        cin >> p[i];
        r[p[i]] = i;
    }
    for (int i = 1; i <= N; i++) {
        cout << 30000 * r[p[i]];
        cout << ' ';
    }
    cout << endl;
    for (int i = 1; i <= N; i++) {
        cout << 30000 * (N - i + 1) + r[i];
        cout << ' ';
    }
    cout << endl;
    //for (int i = 1; i <= N; i++) {
    //    cout << 30000 * (N + 1) + r[i];
    //    cout << ' ';
    //}
    //cout << endl;

    return 0;
}