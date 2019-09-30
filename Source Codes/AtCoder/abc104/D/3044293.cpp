#include <iostream>

using namespace std;

string S;
typedef long long ll;
ll dp[100010][4];

int main() {
   int mod = 1000000007;
   cin >> S;
   int N = S.size();
   for (int i=N;i>=0;i--) {
      for (int j=3;j>=0;j--) {
	 if (i==N) {
	    dp[i][j] = (j==3?1:0);
	 } else {
	    dp[i][j] = dp[i+1][j] * (S[i] == '?' ? 3LL : 1LL);
	    if (j<3&&(S[i]=='?'||S[i]=="ABC"[j])) {
	       dp[i][j] += dp[i+1][j+1];
	    }
	    dp[i][j] %= mod;
	 }
      }
   }
   cout << dp[0][0] << endl;
   
   return 0;

}