#include <algorithm>
#include <cstdio>
#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
using std::cin;
using std::cout;
using std::endl;

int main(void) {

    char result[100][100];
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 100; j++) {
            result[i][j] = '.';
        }
    }
    for (int i = 50; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            result[i][j] = '#';
        }
    }

    int a, b;
    cin >> a >> b;

    int x = 0, y = 1;
    for (int i = 1; i < b; i++) {
        if (y >= 100) {
            y = 1;
            x += 2;
        }
        result[x][y] = '#';
        y += 2;
    }
    x = 99;
    y = 1;
    for (int i = 1; i < a; i++) {
        if (y >= 100) {
            y = 1;
            x -= 2;
        }
        result[x][y] = '.';
        y += 2;
    }

    cout << 100 << " " << 100 << endl;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            cout << result[i][j];
        }
        cout << endl;
    }

    return 0;
}