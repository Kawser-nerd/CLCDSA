#include<iostream>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define pb push_back
int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};
 
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)

ll n,m;
ll pro[200000];
ll cou[200000];

int main() {
    cin >> n >> m;
    REP(i,n)
        cou[i] = 1;

    pro[0] = true;
    REP(i,m) {
        ll x,y;
        cin >> x >> y;
        x--;y--;

        if(pro[x])pro[y] = true;

        cou[x]--;cou[y]++;
        if(cou[x] == 0)
            pro[x] = 0;
    }
    ll ans = 0;
    REP(i,n)
        if(pro[i])
            ans ++ ;
    cout << ans << endl;
    return 0;
}