#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using ull = unsigned long long;

bool valid(char c) {
    return '0' <= c && c <= '9';
}

int main() {
    vector<string> M;
    int H, W;
    cin >> H >> W;
    for (int i = 0; i < H; ++i) {
        string s;
        cin >> s;
        M.push_back(s);
    }
    for (int h = 0; h < H; ++h) {
        for (int w = 0; w < W; ++w) {
            if (M[h][w] == '.') {
                M[h][w] = '0';
            }
        }
    }
    for (int h = 0; h < H; ++h) {
        for (int w = 0; w < W; ++w) {
            if (M[h][w] == '#') {
                if (h > 0 && w > 0 && valid(M[h-1][w-1]))
                    M[h-1][w-1] += 1;
                if (h > 0 && valid(M[h-1][w]))
                    M[h-1][w] += 1;
                if (h > 0 && w + 1 < W && valid(M[h-1][w+1]))
                    M[h-1][w+1] += 1;
                if (w > 0 && valid(M[h][w-1]))
                    M[h][w-1] += 1;
                if (w + 1 < W && valid(M[h][w+1]))
                    M[h][w+1] += 1;
                if (h + 1 < H && w > 0 && valid(M[h+1][w-1]))
                    M[h+1][w-1] += 1;
                if (h + 1 < H && valid(M[h+1][w]))
                    M[h+1][w] += 1;
                if (h + 1 < H && w + 1 < W && valid(M[h+1][w+1]))
                    M[h+1][w+1] += 1;
            }
        }
    }
    for (int h = 0; h < H; ++h) {
        for (int w = 0; w < W; ++w) {
            cout << M[h][w];
        }
        cout << endl;
    }
}