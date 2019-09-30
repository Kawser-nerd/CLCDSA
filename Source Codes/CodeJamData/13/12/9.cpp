#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
map<int, ll> before;
map<int, ll> after;
ll e, r;
int n; 
vector<pair<ll, int> > w;
int main(){
    int tnum;cin>>tnum;
    for (int tcou=0;tcou<tnum;++tcou){
        before.clear();
        after.clear();
        w.clear();
        cin>>e>>r>>n;
        for (int i=0;i<n;++i){
            ll val;cin>>val;
            w.push_back(make_pair(val, i));
        }
        sort(w.begin(), w.end());
        reverse(w.begin(), w.end());
        ll ans=0;
        for (int i=0;i<w.size();++i){
            int ind = w[i].second;
            ll u, l;
            {
                map<int, ll>::iterator it = after.lower_bound(ind);
                if (it==after.begin()){
                    u=e;
                }
                else{
                    --it;
                    u=min(it->second+(ind-it->first)*r, e);
                }
            }
            {
                map<int, ll>::iterator it = before.upper_bound(ind);
                if (it==before.end()){
                    l=0;
                }
                else{
                    l=max(it->second-(it->first-ind)*r, 0LL);
                }
            }
            ans+=(u-l)*w[i].first;
            before[ind]=u;
            after[ind]=l;
        }
        cout<<"Case #"<<(tcou+1)<<": "<<ans<<endl;
    }
    return 0;
}
