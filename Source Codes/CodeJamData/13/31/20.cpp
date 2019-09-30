#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
using namespace std;
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
const int maxn = 1000000 + 10;
typedef long long LL;

char s[maxn];
int n;

bool isvowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    //freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int t, ca = 0;
    scanf("%d", &t);
    while (t--) {
        printf("Case #%d: ", ++ca);
        scanf("%s%d", s, &n);
        int last = -1, cnt = 0;
        LL ans = 0;
        for (int i = 0; s[i]; ++i) {
            if (!isvowel(s[i]) && ++cnt >= n) {
                last = i - n + 1;
            } else if (isvowel(s[i])) {
                cnt = 0;
            }
            if (last >= 0) {
                ans += last + 1;
            }
        }
        printf("%I64d\n", ans);
    }
    return 0;
}

