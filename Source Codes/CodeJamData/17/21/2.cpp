#include<iostream>
#include<iomanip>
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
void dot(){
  double d;
  in n;
  cin>>d>>n;
  double k,s;
  double t=0;
  forn(zz,n){
    cin>>k>>s;
    t=max(t,(d-k)/s);
  }
  cout<<d/t<<endl;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout<<setprecision(15);
  in t;
  cin>>t;
  forn(z,t){
    cout<<"Case #"<<(z+1)<<": ";
    dot();
  }
  return 0;
}
