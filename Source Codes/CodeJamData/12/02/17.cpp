#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <assert.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <deque>
#include <math.h>

#define FOR(i,a,b) for (int i=(a); i<(b); ++i)
#define FORZ(i,b) FOR(i,0,(b))
#define mp make_pair
#define pb push_back
#define all(v) (v).begin( ), (v).end( )
#define _(a,b) memset( a, b, sizeof( a ) )
using namespace std;

template <class T> void out( T a, T b ) { bool first = true; for( T i = a; i != b; ++ i ) { if( !first ) printf( " " ); first = false; cout << * i; } printf( "\n" ); }
template <class T> void outl( T a, T b ) { for( T i = a; i != b; ++ i ) { cout << * i << "\n"; } }
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef map<string,int> msi;

int main() {
  int tt;
  cin >> tt;
  FOR(t,1,tt+1) {
    printf("Case #%d: ", t);
    int N, S, p;
    cin >> N >> S >> p;
    int ans = 0;
    FOR(i,0,N) {
      int t;
      cin >> t;
      if (t % 3 == 0) {
        if (t/3 >= p) {
          ans++;
        } else if (t > 0 && t < 30 && t/3 + 1 >= p && S > 0) {
          ans++;
          S--;
        }
      } else if (t % 3 == 1) {
        if (t/3 + 1 >= p) {
          ans++;
        }
      } else {
        if (t/3 + 1 >= p) {
          ans++;
        } else if (t < 29 && t/3 + 2 >= p && S > 0) {
          ans++;
          S--;
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
