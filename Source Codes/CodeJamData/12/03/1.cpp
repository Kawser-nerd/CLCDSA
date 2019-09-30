#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <sstream>
#include <Windows.h>
//#include <boost/tokenizer.hpp>

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

int doit( FileReader& fin )
{
   int A = fin.readInt();
   int B = fin.readInt();

   int ten = 1;
   int D = 0;
   while ( ten <= A ) { ten *= 10; D++; }
   
   set<__int64> st;
   for ( int i = A; i <= B; i++ )
   {
      int n = i;
      for ( int k = 0; k < D; k++, n = (n+n%10*ten)/10 )
      {
         if ( n >= A && n < i )
         {
            st.insert( n * 100000000LL + i );
         }
      }
   }

   return (int) st.size();
}

void main()
{
   FileReader fin( "C-large.in" );
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