#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
 
int main()
{
  string w;
  cin >> w;
  sort( w.begin(), w.end() );
  int s = 0;
  for( int i = 0; i < w.size(); i += 2 ) {
    s += w[ i + 1 ] - w[ i ];
  }
 
  cout << ( s ? "No" : "Yes" ) << endl;
  return 0;
}