#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,D,x[1100],y[1100];
int check(double k1){
	for (int i=1;i<=n;i++)
		if (k1>y[i]){
			double t=x[i]/(k1-y[i]);
			double dis=t*k1;
			if (dis<D) return 0;
		}
	return 1;
}
void solve(){
	scanf("%d%d",&D,&n);
	for (int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
	double l=0,r=1e20;
	for (int i=1;i<=200;i++){
		double mid=(l+r)/2;
		if (check(mid)) l=mid; else r=mid;
	}
	printf("%.11lf\n",(l+r)/2);
}
int main(){
	freopen("Al.in","r",stdin);
	freopen("Al.out","w",stdout);
	int t; scanf("%d",&t);
	for (int i=1;i<=t;i++){
		printf("Case #%d: ",i); solve();
	}
	return 0;
}
