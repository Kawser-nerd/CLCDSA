#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class bigint {
   static const int BASE = 10000;
   int sign;
   vector< int > limbs;
   bigint &trim()
   { while ( limbs.size() > 0 && limbs.back() == 0 ) limbs.pop_back(); if ( limbs.size()
                                                                            == 0 ) sign = 1; return *this; }
   int operator[]( const size_t index ) const
   { return index >= limbs.size() ? 0 : limbs[index]; }
   // ternarni predikat za usporedivanje
   static int cmp( const bigint &a, const bigint &b )
   {
      if ( a.sign != b.sign ) return a.sign;
      if ( a.limbs.size() < b.limbs.size() ) return -a.sign;
      if ( a.limbs.size() > b.limbs.size() ) return a.sign;
      for ( int i=(int)a.limbs.size()-1; i>=0; --i ) {
         if ( a.limbs[i] < b.limbs[i] ) return -a.sign;
         if ( a.limbs[i] > b.limbs[i] ) return a.sign;
      }
      return 0;
   }
   // oduzimanje kad je ( a.sign == b.sign == 1 ) && a >= b
   static bigint absolute_subtract( const bigint &a, const bigint &b )
   {
      int borrow = 0;
      bigint ret;
      for ( int i=0; i<(int)a.limbs.size(); ++i ) {
         ret.limbs.push_back( a.limbs[i] - b[i] - borrow );
         if ( ret.limbs[i] < 0 ) {
            ret.limbs[i] += BASE;
            borrow = 1;
         }
         else borrow = 0;
      }
      return ret.trim();
   }
   // zbrajanje kad je ( a.sign == b.sign == 1 )
   static bigint absolute_add( const bigint &a, const bigint &b )
   {
      int maxi = max( a.limbs.size(), b.limbs.size() );
      int carry = 0;
      bigint ret;
      for ( int i=0; i<maxi; ++i ) {
         ret.limbs.push_back( a[i] + b[i] + carry );
         if ( ret.limbs[i] >= BASE ) {
            ret.limbs[i] -= BASE;
            carry = 1;
         }
         else carry = 0;
      }
      ret.limbs.push_back( carry );
      return ret.trim();
   }
   // pomocne operacije za ++ i --
   bigint &absolute_inc( void )
   {
      int i;
      for ( i=0; i<(int)limbs.size() && limbs[i] == BASE-1; ++i )
         limbs[i] = 0;
      if ( i == (int)limbs.size() ) limbs.push_back( 0 );
      ++limbs[i];
      return *this;
   }
   bigint &absolute_dec( void )
   {
      int i;
      for ( i=0; i<(int)limbs.size() && limbs[i] == 0; ++i )
         limbs[i] = BASE-1;
      if ( i == (int)limbs.size() ) limbs.push_back( 1 );
      --limbs[i];
      return trim();
   }
   bigint &multiply_and_add( const bigint &b, int s, int offset )
   {
      int carry = 0;
      int i;
      for ( i=0; i<(int)b.limbs.size(); ++i ) {
         while ( (int)limbs.size() <= offset+i ) limbs.push_back( 0 );
         limbs[ offset+i ] += b.limbs[i] * s + carry;
         carry = limbs[ offset+i ] / BASE;
         limbs[ offset+i ] %= BASE;
      }
      for ( ; carry > 0; ++i ) {
         while ( (int)limbs.size() <= offset+i ) limbs.push_back( 0 );
         limbs[ offset+i ] += carry;
         carry = limbs[ offset+i ] / BASE;
         limbs[ offset+i ] %= BASE;
      }
      return trim();
   }
   static void binary_search_div( const bigint &a, const bigint &b, bigint &quo, bigint
                                  &rem )
   {
      rem.limbs.clear();
      quo.limbs.resize( a.limbs.size() );
      for ( int i=(int)a.limbs.size()-1; i>=0; --i ) {
         rem.limbs.insert( rem.limbs.begin(), a[i] ); // rem = rem * BASE + a[i]
         int lo = 0, hi = BASE-1;
         while ( lo < hi ) {
            int mid = ( lo + hi ) / 2 + 1;
            bigint key = b * mid;
            if ( key.sign == -1 ) key.negate();
            int r = cmp( rem, key );
            if ( r >= 0 ) { lo = mid; }
            else if ( r < 0 ) { hi = mid-1; }
         }
         quo.limbs[i] = lo;
         rem = rem - b * lo;
         if ( rem.limbs.size() > 0 && rem.sign == -1 ) rem = rem + b;
      }
      quo.sign = a.sign * b.sign;
      quo.trim();
   }
public:
   bigint() { sign = 1; } // default
   bigint( const bigint &drugi ) { *this = drugi; } //
   bigint( const string &str )
   {
      int rank = 1;
      int limb = 0;
      sign = 1;
      for ( int i=(int)str.size()-1; i>=0; --i ) {
         if ( str[i] == '-' ) { sign=-1; break; }
         limb += ( str[i] - '0' ) * rank;
         if ( ( rank *= 10 ) == BASE ) {
            limbs.push_back( limb );
            limb = 0; rank = 1;
         }
      }
      if ( limb != 0 ) limbs.push_back( limb );
      trim();
   }
   // int konstruktor
   bigint( int x )
   {
      sign = x < 0 ? -1 : 1;
      while ( x != 0 ) {
         limbs.push_back( x % BASE * sign );
         x /= BASE;
      }
   }
   // mijenja predznak
   bigint &negate()
   {
      sign = -sign;
      return *this;
   }
   friend inline bool operator<( const bigint &a, const bigint &b )
   { return cmp( a, b ) < 0; }
   friend inline bool operator>( const bigint &a, const bigint &b )
   { return cmp( a, b ) > 0; }
   friend inline bool operator<=( const bigint &a, const bigint &b )
   { return cmp( a, b ) <= 0; }
   friend inline bool operator>=( const bigint &a, const bigint &b )
   { return cmp( a, b ) >= 0; }
   friend inline bool operator==( const bigint &a, const bigint &b )
   { return cmp( a, b ) == 0; }
   friend inline bool operator!=( const bigint &a, const bigint &b )
   { return cmp( a, b ) != 0; }
   // zbrajanje bigintova
   friend bigint operator+( const bigint &a, const bigint &b )
   {
      if ( a.sign == b.sign ) {
         bigint ret = absolute_add( a, b );
         ret.sign = a.sign;
         return ret;
      }
      else {
         if ( a.sign == -1 ) {
            bigint nega = -a;
            if ( nega > b ) return absolute_subtract( nega, b ).negate();
            else return absolute_subtract( b, nega );
         }
         else {
            bigint negb = -b;
            if ( negb > a ) return absolute_subtract( negb, a ).negate();
            else return absolute_subtract( a, negb );
         }
      }
   }
   // unarni minus i oduzimanje
   friend bigint operator-( const bigint &b )
   {
      bigint ret( b );

      ret.negate();
      return ret;
   }
   friend bigint operator-( const bigint &a, const bigint &b )
   { return a + (-b); }
   // mnozenje
   friend bigint operator*( const bigint &a, const bigint &b )
   {
      bigint ret;
      for ( int i=0; i<(int)b.limbs.size(); ++i )
         ret.multiply_and_add( a, b[i], i );
      ret.sign = a.sign * b.sign;
      return ret.trim();
   }
   // dijeljenje sa intom
   friend bigint operator/( const bigint &a, int s )
   {
      if ( s >= BASE ) return a / bigint( s );
      int rem = 0;
      bigint ret;
      ret.limbs.resize( a.limbs.size() );
      ret.sign = a.sign;
      if ( s < 0 ) { ret.sign = -ret.sign; s = -s; }
      for ( int i=(int)a.limbs.size()-1; i>=0; --i ) {
         rem = rem * BASE + a.limbs[i];
         ret.limbs[i] = rem / s;
         rem %= s;
      }
      return ret.trim();
   }
   friend int operator%( const bigint &a, int s )
   {
      if ( s >= BASE ) ( a % bigint( s ) ).toInt();
      int rem = 0;
      int sign = a.sign;
      if ( s < 0 ) { s = -s; }
      for ( int i=(int)a.limbs.size()-1; i>=0; --i ) {
         rem = ( rem * BASE + a.limbs[i] ) % s;
      }
      return rem * sign;
   }
   // dijeljenje bigintova
   friend bigint operator/( const bigint &a, const bigint &b )
   {
      bigint quo, rem;
      binary_search_div( a, b, quo, rem );
      return quo;
   }
   friend bigint operator%( const bigint &a, const bigint &b )
   {
      bigint quo, rem;
      binary_search_div( a, b, quo, rem );
      return rem;
   }
   // inkrement i dekrement
   friend bigint &operator++( bigint &b )
   {
      if ( b.limbs.size() == 0 ) { b.sign = 1; return b.absolute_inc(); }
      if ( b.sign == 1 ) return b.absolute_inc();
      else return b.absolute_dec();
   }
   friend bigint operator++( bigint &b, int )
   { bigint ret( b ); ++b; return ret; }
   friend bigint &operator--( bigint &b )
   {
      if ( b.limbs.size() == 0 ) { b.sign = -1; return b.absolute_inc(); }

      if ( b.sign == -1 ) return b.absolute_inc();
      else return b.absolute_dec();
   }
   friend bigint operator--( bigint &b, int )
   { bigint ret( b ); --b; return ret; }
   friend ostream& operator<<( ostream &os, const bigint &a )
   {
      if ( a.limbs.size() == 0 ) os << '0';
      else {
         if ( a.sign == -1 ) os << '-';
         for ( int i=(int)a.limbs.size()-1; i>=0; --i ) {
            if ( i < (int)a.limbs.size()-1 )
               for ( int pad=bigint::BASE/10; pad>a.limbs[i] && pad>1; pad/=10 )
                  os << '0';
            os << a.limbs[i];
         }
      }
      return os;
   }
   int toInt() const
   {
      int ret = 0;
      for ( int i=(int)limbs.size()-1; i>=0; --i )
         ret = ret * BASE + limbs[i] * sign;
      return ret;
   }
   friend bigint abs( const bigint &a ) {
      bigint ret( a );
      if ( ret.sign == -1 ) ret.sign = 1;
      return ret;
   }
};


int year, n;
vector<int> tour[51];

bigint dp[51];
bigint total[51];

bigint gcd( bigint a, bigint b ) { return b == 0 ? a : gcd( b, a%b ); }

int main( void ) {
   int T;
   cin >> T;
   for( int tt = 1; tt <= T; ++tt ) {
      int mx = 0;
      cin >> year >> n;
      for( int i = 1; i <= n; ++i ) {
         int rounds;
         cin >> rounds;
         tour[i].push_back( 0 );
         for( int j = 1; j < rounds; ++j ) {
            int x;
            cin >> x;
            tour[i].push_back( x-1 );
            mx = max( mx, tour[i].back() );
         }
      }

      for( int i = 0; i <= n; ++i ) total[i] = 0;
      
      for( int day = 0; day < year; ++day ) {
         for( int i = 0; i <= n; ++i ) 
            dp[i] = 0;
         dp[0] = 1;
         for( int i = 1; i <= n; ++i ) {
            int hi = upper_bound( tour[i].begin(), tour[i].end(), day ) - tour[i].begin();
            for( int j = i; j >= 0; --j ) {
               if( j == 0 ) {
                  dp[j] = dp[j] * (year-hi);
               } else {
                  dp[j] = dp[j-1] * hi + dp[j] * (year-hi);
               }
            }
         }

         if( day > mx ) {
            for( int i = 0; i <= n; ++i ) 
               total[i] = total[i] +  dp[i] * (year-day);
            break;
         } else {
            for( int i = 0; i <= n; ++i )
               total[i] = total[i] + dp[i];
         }
      }

      bigint A = 0;
      for( int i = 1; i <= n; ++i ) A = A + i*i*total[i];
      bigint B = 1;
      for( int i = 1; i <= n; ++i ) B = B * year;

      //      cerr << A << " " << B << endl;
      
      bigint G = gcd( A, B );
      A = A / G;
      B = B / G;

      cout << "Case #" << tt << ": ";
      cout << A/B << "+";
      cout << A%B << "/";
      cout << B << endl;
      //      printf( "%.10lf\n", (double)A/B );

      for( int i = 0; i <= n; ++i ) tour[i].clear();
   }
   
   return 0;
}
