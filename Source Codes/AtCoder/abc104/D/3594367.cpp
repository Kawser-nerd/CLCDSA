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
lint p= 1000*1000*1000+7;

int main(){
  string S;
  cin>>S;
  lint A,AB,ABC,N;
  N=1;
  A=0;
  AB=0;
  ABC=0;
  for(auto c:S){
    if(c=='A'){
      A=A+N;
      A%=p;
    }else if(c=='B'){
      AB=A+AB;
      AB%=p;
    }else if(c=='C'){
      ABC=ABC+AB;
      ABC%=p;
    }else {
      lint Ad=A;
      lint ABd=AB;
      lint ABCd=ABC;
      A=N+Ad*3;
      AB=Ad+ABd*3;
      ABC=ABd+ABCd*3;
      N*=3;
      N%=p;
      A%=p;
      AB%=p;
      ABC%=p;
    }
    // cerr<<A<<" "<<AB<<" "<<ABC<<endl;
  }
  cout<<ABC<<endl;
  return 0;
}