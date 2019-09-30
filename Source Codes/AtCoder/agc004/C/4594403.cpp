#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

string a[505];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int h, w;
    cin >> h >> w;
    for (int i = 0; i < h; i++) cin >> a[i];

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w-1; j++) {
            if (i % 2 == 0 || j == 0 || a[i][j] == '#') cout << '#';
            else cout << '.';
        }
        cout << ".\n";
    }
    cout << '\n';

    for (int i = 0; i < h; i++) {
        cout << '.';
        for (int j = 1; j < w; j++) {
            if (i % 2 == 1 || j == w-1 || a[i][j] == '#') cout << '#';
            else cout << '.';
        }
        cout << '\n';
    }

    return 0;
}