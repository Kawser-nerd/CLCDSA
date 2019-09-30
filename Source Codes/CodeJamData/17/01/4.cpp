#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int testCount, test;

int n, k;
string s;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &testCount);
    for (test = 1; test <= testCount; ++test) {
        printf("Case #%d: ", test);

        cin >> s >> k;
        n = (int)s.size();
        int ans = 0;
        forn(i, n - k + 1) {
            if (s[i] == '-') {
                forn(j, k) {
                    s[i + j] = (s[i + j] == '+' ? '-' : '+');
                }
                ++ans;
            }
        }
        forn(i, n) if (s[i] == '-') {
            ans = -1;
        }
        if (ans == -1) {
            printf("IMPOSSIBLE\n");
        } else {
            printf("%d\n", ans);
        }

        cerr << "Done #" << test << endl;
    }
    return 0;
}
