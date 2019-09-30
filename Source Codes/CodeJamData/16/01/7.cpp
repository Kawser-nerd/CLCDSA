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
ll N;
bool seen[12];

void setSeen(ll c) {
    while (c != 0) {
        int dig = c%10;
        seen[dig] = true;
        c /= 10;
    }
}

bool allSeen() {
    FO (i,0,10) if (!seen[i]) return false;
    return true;
}

int main() {
    scanf ("%d", &T);
    FO (_z,0,T) {
        printf ("Case #%d: ", _z+1);
        scanf ("%lld", &N);
        memset (seen,0,sizeof(seen));
        if (N == 0) {
            printf ("INSOMNIA\n");
            continue;
        }
        ll origN = N;
        FO (i,0,1000000) {
            setSeen(N);
            if (allSeen()) {
                printf ("%lld\n", N);
                break;
            }
            N += origN;
        }
        if (!allSeen()) {
            printf ("INSOMNIA\n");
        }
    }
    return 0;
}
