// another fine solution by misof
// #includes {{{
#include <algorithm>
#include <numeric>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cassert>

#include <cmath>
#include <complex>
using namespace std;
// }}}

/////////////////// PRE-WRITTEN CODE FOLLOWS, LOOK DOWN FOR THE SOLUTION ////////////////////////////////

// pre-written code {{{
#define CLEAR(t) memset((t),0,sizeof(t))
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);++i)
#define FORD(i,a,b) for(int i=(int)(a);i>=(int)(b);--i)
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define SIZE(t) ((int)((t).size()))
vector<string> SPLIT( const string& s, const string& delim =" " ) { vector<string> res; string t; for ( unsigned int i = 0 ; i != s.size() ; i++ ) { if ( delim.find( s[i] ) != string::npos ) { if ( !t.empty() ) { res.push_back( t ); t = ""; } } else { t += s[i]; } } if ( !t.empty() ) { res.push_back(t); } return res; }
// }}}

/////////////////// CODE WRITTEN DURING THE COMPETITION FOLLOWS ////////////////////////////////

string poly;
int K, N;
int cnt[128][32];
int res[12][27][27][27][27];
bool treba[27][27][27][27];

#define MOD 10009

int main() {
  int T;
  cin >> T;
  FOR(ttt,1,T) {
    printf("Case #%d:",ttt);
    cin >> poly >> K >> N;
    CLEAR(cnt);
    CLEAR(treba);

   vector<string> S = SPLIT(poly,"+");
    REP(i,SIZE(S)) {
      int L = SIZE(S[i]);
      REP(ako,1<<L) {
        int z[4];
        REP(j,4) z[j]=0;
        int kde=3;
        FORD(j,SIZE(S[i])-1,0) if (ako & 1<<j) z[kde--] = S[i][j]-'a'+1;
        treba[ z[0] ][ z[1] ][ z[2] ][ z[3] ] = true;
      }
    }

    REP(n,N) {
      string word;
      cin >> word;
      REP(i,SIZE(word)) cnt[ n ][ word[i]-'a'+1 ]++;
    }
    CLEAR(res);
    res[0][0][0][0][0] = 1;
    FOR(d,1,K) {
      for (int v1=0; v1<=26; ++v1)
      for (int v2=v1; v2<=26; ++v2)
      for (int v3=v2; v3<=26; ++v3)
      for (int v4=v3; v4<=26; ++v4) {
        if (!treba[v1][v2][v3][v4]) continue;
        // vyhodnotime polynom v1*v2*v3*v4 pre vsetky d-tice slov
        int v[4];
        v[0]=v1; v[1]=v2; v[2]=v3; v[3]=v4;
        // vyskusame vsetky moznosti pre posledne slovo
//        if (v1==0 && v2==0 && v3==0 && v4==1) printf("a\n");
        REP(n,N) {
          REP(ako,16) {
            int koef = 1;
//            if (v1==0 && v2==0 && v3==0 && v4==1) cout << "  ako=" << ako << endl;
            int z[4];
            REP(i,4) z[i]=0;
            int kde=3;
            REP(i,4) {
              if (ako & 1<<i) {
                z[kde--] = v[3-i];
              } else {
//                if (v1==0 && v2==0 && v3==0 && v4==1) cout << "  nasobim koef " << cnt[n][ v[3-i] ] << endl;
                koef *= cnt[n][ v[3-i] ];
                koef %= MOD;
              }
            }
//            if (v1==0 && v2==0 && v3==0 && v4==1) printf("a n=%d ako=%d koef=%d\n",n,ako,koef);

            res[ d ][ v1 ][ v2 ][ v3 ][ v4 ] += koef * res[ d-1 ][ z[0] ][ z[1] ][ z[2] ][ z[3] ];
            res[ d ][ v1 ][ v2 ][ v3 ][ v4 ] %= MOD;
          }
        }
      }
      vector<string> S = SPLIT(poly,"+");
      int result = 0;
      REP(i,SIZE(S)) {
        int z[4];
        REP(j,4) z[j]=0;
        int kde=3;
        FORD(j,SIZE(S[i])-1,0) z[kde--] = S[i][j]-'a'+1;
        result += res[d][ z[0] ][ z[1] ][ z[2] ][ z[3] ];
        result %= MOD;
      }
      printf(" %d",result);
    }
    printf("\n");
    /*
    cout << "dbg " << res[1][0][5][8][23] << endl;
    cout << "dbg " << res[1][8][23][23][23] << endl;
    */
  }
  return 0;
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
