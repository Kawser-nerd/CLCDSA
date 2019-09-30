#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>
#include <iomanip>
#include <string.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()

typedef long long lint;

using namespace std;

int main(){
  int K,N;
  cin>>K>>N;
  string v[50],w[50];
  REP(i,N)cin>>v[i]>>w[i];
  vector<int> vn[50];
  REP(i,N){
    REP(j,v[i].size()){
      vn[i].push_back(stoi(v[i].substr(j,1)));
    }
  }
  int wl[N];
  REP(i,N)wl[i]=w[i].size();
  int M=1;
  REP(i,K)M*=3;
  int l[K];
  string ans[9];
  REP(i,K)ans[i]="";
  REP(i,M){
    int ic=i;
    REP(j,K){
      l[j]=ic%3+1;
      ic/=3;
    }
    bool f=true;
    REP(j,N){
    int lt=0;
      for(int d:vn[j]){
        lt+=l[d-1];
      }
      if(lt!=wl[j])f=false;
    }
    if(f){
      REP(j,K)ans[j]="";
      REP(j,N){
        int c=0;
        for(int e:vn[j]){
          if(ans[e-1]=="")ans[e-1]=w[j].substr(c,l[e-1]);
          else if(ans[e-1]!=w[j].substr(c,l[e-1]))f=false;
          c+=l[e-1];
        }
      }
    }
    if(f)break;
  }
  REP(i,K)cout<<ans[i]<<endl;
  return 0;
}