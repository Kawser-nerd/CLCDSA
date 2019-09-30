#include <iostream>
#include <vector>
#include <string>

using namespace std;

int vy[4] = {1, 0, -1, 0};
int vx[4] = {0, 1, 0, -1};

int main() {
    int h, w; cin >> h >> w;
    vector<string> vc;

    for (int i = 0; i < h; ++i) {
        string str; cin >> str;
        vc.push_back(str);
    }

    bool drawable = true;
    for (int i = 0; i < h && drawable; ++i) {
        for (int j = 0; j < w && drawable; ++j) {
            if (vc[i][j] == '.') continue;
            bool check = false;
            for (int k = 0; k < 4; ++k) {
                if ((i - vy[k]) < 0 || (i - vy[k]) >= h) continue;
                if ((j + vx[k]) < 0 || (j + vx[k]) >= w) continue;
                if (vc[i - vy[k]][j + vx[k]] == '#') check = true;
                if (check) break;
            }
            drawable = check;
        }
    }

    cout << (drawable ? "Yes" : "No") << endl;

    return 0;
}