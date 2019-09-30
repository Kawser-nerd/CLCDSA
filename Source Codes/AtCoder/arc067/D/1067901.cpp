#include <cstdio>
#include <algorithm>
#define repeat(i,n) for (int i = 0; (i) < int(n); ++(i))
#define repeat_from(i,m,n) for (int i = (m); (i) < int(n); ++(i))
using ll = long long;
using namespace std;

int n, m;
int a[5003];
ll a_acc[5003];
int b[5003][203];
int b_best[203];
int main() {
    scanf("%d%d", &n, &m);
    repeat (i,n-1) scanf("%d", &a[i]);
    repeat (i,n-1) a_acc[i+1] = a_acc[i] + a[i];
    repeat (i,n) repeat (j,m) scanf("%d", &b[i][j]);
    ll ans = 0;
    repeat (l,n) {
        repeat (j,m) b_best[j] = 0;
        ll b_acc = 0;
        repeat_from (r,l,n) { // [l,r]
            repeat (j,m) {
                if (b_best[j] < b[r][j]) {
                    b_acc += - b_best[j] + b[r][j];
                    b_best[j] = b[r][j];
                }
            }
            ans = max(ans, b_acc - (a_acc[r] - a_acc[l]));
        }
    }
    printf("%lld\n", ans);
    return 0;
}