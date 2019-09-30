#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <sstream>
#include <Windows.h>
#include <boost/rational.hpp>
#include <boost/tokenizer.hpp>

using namespace std;

class FileReader : public ifstream
{
public:
   FileReader( const string& filename ) { open( filename.c_str(), ios_base::in ); }
   int readInt() { int x; *this >> x; return x; }
   vector<int> readInts( int n ) { vector<int> v(n); for ( int i = 0; i < n; i++ ) v[i] = readInt(); return v; }
   string readLine() { char buf[20000]; getline( buf, sizeof(buf) ); return buf; }
   //vector<string> readLines( int n ) { vector<string> v; for ( int i = 0; i < n; i++ ) v.push_back( readLine() ); return v; }
   string readString() { string x; *this >> x; return x; }
   vector<string> readStrings( int n ) { vector<string> v; for ( int i = 0; i < n; i++ ) v.push_back( readString() ); return v; }
   __int64 readInt64() { __int64 x; *this >> x; return x; }
};

//vector<string> parse( const string& s, const string& delimeters = " ,\t" )
//{
//   vector<string> ret;
//   boost::tokenizer<boost::char_separator<char>> tokens( s, boost::char_separator<char>( delimeters.c_str() ) );
//   copy( tokens.begin(), tokens.end(), back_inserter( ret ) );
//   return ret;
//}

class FileWriter : public ofstream
{
public:
   FileWriter( const string& filename ) { open( filename.c_str(), ios_base::out ); }
   //int writeInt() { int x; *this << x; return x; }
   //int writeString( const string& str ) { *this << str; }
};


typedef boost::rational<int> rat;

rat up( const rat& x )   { return rat( x.numerator()/x.denominator()+1 ); }
rat down( const rat& x ) { return rat( (x.numerator()-1)/x.denominator() ); }
rat abs( const rat& x )  { return rat( abs( x.numerator() ), x.denominator() ); }
rat isInt( const rat& x ){ return x.denominator() == 1; }
double toDouble( const rat& x ){ return (double)x.numerator()/x.denominator(); }

class XY
{
public:
   XY() : x(0), y(0) {}
   XY( const rat& x, const rat& y ) : x(x), y(y) {}   
   bool operator==( const XY& p ) const { return x==p.x && y==p.y; }
   bool operator!=( const XY& p ) const { return !(*this == p); }
   XY operator-( const XY& p ) const { return XY( x-p.x, y-p.y ); }   
   XY operator*( const rat& m ) const { return XY( x*m, y*m ); }   
   rat manhattanDist() const { return abs( x ) + abs( y ); }
   rat len2() const { return x*x + y*y; }
public:   
   rat x, y;
};


__int64 gcd( __int64 a, __int64 b ) { return a ? gcd( b%a, a ) : b; }

XY g_start;
XY nextBoundary( const XY& pos, const XY& dir )
{
   if ( pos != g_start )
   { 
      // check if we hit starting position
      XY d = g_start-pos;
      rat ratio = d.y != 0 ? dir.y / d.y : dir.x / d.x;
      if ( d * ratio == dir ) 
      {
         if ( ratio > 0 && d.manhattanDist() <= 1 )
            return g_start;
      }
   }

   XY bound0;
   XY bound1;
   if ( dir.x != 0 )
   {
      rat newX = dir.x > 0 ? up( pos.x ) : down( pos.x );
      rat newY = pos.y + (newX-pos.x)*(dir.y/dir.x);
      bound0 = XY( newX, newY );
   }
   if ( dir.y != 0 )
   {
      rat newY = dir.y > 0 ? up( pos.y ) : down( pos.y );
      rat newX = pos.x + (newY-pos.y)*(dir.x/dir.y);
      bound1 = XY( newX, newY );
   }
   if ( bound0 == XY() ) return bound1;
   if ( bound1 == XY() ) return bound0;
   return ( bound0 - pos ).manhattanDist() <= ( bound1 - pos ).manhattanDist() ? bound0 : bound1;
}

int doit( FileReader& fin )
{
   int SY = fin.readInt();
   int SX = fin.readInt();
   int D  = fin.readInt();
   vector<string> m = fin.readStrings( SY );
   
   for ( int y = 0; y < SY; y++ )
   for ( int x = 0; x < SX; x++ )
      if ( m[y][x] == 'X' )
         g_start = XY( x + rat(1,2), y + rat(1,2) );

   int ret = 0;
      
   for ( int dirX = -D; dirX <= D; dirX++ )
   for ( int dirY = -D; dirY <= D; dirY++ ) if ( gcd( abs(dirX), abs(dirY) ) == 1 )
   {
      if ( dirX*dirX + dirY*dirY > D*D ) continue;

      rat totalDist = 0;
      XY  dir = XY( dirX, dirY );
      XY  pos = g_start;

      rat distLimit = D*D * dir.manhattanDist()*dir.manhattanDist() / dir.len2();
      while ( 1 )
      {
         XY  newPos = nextBoundary( pos, dir );
         totalDist += ( newPos - pos ).manhattanDist();
         double dddd = toDouble(totalDist) * sqrt(toDouble(dir.len2())) / toDouble(dir.manhattanDist());
         if ( totalDist*totalDist > distLimit )
            break;

         if ( newPos == g_start )
         {
            ret++;
            break;
         }
         
         int newX = newPos.x.numerator() - (dir.x < 0);
         int newY = newPos.y.numerator() - (dir.y < 0);
         int oldX = newPos.x.numerator() - (dir.x > 0);
         int oldY = newPos.y.numerator() - (dir.y > 0);
         if ( !isInt( newPos.x ) ) { newX = oldX = newPos.x.numerator() / newPos.x.denominator(); }
         if ( !isInt( newPos.y ) ) { newY = oldY = newPos.y.numerator() / newPos.y.denominator(); }
         //if ( isInt( newPos.x ) && isInt( newPos.y ) )
         //{
            if ( m[newY][newX] == '#' )
            {
               if ( m[newY][oldX] == '#' ) dir.y = -dir.y;
               if ( m[oldY][newX] == '#' ) dir.x = -dir.x;
               if ( m[newY][oldX] != '#' && m[oldY][newX] != '#' )
                  break; // ray destroyed
            }
         //} 
         //else if ( isInt( newPos.x ) )
         //{
         //   int Y = ;
         //   if ( m[Y][newX] == '#' ) continue;
         //}

         pos = newPos;
      }
   }
      


   return ret;
}

void main()
{
   FileReader fin( "D-large.in" );
   FileWriter fout( "out.txt" );
   int T = fin.readInt();
   fin.readLine();
   for ( int i = 0; i < T; i++ )
   {
      stringstream ss;
      ss << "Case #" << i+1 << ": " << doit( fin ) << endl;
      fout << ss.str().c_str();
      OutputDebugStringA( ss.str().c_str() );
   }
}