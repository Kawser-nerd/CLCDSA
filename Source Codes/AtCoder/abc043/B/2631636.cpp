#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
  string b;
  cin >> b;

  vector<char> s;
  for( int i = 0; i < b.size(); i++ ) { 
    if( b[ i ] == 'B' ) { 
      if( s.size() != 0 ) {
        s.pop_back();
      }
    }
    else {
      s.push_back( b[ i ] );
    }
  }

  for( int i = 0; i < s.size(); i++ ) {
    cout << s[ i ];
  }
  cout << endl;

  return 0;
}