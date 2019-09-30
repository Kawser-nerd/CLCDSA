#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <queue>
#include <map>
#include <numeric>
#include <unordered_map>
#include <iomanip>
#include <functional>

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define all(x) (x).begin(),(x).end()

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;

using namespace std;

template <class Abel>
class BIT
{
public:
  using F=function<Abel(Abel,Abel)>;
  F f;
  int l;
  vector<Abel> bit;
  Abel m0;
  BIT(int maxidx,F fu,Abel m0):f(fu),l(maxidx),m0(m0)
  {
    bit.assign(l,m0);
  }
  void update(int idx,int val)
  {
    while(idx<=l)
    {
      bit[idx]=f(bit[idx],val);
      idx+=idx & -idx;
    }
  }
  int query(int idx)
  {
    idx--;
    int res=m0;
    while(idx>0)
    {
      res=f(bit[idx],res);
      idx-=idx& -idx;
    }
    return res;
  }
};
int mod=1e9+7;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;cin>>n;
  vector<int> s(n);
  rep(i,n)cin>>s[i];

  s.erase(unique(all(s)),s.end());

  int l=s.size();
  map<int,vector<int>> cidx;
  vector<int>tv;
  rep(i,l)
  {
    if(cidx.count(s[i])==0)
    {
      cidx[s[i]]=tv;
    }
    cidx[s[i]].push_back(i);
  }

  BIT<int>bt(l+10,[](int a,int b){return (a+b)%mod;},0);
  rep(i,l)
  {
    auto nitr=upper_bound(all(cidx[s[i]]),i);
    if(nitr==cidx[s[i]].end())continue;
    bt.update(*nitr,bt.query(i+1)+1);
  }
  cout<<(bt.query(l)+1)%mod<<endl;



  return 0;

}