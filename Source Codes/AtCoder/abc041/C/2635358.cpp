#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int n;
  cin >> n;

  vector< pair<int, int> > v;
  for( int i = 0; i < n; i++ ) {
    int t;
    cin >> t;
    v.push_back( make_pair( t, i + 1 ) );
  }

  sort( v.begin(), v.end(), greater<pair<int, int>>() );

  for( int i = 0; i < v.size(); i++ ) {
    cout << v[ i ].second << endl;
  }

  return 0;
}