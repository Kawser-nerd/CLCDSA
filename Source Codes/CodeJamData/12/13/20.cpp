#include<stdio.h>
#include<algorithm>
#include<vector>
#include<stdlib.h>
#include<math.h>
#include<string.h>
using namespace std;
int n,ltim,s[6],p[6];
double tim[6*6];
bool dp[6*6][1<<6];

pair<double,int> pos[6],pos2[6];
bool valid(double tim,double nexttim,int mask){
	int L=0;
	for(int i=0; i<n; i++){
		pos[i]=make_pair(p[i]+tim*s[i],i);
		pos2[i]=make_pair(p[i]+nexttim*s[i],i);
	}
	sort(pos,pos+n);
	sort(pos2,pos2+n);
	vector<int> v1,v2,_v1,_v2;
	double prev1=-10,prev2=-10;
	for(int i=0; i<n; i++){
		if(mask&(1<<pos[i].second))
			v1.push_back(pos[i].second);
		else
			v2.push_back(pos[i].second);
		if(mask&(1<<pos2[i].second)){
			if(pos2[i].first-prev1<5)return false;
			prev1=pos2[i].first;
			_v1.push_back(pos2[i].second);
		}
		else{
			if(pos2[i].first-prev2<5)return false;
			prev2=pos2[i].first;
			_v2.push_back(pos2[i].second);
		}
	}
	return v1==_v1 && v2==_v2;
}

double poss[6];
bool flag[1<<6];
bool can_swap(int mask,int x){
	for(int i=0; i<n; i++)
		if(((mask>>i)&1)^((mask>>x)&1))
			if(fabs(poss[i]-poss[x])<5)
				return false;
	return true;
}
void dfs(int mask){
	if(flag[mask])return;
	flag[mask]=true;
	for(int i=0; i<n; i++)
		if(can_swap(mask,i))
			dfs(mask^(1<<i));
}
void trans(double tim,int mask){
	for(int i=0; i<n; i++)
		poss[i]=p[i]+tim*s[i];
	dfs(mask);
}
int main(){
	int _,t;char tmp[5];
	scanf("%d",&_);
	for(t=1; t<=_; t++){
		scanf("%d",&n);
		int mask=0;
		for(int i=0; i<n; i++){
			scanf("%s%d%d",tmp,&s[i],&p[i]);
			mask+=(*tmp=='R'?1<<i:0);
		}
		ltim=0;
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)if(s[i]<s[j] && p[i]>=p[j]+5)
				tim[ltim++]=(p[i]-p[j]-5.)/(s[j]-s[i]);
		sort(tim,tim+ltim);
		ltim=unique(tim,tim+ltim)-tim;
		tim[ltim]=10000000;
		memset(dp,0,sizeof(dp));
		dp[0][mask]=true;
		int ans=0;
		for(int i=0; i<ltim; i++)
			for(int mask=0; mask<(1<<n); mask++)if(dp[i][mask]){
				memset(flag,0,sizeof(flag));
				trans(tim[i],mask);
				for(int mask2=0; mask2<(1<<n); mask2++)if(flag[mask2]&&valid(tim[i],tim[i+1],mask2)){
					dp[i+1][mask2]=true;
//					printf("%.4lf ",tim[i+1]);
//					for(int q=0; q<n; q++)printf("%c ",mask2&(1<<q)?'R':'L');puts("");
					ans=i+1;
				}
			}
		printf("Case #%d: ",t);
		if(ans==ltim)puts("Possible");else
			printf("%.10lf\n",tim[ans]);
	}
	return 0;
}
