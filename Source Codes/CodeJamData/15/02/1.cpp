#include <bits/stdc++.h>

#define INF 1000000010
#define FO(i,a,b) for (int (i) = (a); (i) < (b); ++(i))

using namespace std;
//PAIRS:
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pii;

/*~~~~TEMPLATE END~~~~*/

int T, D, P[1005];

int main() {
    freopen ("q2.in", "r", stdin);
    freopen ("q2.out", "w", stdout);
    scanf ("%d", &T);
    FO (_z,0,T) {
        printf ("Case #%d: ", _z+1);
        scanf ("%d", &D);
        int ans = INF;
        FO (i,0,D) scanf ("%d", &P[i]);
        FO (i,1,1001) {
            int nSpec = 0;
            FO (p,0,D) {
                nSpec += (P[p]/i) + ((P[p]%i)>0)-1;
            }
            ans = min (ans, nSpec+i);
        }
        printf ("%d\n", ans);
    }
    return 0;
}
