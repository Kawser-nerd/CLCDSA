// eddy1021
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
#define mod9 1000000009LL
#define mod7 1000000007LL
#define INF  1023456789LL
#define INF16 10000000000000000LL
#define eps 1e-9
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
#ifndef ONLINE_JUDGE
#define debug(...) printf(__VA_ARGS__)
#else 
#define debug(...)
#endif
inline LL getint(){
  LL _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}
inline LL add( LL _x , LL _y , LL _mod = mod7 ){
  _x += _y;
  return _x >= _mod ? _x - _mod : _x;
}
inline LL sub( LL _x , LL _y , LL _mod = mod7 ){
  _x -= _y;
  return _x < 0 ? _x + _mod : _x;
}
inline LL mul( LL _x , LL _y , LL _mod = mod7 ){
  _x *= _y;
  return _x >= _mod ? _x % _mod : _x;
}
LL mypow( LL _a , LL _x , LL _mod ){
  if( _x == 0 ) return 1LL;
  LL _ret = mypow( mul( _a , _a , _mod ) , _x >> 1 , _mod );
  if( _x & 1 ) _ret = mul( _ret , _a , _mod );
  return _ret;
}
LL mymul( LL _a , LL _x , LL _mod ){
  if( _x == 0 ) return 0LL;
  LL _ret = mymul( add( _a , _a , _mod ) , _x >> 1 , _mod );
  if( _x & 1 ) _ret = add( _ret , _a , _mod );
  return _ret;
}
inline bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
#define Bye exit(0)
int __ = 1 , _cs;
/*********default*********/
void build(){

}
LL hd , ad , hk , ak , b , d;
void init(){
  hd = getint();
  ad = getint();
  hk = getint();
  ak = getint();
  b  = getint();
  d  = getint();
}
void solve(){
  LL ans = -1;
  for( LL i = 0 ; i <= ak / max( 1ll , d ) + 1 ; i ++ )
    for( LL j = 0 ; j <= 100 ; j ++ ){
      LL rnd = 0;
      LL thd = hd , tad = ad , thk = hk , tak = ak;
      if( thd <= tak - d ) continue;
      bool gg = false;
      LL tk = 0;
      for( LL k = 0 ; k < i ; k ++ ){
        if( thd <= tak - d ) thd = hd , k --; // cure
        else tak = max( tak - d , 0ll ); // debuff
        thd -= tak;
        ++ rnd;
        if( ++ tk > i + i ){
          gg = true;
          break;
        }
      }
      if( gg ) continue;
      tk = 0;
      for( LL k = 0 ; k < j ; k ++ ){
        if( thd <= tak ) thd = hd , k --; // cure
        else tad = tad + b; // buff
        thd -= tak;
        ++ rnd;
        if( ++ tk > j + j ){
          gg = true;
          break;
        }
      }
      if( gg ) continue;
      set< tuple<LL,LL,LL,LL> > S;
      S.insert( make_tuple( thd , tad , thk , tak ) );
      while( thk > 0 ){
        if( thk <= tad ){
          ++ rnd;
          break;
        }
        if( thd <= tak ) thd = hd; // cure
        else thk -= tad; // attack
        thd -= tak;
        if( S.count( make_tuple( thd , tad , thk , tak ) ) ){
          gg = true;
          break;
        }
        S.insert( make_tuple( thd , tad , thk , tak ) );
        ++ rnd;
      }
      if( gg ) continue;
      if( ans == -1 or rnd < ans )
        ans = rnd;
    }
  printf( "Case #%d: " , ++_cs );
  if( ans == -1 ) puts( "IMPOSSIBLE" );
  else printf( "%lld\n" , ans );
}
int main(){
  build();
  __ = getint();
  while( __ -- ){
    clock_t s = clock();
    init();
    solve();
    clock_t t = clock();
    fprintf( stderr , "Solved case #%d in %.6f\n" ,
             _cs , (double)(t - s)/CLOCKS_PER_SEC );
    fflush( stderr );
  }
}
