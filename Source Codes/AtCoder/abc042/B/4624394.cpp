#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
#define ll long long int
bool a[100];

int main(){
  int n,l;
  cin >> n >> l;
  vector < string > s(n);
  for ( int i = 0; i < n; ++ i ) cin >> s[i];

  sort ( s.begin(), s.end() );
  for ( int i = 0; i < n; ++i ){
    cout << s[i];  
  }
  cout << endl;
  return 0;
}