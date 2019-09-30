#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <functional>
#include <iostream>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int n,m;
ll dp[3001][3001];
string str;
int nex[3001];
int cnt[3001];

int main(void){
	scanf("%d%d",&n,&m);
	cin >> str;
	for(int i=0;i<n;i++){
		cnt[i+1]+=cnt[i];
		if(str[i]=='1')cnt[i+1]++;
	}
	memset(nex,-1,sizeof(nex));
	for(int i=0;i<m;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		l--;
		nex[l]=max(nex[l],r);
	}
	dp[0][0]=1;
	int r=-1;
	for(int i=0;i<n;i++){
		r=max(nex[i],r);
		for(int j=0;j<=i;j++){
			if(r<=i){
				if(str[i]=='0'){
					dp[i+1][j]=(dp[i+1][j]+dp[i][j])%MOD;
				}else{
					dp[i+1][j+1]=(dp[i+1][j+1]+dp[i][j])%MOD;
				}
			}else{
				if(j<cnt[r]){
					dp[i+1][j+1]=(dp[i+1][j+1]+dp[i][j])%MOD;
				}
				if(i-j<r-cnt[r]){
					dp[i+1][j]=(dp[i+1][j]+dp[i][j])%MOD;
				}
			}
		}
	}
	printf("%lld\n",dp[n][cnt[n]]);
	return 0;
}