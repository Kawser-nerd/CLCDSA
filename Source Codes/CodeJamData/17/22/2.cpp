#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cassert>
#define PB push_back
#define MP make_pair
#define sz(v) (in((v).size()))
#define forn(i,n) for(in i=0;i<(n);++i)
#define forv(i,v) forn(i,sz(v))
#define fors(i,s) for(auto i=(s).begin();i!=(s).end();++i)
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef long long in;
typedef vector<in> VI;
typedef vector<VI> VVI;
vector<string> bs,rs,ys;
in n,r,o,y,g,b,v;
bool mrg(in& a, in& b, vector<string>& v, char ca, char cb){
  if(a+b==0)
    return 1;
  if(a==b && a+b==n){
    string s;
    forn(i,a){
      s+=ca;
      s+=cb;
    }
    cout<<s<<"\n";
    return 0;
  }
  if(a<=b){
    cout<<"IMPOSSIBLE\n";
    return 0;
  }
  string s(1,ca);
  forn(i,b){
    s+=cb;
    s+=ca;
  }
  v.PB(s);
  forn(i,a-b-1)
    v.PB(string(1,ca));
  return 1;
}
void dot(){
  cin>>n>>r>>o>>y>>g>>b>>v;
  bs.clear();
  rs.clear();
  ys.clear();
  if(!mrg(r,g,rs,'R','G'))
    return;
  if(!mrg(y,v,ys,'Y','V'))
    return;
  if(!mrg(b,o,bs,'B','O'))
    return;
  if(sz(ys)>sz(rs))
    swap(ys,rs);
  if(sz(bs)>sz(rs))
    swap(bs,rs);
  r=sz(rs);
  y=sz(ys);
  b=sz(bs);
  if(r>b+y || b>r+y || y>b+r){
    cout<<"IMPOSSIBLE\n";
    return;
  }
  forn(i,r){
    cout<<rs.back();
    rs.pop_back();
    if(i<b){
      cout<<bs.back();
      bs.pop_back();
    }
    else{
      cout<<ys.back();
      ys.pop_back();
    }
    if(i<(b+y-r)){
      cout<<ys.back();
      ys.pop_back();
    }
  }
  cout<<"\n";
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in t;
  cin>>t;
  forn(z,t){
    cout<<"Case #"<<(z+1)<<": ";
    dot();
  }
  return 0;
}
