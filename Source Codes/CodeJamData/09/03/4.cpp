#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

const int MOD=10000;

char text[]="welcome to code jam";
char str[505];
int dp[505][25];
int N,L;


int main() {
	scanf("%d\n",&N);
	for(int t=1;t<=N;t++) {
		L=0;
		scanf("%c",&str[L]);
		while (str[L]!='\n') {
			L++;
			scanf("%c",&str[L]);
		}
		memset(dp,0,sizeof(dp));
		int ans=0;
		for(int i=0;i<L;i++) {
			if (str[i]=='w') {dp[i][0]=1;}
			for(int j=1;j<=18;j++) {
				if (str[i]==text[j]) {
					for(int k=0;k<i;k++) {
						dp[i][j]+=dp[k][j-1];
					}
					dp[i][j]%=MOD;
				}
			}
			ans=(ans+dp[i][18])%MOD;
		}
		ostringstream out;
		out << ans;
		string s=out.str();
		while (s.size()<4) {s="0"+s;}
		cout << "Case #" << t << ": " << s << endl;
		//printf("Case #%d: %d\n",t,ans);
	}

	return 0;
}
