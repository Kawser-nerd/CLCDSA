#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <set>

using namespace std;

int teste, T, n;
long long E,R;

set<int> occ;

int a[10000], b[10000];

bool compara(int aa, int bb) {
    return a[aa] == a[bb] ? aa<bb : a[aa]>a[bb];
}

int main() {
    for (scanf("%d", &T); T; T--) {
        occ.clear();
        printf("Case #%d: ", ++teste);

        scanf("%lld %lld %d", &E, &R, &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        for (int i = 0; i < n; i++) b[i] = i;

        sort(b, b+n, compara);
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            set<int>::iterator last = occ.lower_bound( b[i] );

            long long best;
            if (last == occ.begin()) {
                best = E;
            }
            else {
                last--;
                best = min(E, (b[i] - *last)*R);
                last++;
            }

            if (last == occ.end()) {

            }
            else {
                // x + R*diff = E
                // x = E - R*diff
                best = max(0LL, min(best, best - ( E - R * (*last - b[i]) ) )); 
            }

            //printf("%d %d %d\n", b[i], best, i);
            ans += best * a[b[i]];
            occ.insert(b[i]);
        }

        printf("%lld\n", ans);
    }
}