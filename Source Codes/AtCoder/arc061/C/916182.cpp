#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <bitset>
using namespace std;

#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define fi first
#define se second

#define INF 2147483600
typedef pair<int, int> P;

int main(){
  int n,m;
  cin>>n>>m;
  vector<vector<P> > vec(n, vector<P>());

  rep(i,m){
    int p,q,c;
    scanf("%d %d %d", &p, &q, &c);
    p--;q--;
    vec[p].pb(mp(q,c));
    vec[q].pb(mp(p,c));
  }

  // pair[i,j] node i?j???
  // ??map????????TLE????????pair[i,j] -> idx ?????????
  // ????????nvec???
  map<P, int> p2i;  //pair to int
  vector<vector<P> > nvec;
  int idx=0;
  rep(i,n){
    // ??map??????
    if(p2i.find(mp(i,0))==p2i.end()){
      p2i[mp(i,0)] =idx++;
      nvec.pb(vector<P>());
    }
  }
  rep(i,n){
    // map?????????
    for(auto p : vec[i]){
      if(p2i.find(mp(i,p.se))==p2i.end()){
        p2i[mp(i,p.se)]=idx++;
        nvec.pb(vector<P>());
      }
      if(p2i.find(mp(p.fi,p.se))==p2i.end()){
        p2i[mp(p.fi,p.se)]=idx++;
        nvec.pb(vector<P>());
      }
    }
    // ???
    // a->b???????a???(cost1)?b?????a->b??????3????
    for(auto p :vec[i]){  //p.fi:dist p.se:type
      nvec[p2i[mp(i,0)]].pb(mp(p2i[mp(i,p.se)], 1));
      nvec[p2i[mp(i,p.se)]].pb(mp(p2i[mp(p.fi,p.se)],0));
      nvec[p2i[mp(p.fi,p.se)]].pb(mp(p2i[mp(p.fi,0)],0));
    }
  }

  priority_queue<P, vector<P>, greater<P> > pq;  // <cost, to>
  vector<int> c(idx, INF);
  pq.push(mp(0,p2i[mp(0,0)]));
  while(!pq.empty()){
    P p = pq.top(); pq.pop();
    int cost=p.fi, now=p.se;
    if(cost > c[now]) continue;
    for(auto nxt: nvec[now]){
      int ni =nxt.fi, nc=cost + nxt.se;
      if(c[ni] > nc){
        c[ni] = nc;
        pq.push(mp(nc, ni));
      }
    }
  }

  if(c[p2i[mp(n-1,0)]]==INF) cout<<-1<<endl;
  else cout<<c[p2i[mp(n-1,0)]]<<endl;

  return 0;
}