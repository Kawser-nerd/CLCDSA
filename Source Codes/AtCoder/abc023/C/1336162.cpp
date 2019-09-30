#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <deque>
#include <queue>
#include <tuple>
#include <queue>
#include <functional>
#include <cmath>
#include <iomanip>
#include <map>
#include <set>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <complex>
#include <iterator>
#include <array>
#include <memory>
#include <stack>
#define vi vector<int>
#define vvi vector<vector<int> >
#define ll long long int
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>
#define vc vector<char>
#define vs vector<string>
#define ld long double
#define INF 1e9
#define EPS 0.0000000001
#define rep(i,n) for(int i=0;i<n;i++)
#define loop(i,s,n) for(int i=s;i<n;i++)
#define all(in) in.begin(), in.end()
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
#define MAX 9999999
using namespace std;
#define int ll
typedef pair<int, int> pii;
typedef pair<double,double>pdd;
//typedef pair<ll,ll>pll;
#define int ll
signed main(){
    int R,C,K;
    cin>>R>>C>>K;
    int n; cin>>n;
    vector<pii>v;
    vector<vector<int>>data(100100,vi()),dat2(100100,vi());
    map<pii,int>check;
    rep(i,n){
        pii temp; cin>>temp.first>>temp.second;
        v.push_back(temp);
        check[temp]++;
        data[temp.first].push_back(temp.second);
        dat2[temp.second].push_back(temp.first);
    }
    vector<vector<int>>hash(100100,vi());
    for(int i=1; i<=C;i++)
        hash[dat2[i].size()].push_back(i);
    int ans=0;
    for(int i=1;i<=R;i++){
        if((K-(int)data[i].size())<0){continue;}
        //cout<<K-(int)data[i].size()<<endl;
        if((int)hash[K-(int)data[i].size()].size()==0)continue;
        ans+=(int)hash[K-(int)data[i].size()].size();
    }
    rep(i,v.size()){
        if((int)data[v[i].first].size()+(int)dat2[v[i].second].size()==K+1)ans++;
        else if((int)data[v[i].first].size()+(int)dat2[v[i].second].size()==K)ans--;
    }
    cout<<ans<<endl;
}