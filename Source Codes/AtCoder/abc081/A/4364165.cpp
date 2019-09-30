#include <string>
#include <iostream>

using namespace std;

int main(){
  string s;
  cin >> s;
  
  int ans = 0;
  if('1' == s[0]) ++ans;
  if('1' == s[1]) ++ans;
  if('1' == s[2]) ++ans;
  
  cout << ans << endl;
}