#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string S, T;
    int q;
    cin >> S >> T >> q;

    int s[S.size()], t[T.size()];
    for (int i = 0; i < S.size(); i++) {
        s[i] = S[i] == 'A' ? 1 : 2;
        if (i > 0) s[i] += s[i-1];
    }
    for (int i = 0; i < T.size(); i++) {
        t[i] = T[i] == 'A' ? 1 : 2;
        if (i > 0) t[i] += t[i-1];
    }

    for (int i = 0; i < q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--; b--; c--; d--;

        int c1 = s[b];
        if (a > 0) c1 -= s[a-1];

        int c2 = t[d];
        if (c > 0) c2 -= t[c-1];

        if ((c1 - c2) % 3 == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}