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

int main(){
    cin >> k;
    REP(i,k)
        cin >> a[i];

    ll l = 2,r = 2;

    for(int i = k - 1;i >= 0;i--) {
        l = (l + a[i] - 1) / a[i] * a[i];
        r = r / a[i] * a[i] + a[i] - 1;

        if(l > r)
            break;
    }

    if(l <= r)  {
        cout << l << " " << r << endl;
    }else {
        cout << -1 << endl;
    }
    return 0;
}