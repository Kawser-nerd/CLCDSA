#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int tt, n;
char s[105];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &tt);
    for (int test = 1; test <= tt; ++test) {
        printf("Case #%d: ", test);
        scanf("%s", s);
        n = strlen(s);
        int cnt = 1;
        for (int i = 1; i < n; ++i) if (s[i] != s[i - 1]) {
            ++cnt;
        }
        if (s[n - 1] == '+') --cnt;
        printf("%d\n", cnt);
    }
    return 0;
}
