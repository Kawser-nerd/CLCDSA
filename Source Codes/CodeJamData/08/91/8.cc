#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <ext/hash_map>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <utility>
#include <vector>
#include <glpk.h> // http://www.gnu.org/software/glpk/
using namespace std;
using namespace __gnu_cxx;

#define FR(i,a,b) for(int i=a;i<b;i++)
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORI(i,v) FOR(i,(int)v.size())
#define RF(i,a,b) for(int i=(a)-1;i>=b;--i)
#define ROF(i,n) RF(i,n,0)
#define FORALL(i,v) for(typeof(v.end())i=v.begin();i!=v.end();++i)
#define ROFALL(i,v) for(typeof(v.rend())i=v.rbegin();i!=v.rend();++i)
#define BEND(v) v.begin(),v.end()
#define setmax(a,b) (a) = max(a,b)
#define dump(x) cerr << #x << " = " << (x) << endl;
typedef long long ll; typedef long double ld;

namespace __gnu_cxx {
  template<>
  struct hash<string> {
    size_t operator()(const string &s) const {
      size_t h = 0;
      FORALL(i,s) h = 107*h + *i;
      return h;
    }
  };
}

int cas=0;
const int inf = 123456789;
int N;
int A[5000],B[5000],C[5000];
void doit() {
  scanf("%d",&N);

  FOR(i,N) {
    scanf("%d%d%d",&A[i],&B[i],&C[i]);
  }

  int best = 0;
  vector<int> bs,cs;
  FOR(a,10001) {
    int rem = 10000-a;
    bs.push_back(inf);
    cs.push_back(-inf);
    FOR(i,N) if (a >= A[i] && B[i]+C[i] <= rem) {
      bs.push_back(B[i]);
      cs.push_back(C[i]);
    }
    sort(BEND(bs)); reverse(BEND(bs));
    sort(BEND(cs));

    int b = -1;
    int c = rem-b;
    int me = 0;
    int now = 0;
    while (b < 10000 && c > 0) {
      b++; c--;

      while (bs.back() <= b) {
	now++;
	bs.pop_back();
      }
      while (cs.back() > c) {
	now--;
	cs.pop_back();
      }
      setmax(me, now);
    }
    setmax(best, me);
    bs.clear();
    cs.clear();
  }

  printf("Case #%d: %d\n", ++cas, best);
    cerr << "ding" << endl;
}

int TESTS;
int main() {
  scanf("%d",&TESTS);
  FOR(i,TESTS) doit();
}
