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

int T, N;
char inp[1005];
int sCoun[1005];

int main() {
    freopen ("q1.in", "r", stdin);
    freopen ("q1.out", "w", stdout);
    scanf ("%d", &T);
    FO (_z,0,T) {
        printf ("Case #%d: ", _z+1);
        scanf (" %d %s ", &N, inp);
        FO (i,0,N+1) sCoun[i] = inp[i]-'0';
        int ans = 0;
        int soFar = 0;
        FO (i,0,N+1) {
            if (soFar < i) {
                ans += i-soFar;
                soFar = i;
            }
            soFar += sCoun[i];
        }
        printf ("%d\n", ans);
    }
    return 0;
}
