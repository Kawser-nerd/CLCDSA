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
  int H,W;
  cin>>H>>W;
  char C[H+2][W+2];
  REP(i,H+2)REP(j,W+2)C[i][j]='#';
  FOR(i,1,H+1)FOR(j,1,W+1)cin>>C[i][j];
  char D[H+2][W+2];
  REP(i,H+2)REP(j,W+2)D[i][j]='.';
  FOR(i,1,H+1)FOR(j,1,W+1){
    bool f=false;
    FOR(ii,-1,2)FOR(jj,-1,2){
      if(C[i+ii][j+jj]=='.')f=true;
    }
    D[i][j]=(f?'.':'#');
  }
  char E[H+2][W+2];
  REP(i,H+2)REP(j,W+2)E[i][j]='#';
  FOR(i,1,H+1)FOR(j,1,W+1){
    bool f=false;
    FOR(ii,-1,2)FOR(jj,-1,2){
      if(D[i+ii][j+jj]=='#')f=true;
    }
    E[i][j]=(f?'#':'.');
  }
  // FOR(i,1,H+1){
  //   FOR(j,1,W+1)cerr<<E[i][j];
  //   cerr<<endl;
  // }
  bool f=true;
  FOR(i,1,H+1)FOR(j,1,W+1){
    if(C[i][j]!=E[i][j])f=false;
  }
  if(f){
    cout<<"possible"<<endl;
    FOR(i,1,H+1){
      FOR(j,1,W+1)cout<<D[i][j];
      cout<<endl;
    }
  }else{
    cout<<"impossible"<<endl;
  }
  return 0;
}