// NAGLOWEK

#include <algorithm>
#include <cstdio>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <string>
#include <cstring>
#include <functional>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<int,int> PII;

#define REP(i,n) for(int i=0;i<(n);++i)
#define SIZE(c) ((int)((c).size()))
#define FOR(i,a,b) for (int i=(a); i<(b); ++i)
#define FOREACH(i,x) for (__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
#define FORD(i,a,b) for (int i=(a)-1; i>=(b); --i)

#define pb push_back
#define mp make_pair
#define st first
#define nd second

typedef LL intT;

intT GCD(intT a, intT b) {
	intT tmp;
	while(b!=0) {
		tmp = b;
		b = a%b;
		a = tmp;
	}
	return a;
}

/* gcd = ax - by, x>=0, y>=0 */
intT eGCD(intT a, intT b, intT &x, intT &y) {
    if (b==0) {
        x = intT(1);
        y = intT(0);
        return a;
    }   
    intT d = eGCD(b,a%b,y,x);
    y = a-x*(a/b)-y;
    x = b-x;
    return d;
}

intT inverse(intT a, intT p) { intT x,y; eGCD(a%p+p,p,x,y); return x % p; }

LL gcd(LL a, LL b){
  return b?gcd(b,a%b):a;
}

char S[1000000];
const LL MOD = 1000003;
LL _SN[MOD][150];


LL SN(int a, int b){
  return _SN[a][b];
}

LL getPodz(int a, int b){
  if(b>a)return 0;
  return SN(a-1,b-1);
}

LL getWst(int a, int b){
  if(b>a)return 0;
  return SN(a,b);
}

void scase(int CID){
  scanf("%s",S);
  int N = strlen(S);
  REP(i,N)S[i]-='a'-1;
  int count[27];
  REP(i,27)count[i] = 0;
  REP(i,N){count[S[i]]++;}
  int R = 1;
  REP(i,N-1)if(S[i]!=S[i+1])++R;

  LL T[27][R+1];
  int sum = 0;
  REP(i,R+1)T[0][i] = 0;
  T[0][0] = 1;
  FOR(letter,1,27){
    if(count[letter] == 0){
      REP(i,R+1)
        T[letter][i] = T[letter-1][i];
      continue;
    }
    REP(i,R+1)T[letter][i] = 0;
    REP(k,R+1){
      if(T[letter-1][k] == 0)continue;
      REP(a,k+2)
        REP(b,sum - k + 1){
          int k2 = k + a + 2*b;          
          if(k2>R)break;
          if(a+b == 0)continue;
          LL podz = getPodz(count[letter],a+b);
          LL wst = (getWst(k+1,a)*getWst(sum-k,b))%MOD;
          T[letter][k2] += ((podz*wst)%MOD)*T[letter-1][k];
          T[letter][k2] %= MOD;
        }        
    }
    sum += count[letter];
  }
  printf("Case #%d: %lld\n",CID,T[26][R]);
}

int main(){
  _SN[0][0] = 1;
  FOR(i,1,MOD){
    _SN[i][0] = 1;
    if(i<150)_SN[i][i] = 1;
    FOR(j,1,min(i,150))_SN[i][j] = (_SN[i-1][j-1] + _SN[i-1][j])%MOD;  
  }

  int z;
  scanf("%d",&z);
  REP(i,z)scase(i+1);
}

