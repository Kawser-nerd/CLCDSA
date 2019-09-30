#include <cstdio>
#include <vector>
#include <cstring>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1000;

double x[MAXN][MAXN];

int main() {
    ifstream FIN("BASE");
    for (int i = 0; i < MAXN; ++i)
     for (int j = 0; j < MAXN; ++j) {
         FIN >> x[i][j];
         x[i][j] /= 3000;
     }
    
    int T, N, a;
    cin >> T;
    for (int times = 1; times <= T; ++times) {
        cin >> N;
        double ans = 1;
        for (int i = 0; i < N; ++i) {
            cin >> a;
            ans *= x[i][a];
        }
        cout << "Case #" << times << ": ";
        if (ans > 1) cout << "BAD" << endl; else cout << "GOOD" << endl;
    }
    return 0;
}
