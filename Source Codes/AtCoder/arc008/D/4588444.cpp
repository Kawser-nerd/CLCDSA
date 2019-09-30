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


template <class Monoid>struct SegmentTree
{

  using Func = function<Monoid(Monoid, Monoid)>;
  const Func F;
  const Monoid M1;
  int sz;
  vector<Monoid> seg;

  SegmentTree(int n,const Func fu, const Monoid &m1): F(fu) , M1(m1) { init(n); }
  void init(int n) {
      sz= 1;
      while (sz < n) sz *= 2;
      seg.assign(sz * 2, M1);
  }

  void update(int k,const Monoid &x)
  {
    k+=sz;
    seg[k]=x;
    while(k>>=1)
    {
      seg[k]=F(seg[k*2],seg[k*2+1]);
    }
  }
  Monoid query(int l,int r)
  {
    Monoid L=M1,R=M1;
    l+=sz;r+=sz;
    for(;l<r;l>>=1,r>>=1)
    {
      if(l&1)L=F(L,seg[l++]);
      if(r&1)R=F(seg[--r],R);
    }
    return F(L,R);
  }
};


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;
  int m;
  cin>>n>>m;
  vector<ll>p(m),pp;
  vector<double>a(m),b(m);
  rep(i,m)
  {
    cin>>p[i]>>a[i]>>b[i];
  }
  pp=p;
  sort(all(pp));
  pp.erase(unique(all(pp)),pp.end());
  int nn=(int)pp.size();

  SegmentTree<pair<double,double> > seg(nn,
                                        [](pair<double,double> a,pair<double,double> b){
                                          return make_pair(a.first*b.first,b.first*a.second+b.second);
                                        },
                                        make_pair(1.0,0.0));
  double h=1,l=1;

  rep(i,m)
  {
    int idx=lower_bound(all(pp),p[i])-pp.begin();
    seg.update(idx,{a[i],b[i]});
    auto tp=seg.query(0,nn);
    double r=tp.first+tp.second;
    chmax(h,r);
    chmin(l,r);
  }
  cout<<setprecision(12);
  cout<<l<<endl;
  cout<<h<<endl;
  return 0;

}