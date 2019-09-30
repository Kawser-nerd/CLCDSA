#include <iostream>
#include <string>
#include <vector>
# define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;


int main() {
    int h, w;
    cin >> h >> w;

    vector<string> m(h);
    rep (i, h) cin >> m[i];

    rep (i, h+2) {
        if (i == 0 or i == h+1) {
            rep (j, w+2) cout << '#';
            cout << endl;
        }
        else {
            cout << '#';
            rep (j, w) cout << m[i-1][j];
            cout << '#' << endl;
        }
    }
    return 0;
}