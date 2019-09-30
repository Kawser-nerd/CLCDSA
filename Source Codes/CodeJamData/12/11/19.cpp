#include<stdio.h>
#include<algorithm>
int n,m;
double p[200010],ans,now;
int main(){
	int _,t;
	scanf("%d",&_);
	for(t=1; t<=_; t++){
		scanf("%d%d",&n,&m);
		for(int i=0; i<n; i++)
			scanf("%lf",&p[i]);
		ans=m+2;
		now=1;
		for(int i=0; i<=n; i++){
			ans=std::min(ans,(n-i)+(m-i+1)+(1-now)*(m+1));
			now*=p[i];
		}
		printf("Case #%d: %.10lf\n",t,ans);
	}
	return 0;
}
