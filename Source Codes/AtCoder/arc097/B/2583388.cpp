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

ll n,m,p[200000];

ll par[200000];
ll ran[200000];

void init(ll n) {
    REP(i,n){
        par[i] = i;
        ran[i] = 0;
    }
}

ll find(ll x) {
    if(par[x] == x)
        return x;
    return par[x] = find(par[x]);
}

void unite(ll x,ll y) {
    x = find(x);
    y = find(y);

    if(x == y) {
        return ;
    }

    if(ran[x] < ran[y]) {
        par[x] = par[y];
    }else {
        par[y] = par[x];
        if(ran[y] == ran[x]) ran[x]++;
    }
}

bool same(ll x,ll y) {
    return find(x) == find(y);
}

int main() {
    cin >> n >> m;
    REP(i,n)
        cin >> p[i];

    init(n + 1);

    REP(i,m) {
        ll x,y;
        cin >> x >> y;
        unite(x,y);
    }

    ll ans = 0;

    REP(i,n) {
        if(same(i + 1,p[i]))ans++;
    }
    cout << ans << endl;
    return 0;
}