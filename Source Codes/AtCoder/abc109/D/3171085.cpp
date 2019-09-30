#include <iostream>
#include <vector>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h + 1, vector<int>(w + 1, 0));
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> a[i][j];
        }
    }

    int count = 0;
    vector<int> y_prev(h * w), x_prev(h * w), y_next(h * w), x_next(h * w);
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j < w; j++) {
            if (a[i][j] & 1) {
                a[i][j]--;
                y_prev[count] = i;
                x_prev[count] = j;
                a[i][j + 1]++;
                y_next[count] = i;
                x_next[count] = j + 1;
                count++;
            }
        }
        if (a[i][w] & 1 && i < h) {
            a[i][w]--;
            y_prev[count] = i;
            x_prev[count] = w;
            a[i + 1][w]++;
            y_next[count] = i + 1;
            x_next[count] = w;
            count++;
        }
    }

    cout << count << endl;
    for (int i = 0; i < count; i++) {
        cout << y_prev[i] << " " << x_prev[i] << " " << y_next[i] << " " << x_next[i] << endl;
    }
}