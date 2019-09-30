/* Writen by Filip Hlasek 2012 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<b;i++)

using namespace std;

long long M,F;
#define MAXN 222
#define MAX 5000000
#define INF 1000000000000000000LL
int N, o[MAXN];
long long P[MAXN], S[MAXN];
long long dp[MAX];

bool cmp(int a,int b){ return P[a] < P[b]; }

bool possible(long long days){
  for(long long p = 1; p <= days; p++){
    long long k = days/p, days1 = days%p;
    if(dp[k] == INF || (days1 && dp[k+1] == INF)) continue;
    if((p-days1)*dp[k] + days1*dp[k+1] <= M) return true;
  }
  return false;
}

long long solve(){
  long long left = 0, right = 2*M, middle;
  while(left < right){
    middle = (left + right + 1) / 2;
    if(possible(middle)) left = middle;
    else right = middle - 1;
  }
  return left;
}

int main(int argc, char *argv[]){
  int T; 
  scanf("%d",&T);
  REP(t,T){
    scanf("%lld%lld%d",&M,&F,&N);
    REP(i,N) scanf("%lld%lld",P+i, S+i);
    REP(i,N) o[i] = i;
    sort(o,o+N,cmp);
    int pos = 0;
    dp[0] = F;
    REP(i,2*M){
      while(pos < N && S[o[pos]] < i) pos++;
      if(pos == N) dp[i+1] = INF;
      else dp[i+1] = dp[i] + P[o[pos]];
    }
    printf("Case #%d: %lld\n",t+1,solve());
  }
  return 0;
}
