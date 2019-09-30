#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

typedef long long Int;


int main(){
	Int n, dp[19][19][19];
	string str;
	Int cnt = 0;
	cin >> n;
	cin >> str;
	
	for(Int i = 0;i < (1 << n);i++){
		string a,b;
		for(Int j = 0;j < n;j++){
			if((i >> j) % 2 == 1)a += str[j];
			else b += str[j];
		}
		dp[0][0][0] = 1;
		for(Int i = 0;i <= n;i++){
			for(Int j = 0;j <= a.size();j++){
				for(Int k = 0;k <= b.size();k++){
					Int &res = dp[i][j][k];
					if(i == 0 && j == 0 && k == 0){res = 1;continue;}
					if(i == 0){res = 0;continue;}
					res = 0;
					if(j > 0 && str[n+i-1] == a[a.size() - j]){
						res += dp[i-1][j-1][k];
					}
					if(k > 0 && str[n+i-1] == b[b.size() - k]){
						res += dp[i-1][j][k-1];
					}
				}
			}
		}
		cnt += dp[n][a.size()][b.size()];
	}

	cout << cnt << endl;
	return 0;
}