#include<iostream>
#include<string>
#include<vector>

using namespace std;

int h, w;
string map[12];
vector<string> ord;
bool used[12];
int cnt;

bool check() {
    // for (int i = 0; i < h; ++i) {
    //     cout << ord[i] << endl;
    // }
    // cout << endl;

    // if (h % 2 != 0) {
    //     for (int i = 0; i < w; ++i) {
    //         if (ord[h / 2][i] != ord[h / 2][w - i - 1]) return false;
    //     }
    // }
    for (int i = 0; i < w; ++i) used[i] = false;

    for (int i = 0; i < w; ++i) {
        if (used[i]) continue;
        for (int j = i + 1; j < w; ++j) {
            if (!used[j]) {
                bool rev = true;
                for (int k = 0; k < h; ++k) {
                    if (ord[k][i] != ord[h - k - 1][j]) {
                        rev = false;
                        break;
                    }
                }
                if (rev) {
                    used[i] = true;
                    used[j] = true;
                    // cout << i <<", " << j << endl;
                    break;
                }
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < w; ++i) if (used[i]) cnt++;
    

    // cout << cnt << endl;
    if (w % 2 != 0) {
        for (int i = 0; i < w; ++i)
            if (!used[i])
                for (int k = 0; k < h; ++k)
                    if (ord[k][i] != ord[h - k - 1][i]) return false;
    }
    if (cnt == w / 2 * 2) return true;
    return false;
}

bool all_pair(int bit, int depth=0) {
    if (depth == h / 2) {
        // if (h % 2 == 1) {
        //     for (int i = 0; i < h; ++i) {
        //         if (!((bit >> i) & 1)) {
        //             ord[h / 2] = map[i];
        //         }
        //     }
        // }
        return check();
    }
    //cout << bit << endl;

    for (int i = 0; i < h; ++i) {
        if ((bit >> i) & 1) {
        continue;
        } else {
            for (int j = i + 1; j < h; ++j) {
                if ((bit >> j) & 1) continue;
                ord[depth] = map[i];
                ord[h - depth - 1] = map[j];
                bool ok = all_pair(bit | (1 << i) | (1 << j), depth+1);
                if (ok) return true;
            }
            break;
        }
    }

    return false;
}

int main() {
    cin >> h >> w;
    for (int i = 0; i < h; ++i) {
        cin >> map[i];
        ord.push_back("");
    }

    bool ans = false;
    if (h % 2 == 0) {
        ans = all_pair(0);
    } else {
        ans = false;
        for (int i = 0; i < h; ++i) {
            ord[h / 2] = map[i];
            ans |= all_pair(1 << i);
        }
    }
    cout << (ans ? "YES" : "NO") << endl;
}