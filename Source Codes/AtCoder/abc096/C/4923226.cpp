#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    vector< vector<string> > map(H, vector<string>(W));

    for (int h = 0; h < H; ++h) {
        string S;
        cin >> S;
        for (int w = 0; w < W; ++w) {
            map[h][w] = S[w];
        }
    }

    // ???????????????k
    bool flg = true;
    for (int h = 0; h < H; ++h) {
        for (int w = 0; w < W; ++w) {

            if (map[h][w] == ".") {
                continue;
            }

            int count = 0;


            // ?
            // map[h-1][w] == "#"
            if (h > 0 && map[h-1][w] == "#") {
                ++count;
            }

            // ?
            // map[h][w-1] == "#"
            if (w > 0 && map[h][w-1] == "#") {
                ++count;
            }

            // ?
            // map[h][w+1] == "#"
            if (w < W - 1 && map[h][w+1] == "#") {
                ++count;
            }

            // ?
            // map[i+1][j] == "#"
            if (h < H - 1 && map[h+1][w] == "#") {
                ++count;
            }

            if (count == 0) {
                flg = false;
                break;
            }

        }
    }

    if (flg) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}