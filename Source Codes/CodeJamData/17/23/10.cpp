#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
int b[110][110];
long long d[110][110];
int n,ss[110],e[110],q,pd[110];
double dis[110];
queue<int>Q;
double eps=1e-9;
double getans(int s,int t){
	for (int i=1;i<=n;i++) dis[i]=1e100;
	memset(pd,0x00,sizeof pd); dis[s]=0;
	Q.push(s); pd[s]=1;
	while (!Q.empty()){
		int k=Q.front(); Q.pop();
		for (int i=1;i<=n;i++)
			if (d[k][i]<=e[k]+eps&&dis[i]>eps+dis[k]+1.0*d[k][i]/ss[k]){
				dis[i]=dis[k]+1.0*d[k][i]/ss[k];
				if (pd[i]==0){
					Q.push(i); pd[i]=1;
				}
			}
		pd[k]=0;
	}
	return dis[t];
}
void solve(){
	scanf("%d",&n);
	scanf("%d",&q);
	memset(d,0x3f,sizeof d);
	for (int i=1;i<=n;i++) scanf("%d%d",&e[i],&ss[i]);
	for (int i=1;i<=n;i++){
		d[i][i]=0;
		for (int j=1;j<=n;j++){ scanf("%d",&b[i][j]); if (b[i][j]!=-1) d[i][j]=b[i][j];}
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			for (int k=1;k<=n;k++)
				d[j][k]=min(d[j][i]+d[i][k],d[j][k]);
	for (;q;q--){
		int k1,k2; scanf("%d%d",&k1,&k2);
		printf(" %.11lf",getans(k1,k2));
	}
	putchar('\n');
}
int main(){
	freopen("Cl.in","r",stdin);
	freopen("Cl.out","w",stdout);
	int t; scanf("%d",&t);
	for (int i=1;i<=t;i++){
		printf("Case #%d:",i); solve();
	}
	return 0;
}
