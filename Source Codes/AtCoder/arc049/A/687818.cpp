#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define MAX_N 102

char S[MAX_N];
int A, B, C, D;

int main(){
  scanf("%s", S);
  scanf("%d %d %d %d", &A, &B, &C, &D);
  int i=0;
  while(i < strlen(S)){
    if(i == A || i == B || i == C || i == D)printf("\"");
    printf("%c", S[i]);
    i++;
  }
  if(i == A || i == B || i == C || i == D)printf("\"");
  printf("\n");
  return 0;
}