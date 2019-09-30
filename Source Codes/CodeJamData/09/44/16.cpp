#include<cstdio>
#include<cmath>
#include<algorithm>
#define L 100

using namespace std;


int T,n,i,x[L],y[L],r[L],I;
double ans;

double calc(int a,int b,int c){
	ans=max(r[b],r[c])*2;
	ans=max(ans,r[b]+r[c]+sqrt((x[b]-x[c])*(x[b]-x[c])+(y[b]-y[c])*(y[b]-y[c])));
	ans=max(ans/2,(double)r[a]);
	return ans;
}

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for (i=0;i<n;++i)
			scanf("%d%d%d",&x[i],&y[i],&r[i]);
		if (n==1) ans=r[0];
		else if (n==2){
			ans=max(r[0],r[1]);
		}
		else if (n==3){
			ans=calc(0,1,2)<?calc(1,0,2)<?calc(2,0,1);
		}
		printf("Case #%d: %.10lf\n",++I,ans);
	}
}
