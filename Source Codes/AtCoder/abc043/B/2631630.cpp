#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
  string buf;
  cin >> buf;

  vector<char> s;
  for( int i = 0; i < buf.size(); i++ ) {
    if( buf[ i ] == 'B' ) {
      if( s.size() != 0 ) {
        s.pop_back();
      }
    }
    else {
      s.push_back( buf[ i ] );
    }
  }

  for( int i = 0; i < s.size(); i++ ) {
    cout << s[ i ];
  }
  cout << endl;

  return 0;
}