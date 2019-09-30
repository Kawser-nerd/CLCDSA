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

int T, N, ans;
char inp[100005];


int main() {
    scanf ("%d", &T);
    FO (_z,0,T) {
        printf ("Case #%d: ", _z+1);
        scanf ("%s", inp);
        N = strlen(inp);
        ans = 0;
        bool isHappy = (inp[0] == '+');
        FO (i,0,N-1) {
            if (inp[i] != inp[i+1]) {
                ans++;
                isHappy = !isHappy;
            }
        }
        if (!isHappy) ans++;
        printf ("%d\n", ans);
    }
    return 0;
}

