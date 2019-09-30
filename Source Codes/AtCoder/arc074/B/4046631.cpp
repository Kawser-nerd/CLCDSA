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
#include <numeric>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

ll p[300010];
ll q[300010];

int main(){
    int n1;
    cin >> n1;
    int n = 3*n1;
    vector<ll>a(n);
    rep(i,n)cin >> a[i];
    priority_queue<ll>pq2;
    priority_queue<ll,vector<ll>,greater<ll> >pq;
    ll s = 0;
    for(int i=0;i<n;i++){
        if(i<n1){
            pq.push(a[i]);
            s += a[i];
            p[i] = s;
        }else{
            ll x = pq.top();
            if(x>a[i]){
                p[i] = s;
            }else{
                s-=x;
                pq.pop();
                s+=a[i];
                pq.push(a[i]);
                p[i] = s;
            }
        }
    }
    s = 0;
    for(int i=0;i<n;i++){
        if(i<n1){
            pq2.push(a[n-1-i]);
            s += a[n-1-i];
            q[n-1-i] = s;
        }else{
            ll x = pq2.top();
            if(x<a[n-1-i]){
                q[n-1-i] = s;
            }else{
                s-=x;
                pq2.pop();
                s+=a[n-1-i];
                pq2.push(a[n-1-i]);
                q[n-1-i] = s;
            }
        }
    }
    // rep(i,n){
    //     cerr  << p[i] << " ";
    // }
    // cerr << endl;
    
    // rep(i,n){
    //     cerr  << q[i] << " ";
    // }
    // cerr << endl;
    ll mx = -(1LL<<60);
    for(int i=n1-1;i<n-n1;i++){
        mx = max(mx,p[i]-q[i+1]);
    }
    cout << mx << endl;
    return 0;
}