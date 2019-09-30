#include <iostream>
#include <vector>
#include <string>

using namespace std;

int vy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int vx[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int main() {
    int h, w; cin >> h >> w;
    vector<string> vc;
    for (int i = 0; i < h; ++i) {
        string str; cin >> str;
        vc.push_back(str);
    }

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (vc[i][j] == '#') cout << '#';
            else {
                int cnt = 0;
                for (int k = 0; k < 8; ++k) {
                    if (i - vy[k] < 0 || i - vy[k] >= h) continue;
                    if (j + vx[k] < 0 || j + vx[k] >= w) continue;
                    if (vc[i - vy[k]][j + vx[k]] == '#') ++cnt;
                }
                cout << cnt;
            }
        }
        cout << endl;
    }

    return 0;
}