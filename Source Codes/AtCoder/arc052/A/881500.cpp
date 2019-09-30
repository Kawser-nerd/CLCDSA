#include <iostream>
#include <string>
using namespace std;
int main()
{
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  int ret = 0;
  for( int i=0; i<s.size(); i++ ){
    if( s[i] >= '0' && s[i] <= '9' ){
      ret = ret * 10 + s[i] - '0';
    }
  }
  cout << ret << endl;
}