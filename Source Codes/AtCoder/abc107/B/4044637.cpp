#include <iostream>
#include <set>

using namespace std;

char M[101][101];

int main() {
    int H, W;
    cin >> H >> W;
    for (int h = 0; h < H; ++h) {
        cin >> M[h];
    }

    set<int> memo_h;
    set<int> memo_w;
    while (true) {
        bool compressed = false;
        for (int h = 0; h < H; ++h) {
            if (memo_h.find(h) != memo_h.end()) continue;
            int w = 0;
            for (; w < W; ++w) {
                if (M[h][w] == '#') break;
            }
            if (w == W) {
                memo_h.insert(h);
                compressed = true;
            }
        }
        for (int w = 0; w < W; ++w) {
            if (memo_w.find(w) != memo_w.end()) continue;
            int h = 0;
            for (; h < H; ++h) {
                if (M[h][w] == '#') break;
            }
            if (h == H) {
                memo_w.insert(w);
                compressed = true;
            }
        }
        if (!compressed) break;
    }

    for (int h = 0; h < H; ++h) {
        if (memo_h.find(h) != memo_h.end()) continue;
        for (int w = 0; w < W; ++w) {
            if (memo_w.find(w) != memo_w.end()) continue;
            cout << M[h][w];
        }
        cout << endl;
    }
}