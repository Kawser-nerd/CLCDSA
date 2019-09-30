#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int testCount, test;
LL n;
string s;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &testCount);
    for (test = 1; test <= testCount; ++test) {
        printf("Case #%d: ", test);

        cin >> n;
        s.clear();
        while (n) {
            s += char(n % 10 + '0');
            n /= 10;
        }
        reverse(s.begin(), s.end());
        int ind = -1;
        forn(i, (int)s.size() - 1) {
            if (s[i] > s[i + 1]) {
                ind = i;
                break;
            }
        }
        if (ind == -1) {
            cout << s << endl;
            cerr << "Done #" << test << endl;
            continue;
        }
        while (ind > 0 && s[ind] == s[ind - 1]) {
            --ind;
        }
        if (ind == 0 && s[ind] == '1') {
            forn(i, (int)s.size() - 1) {
                printf("9");
            }
            puts("");
            cerr << "Done #" << test << endl;
            continue;
        }
        assert(s[ind] != '0');
        --s[ind];
        for (int i = ind + 1; i < (int)s.size(); ++i) {
            s[i] = '9';
        }
        cout << s << endl;

        cerr << "Done #" << test << endl;
    }
    return 0;
}
