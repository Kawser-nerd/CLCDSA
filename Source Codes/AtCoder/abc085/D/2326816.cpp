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
ll n,h,a[200000],b[200000];
int main(){
    cin >> n >> h;
    REP(i,n) {
        cin >> a[i] >> b[i];
    }

    ll maxa = 0;
    REP(i,n) {
        maxa = max(a[i],maxa);
    }

    sort(b,b + n);


    ll ans = 0;
    RREP(i,n) {
        if(maxa > b[i]) {
            break;
        }

        h -= b[i];
        ans++;
        if(h < 1) {
            cout << ans << endl;
            return 0;
        }
    }

    ans += ((h + maxa - 1) / maxa);
    cout << ans << endl;
    return 0;
}