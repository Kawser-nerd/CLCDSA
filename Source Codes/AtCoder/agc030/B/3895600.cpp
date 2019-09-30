#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <iomanip>
#include <cstdio>
#include <stack>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define rep(i,n) for(ll i=0;i<(ll)(n);++i)

int main(){
    ll l,n;
    cin >> l >> n;
    vector<ll>a(n);
    vector<ll>p(n);
    rep(i,n)cin >> a[i];
    vector<ll>b(n);
    vector<ll>q(n+2);
    rep(i,n){
        b[i] = l-a[i];
    }
    p[0] = a[0];
    rep(i,n-1){
        p[i+1] = p[i]+a[i+1];
    }
    q[n-1] = b[n-1];
    for(int i=n-2;i>=0;i--){
        q[i] = q[i+1]+b[i];
    }
    ll ans = 0;
    rep(x,n){
        //cerr << x << " " << s << endl;
        ll tmp = 0;
        ll tmp2 = 0;
        if(x==0){
            tmp = max(2*b[1]+a[0],b[0]);
            ans = max(ans,tmp);
            //cerr << x << " " << tmp << endl;
        
            continue;
        }
        if(x==n-1){
            tmp = max(2*a[n-2]+b[n-1],a[n-1]);
            ans = max(ans,tmp);
            //cerr << x << " " << tmp << endl;
        
            continue;
        }
        ll t = n-1-x;
        ll s = x;
        if(s>t){
            tmp += a[x];
            tmp += 2*(q[x+1]);
            if(x-t-1>=0)tmp += 2*(p[x-1]-p[x-t-1]);
            else tmp += 2*p[x-1];
            ans = max(ans,tmp);
            tmp2 += b[x];
            tmp2 += 2*(q[x+1]);
            if(x-t-2>=0)tmp2 += 2*(p[x-1]-p[x-t-2]);
            else tmp2 += 2*p[x-1];
            ans = max(ans,tmp2);
        }else if(s==t){
            tmp += a[x];
            tmp += 2*(p[x-1]);
            tmp += 2*(q[x+1]-q[n]);
            ans = max(ans,tmp);
            tmp2 += b[x];
            tmp2 += 2*(p[x-1]);
            tmp2 += 2*(q[x+1]-q[n]);
            ans = max(ans,tmp2);
        }else{
            tmp += a[x];
            tmp += 2*(p[x-1]);
            tmp += 2*(q[x+1]-q[x+s+2]);
            ans = max(ans,tmp);

            tmp2 += b[x];
            tmp2 += 2*p[x-1];
            tmp2 += 2*(q[x+1]-q[x+s+1]);
            ans = max(ans,tmp2);
        }
        // if(n-x-1>=x+1){
        //     tmp += 2*p[x-1]+2*(q[x+1]-q[x+x+2]);
        //     tmp += a[x];
        //     ans = max(ans,tmp);
            
        // }else{
        //     if(2*x-n-1>=0){
        //         tmp += 2*(p[x-1]-p[2*x-n-1])+2*(q[x+1]-q[n]);
        //         if(x==4){
        //             //cerr << x-1 << " " << 2*x-n-1 << " "  << endl;
        //         }
        //     }else{
        //         tmp += 2*(p[x-1])+2*(q[x+1]-q[n]);
        //     }
        //     tmp += a[x];
        //     ans = max(ans,tmp);
        // }
        // if(n-x-1 >= x){
        //     tmp2 += 2*p[x-1] + 2*(q[x+1]-q[x+x+1]);
        //     tmp2 += b[x];
        //     ans = max(ans,tmp2);
        // }else{
        //     tmp2 += 2*(p[x-1]-p[2*x-n]) + 2*(q[x+1]-q[n]);
        //     //if(x==4)cerr << 2*x-n << " " << x-1 << " " << x+1 << endl;
        //     tmp2 += b[x];
        //     ans = max(ans,tmp2);
        // }
        //cerr << x << " " << tmp << " " << tmp2 << endl;
    }
    cout << ans << endl;
    return 0;
}