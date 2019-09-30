#include<iostream>
#include<algorithm>

using namespace std;
typedef long long Int;
Int dp[52][52][52];
Int a[52], b[52];
Int res;
bool oks[52][52];

int main(){
	Int n;

	for(Int i = 0;i <= 51;i++){
		for(Int j = 0;j <= 51;j++){
			for(Int k = 0;k <= 51;k++){
				if(i == j)dp[i][j][k] = 1;
				if(k == 0)continue;
				dp[i][j][k] |= dp[i][j][k-1];
				dp[i][j][k] |= dp[i%k][j][k];
			}
		}
	}
	cin >> n;
	for(Int i = 0;i < n;i++){
		cin >> a[i];
		oks[i][a[i]] = true;
	}
	for(Int i = 0;i < n;i++)cin >> b[i];
	for(Int k = 51;k >= 1;k--){
		Int ok = 0;
		
		for(Int i = 0;i < n;i++){
			Int notok = 1;
			for(Int j = 0;j <= 51;j++){
				if(oks[i][j] && dp[j][b[i]][k-1])notok = 0;
			}
			if(notok == 1)ok = 1;
		}
		if(ok){
			for(Int i = 0;i < n;i++){
				for(Int j = 0;j < k;j++){
					for(Int l = j;l <= 51;l += k){
						oks[i][j] |= oks[i][l];
					}
				}
			}
		}
		if(k == 51 && ok){
			cout << -1 << endl;
			return 0;
		}
		res += ok << k;
	}
	cout << res << endl;
	return 0;
}