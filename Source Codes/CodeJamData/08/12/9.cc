#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORI(i,v) FOR(i,(int)v.size())
#define BEND(v) v.begin(),v.end()
#define dump(x) cerr << #x << " = " << (x) << endl;
typedef long long ll; typedef long double ld;

int cas = 0;
int N,M;
bitset<2048> what;
int mlike[2048];
bitset<2048> ulike[2048];
void doit() {
  what.reset();
  scanf("%d%d",&N,&M);
  memset(mlike,-1,sizeof(mlike));

  FOR(i,M) {
    ulike[i].reset();
    int T;
    scanf("%d",&T);
    FOR(j,T) {
      int X,Y;
      scanf("%d%d",&X,&Y);
      if (Y) {
	assert(mlike[i] == -1);
	mlike[i] = X-1;
      } else {
	ulike[i].set(X-1);
      }
    }
  }

  FOR(i,N) what[i] = true;

  bool possible = true;
  while (possible) {
    bool happy = true;
    FOR(i,M) {
      if ((ulike[i] & what).none()
	&& (mlike[i] == -1 || what[mlike[i]])) {
	happy = false;

	if (mlike[i] == -1) {
	  possible = false;
	} else {
	  what[mlike[i]] = false;
	}
      }
    }

    if (happy) break;
  }

  printf("Case #%d:",++cas);

  if (possible) {
    FOR(i,N) printf(" %d",(int)!what[i]);
  } else {
    printf(" IMPOSSIBLE");
  }
  printf("\n");
}
int T;
int main() {
scanf("%d",&T);
FOR(i,T)doit();
}
