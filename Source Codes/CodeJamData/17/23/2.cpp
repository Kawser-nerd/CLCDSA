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
const in inf=1e18;
VI mdist;
vector<double> spd;
VVI d;
vector<vector<double> > rld;
void dot(){
  in n,q;
  cin>>n>>q;
  d=VVI(n,VI(n,inf));
  rld=vector<vector<double> >(n,vector<double>(n,inf));
  mdist.resize(n);
  spd.resize(n);
  forn(i,n)
    cin>>mdist[i]>>spd[i];
  in tt;
  forn(i,n)
    d[i][i]=rld[i][i]=0;
  forn(i,n){
    forn(j,n){
      cin>>tt;
      if(tt>-1)
	d[i][j]=tt;
    }
  }
  forn(j,n){
    forn(i,n){
      forn(k,n){
	d[i][k]=min(d[i][k],d[i][j]+d[j][k]);
      }
    }
  }
  forn(i,n){
    forn(j,n){
      if(d[i][j]<=mdist[i])
	rld[i][j]=d[i][j]/spd[i];
    }
  }
  forn(j,n){
    forn(i,n){
      forn(k,n){
	rld[i][k]=min(rld[i][k],rld[i][j]+rld[j][k]);
      }
    }
  }
  in ta,tb;
  forn(z,q){
    cin>>ta>>tb;
    cout<<rld[ta-1][tb-1]<<" ";
  }
  cout<<"\n";
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
