#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    vector< vector<string> > map(H, vector<string>(W));

    for (int i = 0; i < H; ++i) {
        string S;
        cin >> S;
        for (int j = 0; j < W; ++j) {
            map[i][j] = S[j];
        }
    }

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            int count = 0;

            if (map[i][j] == "#") {
                cout << "#";
                continue;
            }

            // ??
            // map[i-1][j-1] == "#"
            if (i > 0 && j > 0 && map[i-1][j-1] == "#") {
                ++count;
            }

            // ?
            // map[i-1][j] == "#"
            if (i > 0 && map[i-1][j] == "#") {
                ++count;
            }

            // ??
            //map[i-1][j+1] == "#"
            if (i > 0 && j < W -1 && map[i-1][j+1] == "#") {
                ++count;
            }

            // ?
            // map[i][j-1] == "#"
            if (j > 0 && map[i][j-1] == "#") {
                ++count;
            }

            // ?
            // map[i][j+1] == "#"
            if (j < W - 1 && map[i][j+1] == "#") {
                ++count;
            }

            // ??
            // map[i+1][j-1] == "#"
            if (i < H - 1 && j > 0 && map[i+1][j-1] == "#") {
                ++count;
            }

            // ?
            // map[i+1][j] == "#"
            if (i < H - 1 && map[i+1][j] == "#") {
                ++count;
            }

            // ??
            // map[i+1][j+1] == "#"
            if (i < H - 1 && j < W - 1 && map[i+1][j+1] == "#") {
                ++count;
            }

            cout << count;
        }
        cout << endl;
    }
}