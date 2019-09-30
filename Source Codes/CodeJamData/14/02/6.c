#include<stdio.h>

int main(int argc,char*argv[]){
	int a,t,t2;
	double c,f,x,ans,lastfarm,currfarm,currrate;
	scanf("%d",&t);
	for(t2=1;t2<=t;t2++){
		scanf("%lf%lf%lf",&c,&f,&x);
		ans=x/2;
		currrate=2;
		lastfarm=0;
		for(a=1;a<=x;a++){
			currfarm=lastfarm+c/currrate;
			currrate+=f;
			if(ans>currfarm+x/currrate)ans=currfarm+x/currrate;
			lastfarm=currfarm;
		}
		printf("Case #%d: %.7lf\n",t2,ans);
	}
	return 0;
}
