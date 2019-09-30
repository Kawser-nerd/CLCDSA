#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;

#define X first
#define Y second
#define MP make_pair
#define PB push_back
typedef long long ll;
typedef double D;
typedef long double ld;
typedef vector<int> VI;
typedef pair<int,int> PII;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(VAR(i,a);i<=(b);++i)
#define FORD(i,a,b) for(VAR(i,a);i>=(b);--i)
#define FORE(a,b) for(VAR(a,(b).begin());a!=(b).end();++a)
#define VAR(a,b) __typeof(b) a=(b)
#define SIZE(a) ((int)((a).size()))
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,a) memset(x,a,sizeof(x))
int COND = 0;
#define DB(x) { if (COND) { cerr << __LINE__ << " " << #x << " " << x << endl; } }
#define SZ 1111

ll A[SZ];
ll B[SZ];

int main(int argc, char **argv) {
  COND = argc >= 2 && argv[1][0] == 'q';
  int t;
  cin >> t;
  FOR (mycase, 1, t) {
    int  n;
    cin >> n;
    REP (j, n) cin >> A[j];
    REP (j, n) cin >> B[j];
    sort(A, A + n);
    sort(B, B + n);
    reverse(B, B + n);
    ll val = 0;
    REP (i, n) val += A[i] * B[i];
    printf("Case #%d: %lld\n", mycase, val);

  }

    
  return 0;
}
