#include <iostream>
#include <vector>

using namespace std;

int A, B;
int D[10][10];
int f[101][101];
int main(){
    cin >> A >> B;

    for (int i = 0; i < A; ++i) {
        for (int j = 0; j < B; ++j) {
            cin >> D[i][j];
        }
    }

    for (int a = 0; a <= 100; ++a) {
        for (int b = 0; b <= 100; ++b) {
            int fmax = 0;
            for (int x = 1; x <= A; ++x) {
                for (int y = 1; y <= B; ++y) {
                    int tmp = max(0, D[x - 1][y - 1] - a * x - b * y);
                    if (tmp > fmax) fmax = tmp;
                }
            }
            f[a][b] = fmax;
            //cout << fmax << " ";
        }
        //cout << endl;
    }

    bool possible = true;

    for (int x = 1; x <= A; ++x) {
        for (int y = 1; y <= B; ++y) {
            int dmin = 1000;
            for (int a = 0; a <= 100; ++a) {
                for (int b = 0; b <= 100; ++b) {
                    int dist = a * x + b * y + f[a][b];
                    if (dmin > dist) dmin = dist;
                }
            }
            if (dmin != D[x - 1][y - 1]) {
                possible = false;
                break;
            }
        }
        if (!possible) break;
    }

    if (possible) {
        cout << "Possible" << endl;
        cout << 202 << " " << 101 * 101 + 200 << endl;
        for (int i = 1; i <= 100; ++i) {
            cout << i << " " << i + 1 << " X" << endl;
            cout << i + 101 << " " << i + 102 << " Y" << endl;
        }

        for (int a = 0; a <= 100; ++a) {
            for (int b = 0; b <= 100; ++b) {
                cout << a + 1 << " " << 202 - b << " " << f[a][b] << endl;
            }
        }
        cout << "1 202" << endl;
    } else {
        cout << "Impossible" << endl;
    }
}