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

int Rect[101][101];

int main() {
    int W, H, N;
    cin >> W >> H >> N;
    for (int h = 1; h <= H; ++h) {
        for (int w = 1; w <= W; ++w) {
            Rect[h][w] = 1;
        }
    }
    for (int i = 0; i < N; ++i) {
        int x, y, a;
        cin >> x >> y >> a;
        if (a == 1) {
            for (int h = 1; h <= H; ++h) {
                for (int w = 1; w <= x; ++w) {
                    Rect[h][w] = 0;
                }
            }
        } else if (a == 2) {
            for (int h = 1; h <= H; ++h) {
                for (int w = x + 1; w <= W; ++w) {
                    Rect[h][w] = 0;
                }
            }
        } else if (a == 3) {
            for (int w = 1; w <= W; ++w) {
                for (int h = 1; h <= y; ++h) {
                    Rect[h][w] = 0;
                }
            }
        } else if (a == 4) {
            for (int w = 1; w <= W; ++w) {
                for (int h = y + 1; h <= H; ++h) {
                    Rect[h][w] = 0;
                }
            }
        }
    }
    int ans = 0;
    for (int h = 1; h <= H; ++h) {
        for (int w = 1; w <= W; ++w) {
            ans += Rect[h][w];
        }
    }
    cout << ans << endl;
}