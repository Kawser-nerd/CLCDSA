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

int main(){
    priority_queue<pair<ll,int> > pq;
    int n,k;
    cin >> n >> k;
    rep(i,n){
        ll tmp;
        int p;
        cin >> p >> tmp;
        pq.push(MP(tmp,p));
    }
    ll ans = 0;
    ll sm=0;
    vector<int> cnt(n+1);
    ll q = 0;
    priority_queue<pair<ll,int> ,vector<pair<ll,int> >,greater<pair<ll,int> >  > pq2;
    int w = 0;
    while(!pq.empty()){
        auto x = pq.top();
        pq.pop();
        ll s = x.first;
        ll t = x.second;
        //cerr << s << " " << t << endl;
        w++;
        if(w<=k){
            if(cnt[t]==0){
                q++;
            }
            cnt[t]++;
            sm += s;
            ans = max(ans,sm+q*q);

            pq2.push(MP(s,t));
        }else{
            if(cnt[t]!=0)continue;
            while(!pq2.empty()){
                auto y = pq2.top();
                pq2.pop();
                if(cnt[y.second]==1){
                    continue;
                }else{
                    cnt[y.second]--;
                    sm -= y.first;
                    cnt[t]++;
                    q++;
                    sm += s;
                    ans = max(ans,sm+q*q);
                    break;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}