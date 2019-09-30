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
  int N;
  cin>>N;
  int am=0;
  int temp=0;
  FOR(i,1,N){
    int dist;
    cout << "? " << 1 << " " << i+1 << endl;
    cin >> dist;
    if(dist>temp){
      temp=dist;
      am=i;
    }
  }
  int ans=0;
  REP(i,N){
    if(i==am)continue;
    int dist;
    cout << "? " << am+1 << " " << i+1 << endl;
    cin >> dist;
    ans=max(ans,dist);
  }
  cout << "! " << ans << endl;
  return 0;
}