#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int wh, bk;
char map[100][100];

// white .
// black #

int main(){
    cin >> wh >> bk;

    bool reverse = bk > wh;
    if (reverse) {
        int tmp = wh;
        wh = bk;
        bk = tmp;
    }

    // wh >= bk
    int common = min(wh, bk);
    wh -= common;
    bk -= common;

    int ck_h = 0;
    while (ck_h * ck_h / 2 < common) ck_h += 2;

    int cnt = 0;

    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            map[i][j] = ' ';
        }
    }
    int lasti;
    for (int i = ck_h - 1; i >= 0; i--) {
        for (int j = ck_h - 1; j >= 0; j -= 2) {
            if (i % 2 == 1) {
                map[i][j] = '#';
                map[i][j - 1] = '.';
            } else {
                map[i][j] = '.';
                map[i][j - 1] = '#';
            }
            cnt += 1;
            if (cnt == common) {
                if (j - 2 >= 0) {
                    map[i][j - 2] = i % 2 == 1 ? '#' : '.';
                }
                break;
            }
        }
        lasti = i;
        if (cnt == common) break;
    }

    for (int i = lasti; i >= 0; --i) {
        for (int j = 0; j < ck_h; ++j) {
            if (map[i][j] != ' ') continue;
            map[i][j] = map[i + 1][j];
        }
    }

    for (int i = ck_h; i < 100; ++i) {
        for (int j = 0; j < ck_h; ++j) {
            map[i][j] = map[i - 1][j];
        }
    }

    for (int j = ck_h; j < 100; ++j) {
        for (int i = 0; i < ck_h; ++i) {
            map[i][j] = map[i][j - 1];
        }
    }

    for (int i = ck_h; i < 100; ++i) {
        for (int j = ck_h; j < 100; ++j) {
            map[i][j] = '#';
        }
    }

    int i = ck_h;
    int j = ck_h;
    for (int cnt = 0; cnt < wh; ++cnt) {
        map[i][j] = '.';
        j += 2;
        if (j >= 100) {
            j = ck_h;
            i += 2;
        }
    }

    if (reverse) {
        for (int i = 0; i < 100; ++i) {
            for (int j = 0; j < 100; ++j) {
                map[i][j] = map[i][j] == '.' ? '#' : '.';
            }
        }
    }

    cout << "100 100" << endl;
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            cout << map[i][j];
        }
        cout << endl;
    }

}