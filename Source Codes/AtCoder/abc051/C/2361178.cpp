#include <iostream>

using namespace std;

int main () {

    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;


    string ans = "";
    int dh = ty - sy, dr = tx - sx;
    for (int i = 0; i < dh; i++) {
        ans += 'U';
    }
    for (int i = 0; i < dr; i++) {
        ans += 'R';
    }
    for (int i = 0; i < dh; i++) {
        ans += 'D';
    }
    for (int i = 0; i < dr; i++) {
        ans += 'L';
    }

    ans += 'L';
    for (int i = 0; i < dh + 1; i++) {
        ans += 'U';
    }
    for (int i = 0; i < dr + 1; i++) {
        ans += 'R';
    }
    ans += "DR";
    for (int i = 0; i < dh + 1; i++) {
        ans += 'D';
    }
    for (int i = 0; i < dr + 1; i++) {
        ans += 'L';
    }
    ans += 'U';

    cout << ans << endl;

    return 0;
}