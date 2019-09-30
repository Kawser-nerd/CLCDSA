#include <string>
#include <iostream>

using namespace std;
long long int dp[200005];
int main(){
  string s;
  cin >> s;
  int ct[256];
  for(int i=0;i<256;i++) ct[i] = 0;
  dp[0] = 1;
  ct[s[0]]++;
  for(int i=1;i<s.length();i++){
    dp[i] = (i - ct[s[i]]) + dp[i-1];
    ct[s[i]]++;
  }
  cout << dp[s.length()-1] << endl;
  return 0;
}