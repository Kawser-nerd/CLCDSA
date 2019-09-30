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
#define N 33
void build(){

}
int r , c;
char a[ N ][ N ];
void init(){
  r = getint();
  c = getint();
  for( int i = 0 ; i < r ; i ++ )
    scanf( "%s" , a[ i ] );
}
void solve(){
  for( int i = 0 ; i < r ; i ++ ){
    char pc = '?';
    for( int j = 0 ; j < c ; j ++ )
      if( a[ i ][ j ] == '?' )
        a[ i ][ j ] = pc;
      else
        pc = a[ i ][ j ];
    pc = '?';
    for( int j = c - 1 ; j >= 0 ; j -- )
      if( a[ i ][ j ] == '?' )
        a[ i ][ j ] = pc;
      else
        pc = a[ i ][ j ];
  }
  for( int i = 1 ; i < r ; i ++ )
    for( int j = 0 ; j < c ; j ++ )
      if( a[ i ][ j ] == '?' )
        a[ i ][ j ] = a[ i - 1 ][ j ];
  for( int i = r - 2 ; i >= 0 ; i -- )
    for( int j = 0 ; j < c ; j ++ )
      if( a[ i ][ j ] == '?' )
        a[ i ][ j ] = a[ i + 1 ][ j ];
  printf( "Case #%d:\n" , ++ _cs );
  for( int i = 0 ; i < r ; i ++ )
    puts( a[ i ] );
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
