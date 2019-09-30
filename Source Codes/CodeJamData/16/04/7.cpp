#include <bits/stdc++.h>

#define INF 1000000010
#define FO(i,a,b) for (int (i) = (a); (i) < (b); ++(i))
#define sz(v) int(v.size())

using namespace std;
//PAIRS:
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pii;
typedef long long ll;

/*~~~~TEMPLATE END~~~~*/

int T;
ll K, C, S;

ll printSeq (int c, int m, ll cum) {
    if (c >= K) {
        if (c == m) return K-1 + cum*K;
        return printSeq(c+1,m,cum*K+K-1);
    }
    if (c == m) return c + cum*K;
    return printSeq(c+1,m,cum*K+c);
}

int main() {
    scanf ("%d",&T);
    FO (_z,0,T) {
        printf ("Case #%d: ", _z+1);
        scanf ("%lld %lld %lld", &K, &C, &S);
        if (C*S < K) {
            printf ("IMPOSSIBLE\n");
            continue;
        }
        for (int i = 0; i < K; i += C) {
            printf ("%lld ", printSeq(i,i+C-1,0)+1);
        }
        printf ("\n");
    }
    return 0;
}

