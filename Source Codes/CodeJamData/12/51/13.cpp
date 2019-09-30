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

#define MAXN 1111 
int o[MAXN], P[MAXN], L[MAXN], N;

bool cmp(int a,int b){ return P[a] * L[b] > P[b] * L[a]; }

int main(int argc, char *argv[]){
  int T; 
  scanf("%d",&T);
  REP(t,T){
    scanf("%d",&N);
    REP(i,N) scanf("%d",L+i);
    REP(i,N) scanf("%d",P+i);
    REP(i,N) o[i] = i;
    stable_sort(o,o+N,cmp);
    printf("Case #%d:",t+1);
    REP(i,N) printf(" %d",o[i]);
    printf("\n");
  }
  return 0;
}
