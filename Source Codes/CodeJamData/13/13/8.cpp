#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <utility>
using namespace std;
typedef long long ll;
int r, n, m, k;
map<ll, double> c;
map<ll, map<ll, double> > p;
ll rep(vector<int> cnt){
    ll ret = 0;
    for (int i=0;i<cnt.size();++i)
        for (int j=0;j<cnt[i];++j)
            ret = ret*10+(i+2);
    return ret;
}
void link(vector<int> cnt){
    vector<int> a;
    for (int i=0;i<cnt.size();++i)
        for (int j=0;j<cnt[i];++j)
            a.push_back(i+2);
    ll r = rep(cnt);
    for (int mask=0;mask<(1<<n);++mask){
        ll prod = 1;
        for (int i=0;i<n;++i)
            if (mask&(1<<i))
                prod*=a[i];
        ++p[prod][r];
    }
    ll C = 1;for (int i=0;i<n;++i) C*=(i+1);
    for (int i=0;i<cnt.size();++i)
        for (int j=0;j<cnt[i];++j)
            C/=(1+j);
    c[r] = C;
}
void gen(vector<int> cnt=vector<int>()){
    int rem=n;
    for (int i=0;i<cnt.size();++i)
        rem-=cnt[i];
    if (cnt.size()==m-1){
        if (rem!=0)
            return;
        link(cnt);
        return;
    }
    cnt.push_back(0);
    for (cnt[cnt.size()-1]=0;cnt[cnt.size()-1]<=rem;++cnt[cnt.size()-1])
        gen(cnt);
}
bool comp(ll a, ll b){
    return p[a].size()<p[b].size();
}
int main(){
    {int temp; cin>>temp;}
    cin>>r>>n>>m>>k;
    gen();
    cout<<"Case #1:"<<endl;
    for (int i=0;i<r;++i){
        vector<ll> prods;
        for (int j=0;j<k;++j){
            ll prod;cin>>prod;
            prods.push_back(prod);
        }
        sort(prods.begin(), prods.end(), comp);
        map<ll, double> ans = p[prods[0]];
        for (int j=1;j<prods.size();++j){
            map<ll, double> nans;
            map<ll, double> &M=p[prods[j]];
            for (map<ll, double>::iterator it=ans.begin();it!=ans.end();++it)
                if (M.find(it->first)!=M.end())
                    nans[it->first]=it->second*M[it->first];
            ans = nans;
        }
        for (map<ll, double>::iterator it=ans.begin();it!=ans.end();++it){
            ans[it->first]*=c[it->first];
        }
        ll top;
        double top_ans=-1;
        for (map<ll, double>::iterator it=ans.begin();it!=ans.end();++it)
            if (it->second>top_ans){
                top_ans=it->second;
                top=it->first;
            }
        cout<<top<<endl;
    }
    return 0;
}
