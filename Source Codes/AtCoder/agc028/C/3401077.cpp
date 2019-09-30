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

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}
#define int long long
signed main(){
    int n;
    cin >> n;
    vector<pair<int,pair<int,int> > >v(2*n);
    ll sm_x=0;
    ll sm_y = 0;
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        v[2*i] =MP(x,MP(i,0));
        v[2*i+1] = MP(y,MP(i,1));
        sm_x += x;
        sm_y += y;
    }
    sort(v.begin(),v.end());
    vector<bool>p(n),q(n);
    ll ans = 0;
    for(int i=0;i<2*n;i++){
        if(i<n){
            ans += v[i].first;
            if(v[i].second.second==0){
                p[v[i].second.first] = 1;
                
            }else{
                q[v[i].second.first] = 1;
            }
        }else{
            bool flag = 0;
            for(int j=0;j<n;j++){
                if(p[j]&&q[j]){
                    flag = 1;
                }
            }
            if(flag)break;
            
            if(v[i].second.first!=v[i-1].second.first){
                ans += v[i].first;
                ans -=v[i-1].first;
            }else{
                int tmp = v[i].first - v[i-2].first;
                tmp = min(tmp,v[i+1].first-v[i-1].first);
                ans += tmp;
            }
            break;
            
        }
        
    }
    cout << min(ans,min(sm_x,sm_y)) << endl;
    return 0;
}