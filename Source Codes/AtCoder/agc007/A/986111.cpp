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
typedef array<array<char, 10>, 10> Array;
Array A;
int H, W;

bool func(Array A, int h, int w) {
    A[h][w] = '.';

    if (h == H && w == W) {
        for (auto aa : A) {
            for (auto a : aa) {
                if (a == '#') {
                    return false;
                }
            }
        }
        return true;
    }

    bool ret = false;
    if (A[h + 1][w] == '#'){
        ret |= func(A, h + 1, w);
    }
    if (A[h][w + 1] == '#') {
        ret |= func(A, h, w + 1);
    }
    return ret;
}

int main(void) {
    cin >> H >> W;

    for (auto aa : A) {
        aa.fill('.');
    }

    for (int i = 1; i <= H; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= W; j++) {
            A[i][j] = s[j - 1];
        }
    }

    cout << (func(A, 1, 1) ? "Possible" : "Impossible") << endl;
    return 0;
}