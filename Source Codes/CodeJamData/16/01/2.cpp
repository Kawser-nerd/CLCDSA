#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int tt, n;
bool was[10];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &tt);
    for (int test = 1; test <= tt; ++test) {
        printf("Case #%d: ", test);
        scanf("%d", &n);
        if (n == 0) {
            printf("INSOMNIA\n");
            continue;
        }
        REP(i, 10) was[i] = false;
        int cnt = 0;
        for (int i = n; ; i += n) {
            int num = i;
            while (num) {
                if (!was[num % 10]) {
                    was[num % 10] = true;
                    ++cnt;
                }
                num /= 10;
            }
            if (cnt == 10) {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}
