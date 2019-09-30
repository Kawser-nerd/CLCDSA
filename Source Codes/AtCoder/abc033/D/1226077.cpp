#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
 
const double EPS = 1e-9, pi = acos(-1);

typedef long long ll;
 
struct Pt
{
  int x, y;
 
  Pt()
  : x(0), y(0)
  {}
 
  Pt( int x, int y )
  : x(x), y(y)
  {}
 
  Pt( const Pt &p )
  : x(p.x), y(p.y)
  {}
 
  Pt operator+ ( Pt p ) const
  { return Pt( x+p.x, y+p.y); }
 
  Pt operator- ( Pt p ) const
  { return Pt( x-p.x, y-p.y); }
 
  double operator*( Pt p ) const
  { return x*p.x+y*p.y; }
 
  Pt operator-() const
  { return Pt( -x, -y ); }
 
  double norm() const { return sqrt(x*x+y*y); }
 
  double ang( Pt p ) const
  { return (*this)*p/this->norm()/p.norm(); }

  double cross( Pt p ) const
  { return x*p.y-y*p.x; }
};
 
int N;
std::vector<Pt> pts;
 
int main()
{
  scanf( "%d", &N );
  rep( i, N )
  {
    int x, y;
    scanf( "%d%d", &x, &y );
 
    pts.push_back( Pt( x, y ) );
  }

  int cnt[3] = {0};
 
  rep( i, N )
  {
    std::vector<double> angs;

    rep( j , N )
    {
      if( i == j )
        continue;

      Pt v = pts[j] - pts[i];
      double theta = atan2( v.y, v.x );

      if( theta < 0 )
        theta += 2*pi;
      angs.push_back( theta );
      angs.push_back( theta+2*pi );
    }

    std::sort( angs.begin(), angs.end() );

    rep( j, N-1 )
    {
      auto x = std::upper_bound( angs.begin(), angs.end(), angs[j]+pi/2-EPS );
      auto y = std::upper_bound( x, angs.end(), angs[j]+pi/2+EPS );
      auto z = std::upper_bound( y, angs.end(), angs[j]+pi-EPS );

      cnt[1] += y-x;
      cnt[2] += z-y;
    }
  }
 
  rep( i, 3 )
    printf( "%d%c", i==0?(ll)N*(N-1)*(N-2)/6-cnt[1]-cnt[2]:cnt[i], i==2?'\n':' ' );
 
  return 0;
} ./Main.cpp:97:21: warning: format specifies type 'int' but the argument has type 'long long' [-Wformat]
    printf( "%d%c", i==0?(ll)N*(N-1)*(N-2)/6-cnt[1]-cnt[2]:cnt[i], i==2?'\n':' ' );
             ~~     ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
             %lld
1 warning generated.