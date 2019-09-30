#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <cmath>
 
using namespace std;
 
#define rep(i,n) for(int i = 0; i<n ; i++)
#define FOR(i,a,n) for(int i=a; i<n; i++)
 
#define RANGE(a,i,b) ((a)<=(i)&&(i)<=(b))
 
#define pb push_back
#define mp make_pair
 
#define ALL(a) (a).begin(), (a).end()
 
#define SET(a,c) memset(a,c,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))
 
#define INF 1001001001
#define LLINF 1001001001001001001LL
 
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
 
#define PQ priority_queue
 
#define FST first
#define SEC second
#define int long long 
 
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
 
//------------------HEAD---------------------
int a[112345];
int d[112345];
signed main(void){
    int k,n;
    cin>>k>>n;
    rep(i,n){
        cin>>a[i]>>d[i];
    }
    int p,q;
    p=0;
    q=1e12;
    while(q-p>1){ 
        int r=(p+q)/2;
        int t=0;
        rep(i,n){
            t+=max(0ll,(r-a[i]+d[i])/d[i]);
        }
        if(t>=k)q=r;
        else p=r;
    }
    int ans=0;
    int t=0;
    rep(i,n){
        for(int c=a[i];c<q;c+=d[i]){
            ans+=c;
            ++t;
        }
    }
    cout<<ans+q*(k-t)<<endl;
    return 0;
}