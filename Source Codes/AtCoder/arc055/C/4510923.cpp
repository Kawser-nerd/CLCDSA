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

vector <int> ZAlgorithm(const string& S) {
    int sz = S.size();
    vector <int> ret(sz);
    ret[0] = sz;

    int i = 1, j = 0;
    while (i < sz) {
        while (i+j < sz && S[j] == S[i+j]) j++;
        ret[i] = j;
        if (j == 0) { i++; continue; }
        int k = 1;
        while (i+k < sz && k+ret[k] < j) ret[i+k] = ret[k], k++;
        i += k; j -= k;
    }

    return ret;
}

int main() {
    string S, T;
    cin >> S;
    T = S;
    reverse(T.begin(), T.end());

    auto s = ZAlgorithm(S);
    auto t = ZAlgorithm(T);

    ll ans = 0;
    int sz = S.size();
    for (int i = sz / 2 + 1; i < sz - 1; i++) {
        // i-1?i?C?A???
        int A = s[i];
        int C = t[sz - i];

        if (A && C && A + C >= sz - i) {
            A = min(A, sz - i - 1);
            C = min(C, sz - i - 1);
            ans += A + C - (sz - i - 1);
        }
    }

    cout << ans << "\n";
    return 0;
}