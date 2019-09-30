#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<list>
#include<map>
#include<set>
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
ll k,a[200000];

ll f(ll i,ll n) {
    if(i < 0)
        return n;

    ll x = f(i - 1,n);
    return x - x % a[i];
}

ll g(ll n) {
    return f(k - 1,n);
}

ll bins1() {
    ll l = 0,r = 2*1e14;

    while(r - l > 1) {
        ll m = (r + l) / 2;

        if(g(m) >= 2) {
            r = m;
        }else {
            l = m;
        }
    }
    return r;
}

ll bins2() {
    ll l = 1,r = 2*1e14;

    while(r - l > 1) {
        ll m = (r + l) / 2;

        if(g(m) <= 2) {
            l = m;
        }else {
            r = m;
        }
    }
    return l;
}

int main(){
    cin >> k;
    REP(i,k)
        cin >> a[i];

    ll a = bins1();
    ll b = bins2();

    if(a > b) {
        cout << -1 << endl;
    }else {
        cout << a << " " << b << endl;
    }
    return 0;
}