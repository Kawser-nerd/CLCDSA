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
#define N 514
void build(){

}
LL n , p , r[ N ] , c[ N ][ N ];
void init(){
  n = getint();
  p = getint();
  for( int i = 0 ; i < n ; i ++ )
    r[ i ] = getint();
  for( int i = 0 ; i < n ; i ++ )
    for( int j = 0 ; j < p ; j ++ )
      c[ i ][ j ] = getint();
}
vector< pair<LL,LL> > cand[ N ];
LL ptr[ N ];
void solve(){
  for( int i = 0 ; i < n ; i ++ )
    cand[ i ].clear();
  for( int j = 0 ; j < p ; j ++ ){
    for( int i = 0 ; i < n ; i ++ ){
      LL al = 0 , ar = 1000000;
      {
        LL bst = -1;
        LL exp = c[ i ][ j ] * 10 / 9 / r[ i ];
        for( LL dlt = -1000 ; dlt <= 1000 ; dlt ++ ){
          LL now = exp + dlt;
          if( now < 0 ) continue;
          if( now * r[ i ] * 9  <= c[ i ][ j ] * 10 and
              now * r[ i ] * 11 >= c[ i ][ j ] * 10 )
          bst = max( bst , now );
        }
        ar = min( ar , bst );
      }
      {
        LL bst = 1000001;
        LL exp = c[ i ][ j ] * 10 / 11 / r[ i ];
        for( LL dlt = -1000 ; dlt <= 1000 ; dlt ++ ){
          LL now = exp + dlt;
          if( now < 0 ) continue;
          if( now * r[ i ] * 9  <= c[ i ][ j ] * 10 and
              now * r[ i ] * 11 >= c[ i ][ j ] * 10 )
          bst = min( bst , now );
        }
        al = max( al , bst );
      }
      if( al > ar ) break;
      cand[ i ].push_back( { al , ar } );
    }
  }
  LL ans = 0;
  for( int i = 0 ; i < n ; i ++ ){
    ptr[ i ] = 0;
    sort( cand[ i ].begin() , cand[ i ].end() );
  }
  while( true ){
    bool gg = false;
    LL tcand = 0;
    for( int i = 0 ; i < n ; i ++ )
      if( ptr[ i ] >= (int)cand[ i ].size() ){
        gg = true;
        break;
      }else{
        tcand = max( tcand , cand[ i ][ ptr[ i ] ].first );
      }
    if( gg ) break;
    gg = false;
    for( int i = 0 ; i < n ; i ++ )
      if( tcand > cand[ i ][ ptr[ i ] ].second ){
        ptr[ i ] ++;
        gg = true;
      }
    if( gg ) continue;
    ans ++;
    for( int i = 0 ; i < n ; i ++ )
      ptr[ i ] ++;
  }  
  printf( "Case #%d: %lld\n" , ++ _cs , ans );
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
