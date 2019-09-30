#include <algorithm>
#include <bitset>
#include <cstdio>
#include <cassert>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

typedef long long LL;
typedef pair<int, int> P;
typedef pair<LL, LL> PLL;

const int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

string field[100];
string a[100];
string b[100];

int main() {
    int h, w;

    cin >> h >> w;

    for (int j = 0; j < h; ++j) {
        cin >> field[j];
        a[j] = string(w, '#');
        b[j] = string(w, '.');
    }


    for (int j = 0; j < h; ++j) {
        for (int k = 0; k < w; ++k) {
            if (field[j][k] == '.') {
                a[j][k] = '.';
                continue;
            }
            for (int d = 0; d < 8; ++d) {
                int nx = j + dx[d], ny = k + dy[d];

                if (0 <= nx && nx < h && 0 <= ny && ny < w) {
                    if (field[nx][ny] == '.') {
                        a[j][k] = '.';
                        break;
                    }
                }
            }
        }
    }

    for (int j = 0; j < h; ++j) {
        for (int k = 0; k < w; ++k) {
            if (a[j][k] == '#') {
                b[j][k] = '#';
                for (int d = 0; d < 8; ++d) {
                    int nx = j + dx[d], ny = k + dy[d];
                    if (0 <= nx && nx < h && 0 <= ny && ny < w) {
                        b[nx][ny] = '#';
                    }
                }

            }
        }
    }

    bool flag = true;
    for (int j = 0; j < h; ++j) {
        for (int k = 0; k < w; ++k) {
             flag = flag && (field[j][k] == b[j][k]);
        }
    }

    if (flag) {
        cout << "possible" << endl;
        for (int j = 0; j < h; ++j) {
            cout << a[j] << endl;
        }
    } else {
        cout << "impossible" << endl;
    }

    return 0;
}