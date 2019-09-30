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

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repi(i,a,b) for(ll i=ll(a);i<ll(b);i++)
#define all(x) (x).begin(),(x).end()

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;

using namespace std;
struct edge{ll from,to,cost;};


int  main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  //cout<<setprecision(10);
  ll n,m;
  cin>>n>>m;
  vector<edge>edges(m);
  rep(i,m)
  {
    ll a,b,c;
    cin>>a>>b>>c;
    edges[i]={a,b,c};
  }
  bool update=0;
  ll mm=LLONG_MIN;
  vector<ll>dist(n+1,mm);
  dist[1]=0;
  rep(i,n+1)
  {
    update=0;
    rep(j,m)
    {
      if(dist[edges[j].from]==mm)continue;
      bool tmp=chmax(dist[edges[j].to],dist[edges[j].from]+edges[j].cost);
      if(edges[j].to==n)update|=tmp;
    }
  }
  if(update)cout<<"inf"<<endl;
  else cout<<dist[n]<<endl;

  return 0;

}