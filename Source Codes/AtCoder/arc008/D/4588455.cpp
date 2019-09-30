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

template <typename Monoid>
class SegmentTree
{
  using F=function<Monoid(Monoid,Monoid)>;
public:
  const F f;
  const Monoid M1;
  int sz;
  vector<Monoid> seg;

  SegmentTree(int n,F fu,Monoid &m1):f(fu),M1(m1)
  {
    sz=1;
    while(n>sz)sz<<=1;
    seg.assign(2*sz,M1);
  }
  void update(int k,const Monoid &x)
  {
    k+=sz;
    seg[k]=x;
    while(k>>=1)
    {
      seg[k]=f(seg[k*2],seg[k*2+1]);
    }
  }
  Monoid query(int l,int r)
  {
    Monoid L=M1,R=M1;
    l+=sz;r+=sz;
    for(;l<r;l>>=1,r>>=1)
    {
      if(l&1)L=f(L,seg[l++]);
      if(r&1)R=f(seg[--r],R);
    }
    return f(L,R);
  }
};
typedef pair<double,double> P;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,m;
  cin>>n>>m;
  P p1={1,0};
  SegmentTree<P> seg(m+1,[](P a,P b){P r={a.first*b.first,b.first*a.second+b.second};return r;},p1);
  double h=1,l=1;
  vector<ll>p(m),pp;
  vector<double>a(m),b(m);
  unordered_map<ll,int> ma;
  rep(i,m)
  {
    cin>>p[i]>>a[i]>>b[i];
  }
  pp=p;
  sort(all(pp));
  rep(i,m)ma[pp[i]]=i+1;
  rep(i,m)
  {
    seg.update(ma[p[i]],{a[i],b[i]});
    auto tp=seg.query(1,m+1);
    double r=tp.first+tp.second;
    chmax(h,r);
    chmin(l,r);
  }
  cout<<setprecision(12);
  cout<<l<<endl;
  cout<<h<<endl;
  return 0;

}