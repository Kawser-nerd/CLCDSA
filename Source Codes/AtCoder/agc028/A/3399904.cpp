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
  lint N,M;
  cin>>N>>M;
  char S[N],T[M];
  REP(i,N)cin>>S[i];
  REP(i,M)cin>>T[i];
  lint n=N;
  lint m=M;
  lint r=n%m;
  while(r!=0){
    n=m;
    m=r;
    r=n%m;
  }
  n=(N*M)/m;
  for(lint i=0;i<N;i++){
    if((i*(n/N))%(n/M)==0){
      if((i*(n/N))/(n/M)>=M)continue;
      if(S[i]!=T[(i*(n/N))/(n/M)]){
        cout<<-1<<endl;
        return 0;
      }       
    }
  }
  cout<<n<<endl;
  return 0;
}