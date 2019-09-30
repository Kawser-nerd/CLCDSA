#include <iostream>
#include <vector>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    vector<string> map(H);
    for (int i = 0; i < H; ++i) {
        cin >> map[i];
    }

    for (int i = 0; i < H-1; ++i) {
        for (int j = 1; j < W; ++j) {
            if (map[i][j] == '#' && map[i+1][j-1] == '#') {
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }

    cout << "Possible" << endl;
    return 0;
}