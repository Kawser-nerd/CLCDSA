#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

double calc(vector<double> p){
	int n=p.size();
	vector<vector<double> > dp(n+1,vector<double>(n+1));
	dp[0][0]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			dp[i+1][j+1]+=dp[i][j]*p[i];
			dp[i+1][j]+=dp[i][j]*(1-p[i]);
		}
	}
	return dp[n][n/2];
}

main(){
	int testcases;
	scanf("%d",&testcases);
	for(int casenum=1;casenum<=testcases;casenum++){
		printf("Case #%d: ",casenum);
		int n,k;
		scanf("%d%d",&n,&k);
		vector<double> p(n);
		for(int i=0;i<n;i++)scanf("%lf",&p[i]);
		
		sort(p.begin(),p.end());
		
		double ans=0;
		
		for(int j=0;j<=k;j++){
			vector<double> tmp;
			for(int i=0;i<j;i++)tmp.push_back(p[i]);
			for(int i=n-(k-j);i<n;i++)tmp.push_back(p[i]);
			ans=max(ans,calc(tmp));
		}
		printf("%.10f\n",ans);
	}
}