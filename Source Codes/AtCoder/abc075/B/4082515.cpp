#include <iostream>
#include <vector>

using namespace std;
int h, w;
vector<vector<int>> state;

int main() {
    cin >> h >> w;
    int cnt;

    state = vector<vector<int>>(h + 5, vector<int>(w + 5, 0));
    char tmp;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> tmp;
            if (tmp == '.') {
                state[i + 1][j + 1] = 0;
            } else {
                state[i + 1][j + 1] = 1;
            }


        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (state[i + 1][j + 1]) {
                cout << '#';
            } else {
                cout << state[i][j] + state[i][j + 1] + state[i][j + 2]
                        + state[i + 1][j] + state[i + 1][j + 1] + state[i + 1][j + 2]
                        + state[i + 2][j] + state[i + 2][j + 1] + state[i + 2][j + 2];
            }
        }
        cout << endl;
    }


    return 0;
}