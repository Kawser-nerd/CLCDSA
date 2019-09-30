#include<stdio.h>

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

long long absb(long long a){
	if(a<0)a=a*(-1);
	return a;
}

int main(){
	int a,b,q,i,y,j;
	long long s[100000],t[100000],x[100000],ans[100000];
	scanf("%d%d%d",&a,&b,&q);
	for(i=0;i<a;i++)scanf("%lld",&s[i]);
	for(i=0;i<b;i++)scanf("%lld",&t[i]);
	for(i=0;i<q;i++)scanf("%lld",&x[i]);
	for(y=0;y<q;y++){
		int al=-1,au=a,bl=-1,bu=b;
		if(a>1){while(au-al>1){
			int mid=(al+au)/2;
			if(s[mid]>=x[y])au=mid;
			else al=mid;
		}}
		else al=au=0;
		if(a>1&&au==0&&al==-1)al=0;
		if(a>1&&al==a-1&&au==a)au=a-1;
		if(b>1){while(bu-bl>1){
			int mid=(bl+bu)/2;
			if(t[mid]>=x[y])bu=mid;
			else bl=mid;
		}}
		else bl=bu=0;
		if(b>1&&bu==0&&bl==-1)bl=0;
		if(b>1&&bl==b-1&&bu==b)bu=b-1;
		ans[y]=200000000000;
		long long  tr[2]={absb(x[y]-s[al]),absb(x[y]-s[au])};
		long long  sr[2]={absb(x[y]-t[bl]),absb(x[y]-t[bu])};
		if(x[y]-s[al]>=0&&x[y]-t[bl]>=0)ans[y]=max(tr[0],sr[0]);
		if(x[y]-s[au]<=0&&x[y]-t[bu]<=0)ans[y]=min(ans[y],max(tr[1],sr[1]));
		if(s[al]<=x[y]&&x[y]<=t[bu])ans[y]=min(ans[y],tr[0]+sr[1]+min(tr[0],sr[1]));
		if(t[bl]<=x[y]&&x[y]<=s[au])ans[y]=min(ans[y],tr[1]+sr[0]+min(tr[1],sr[0]));
	}
	for(i=0;i<q;i++)printf("%lld\n",ans[i]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&a,&b,&q);
  ^
./Main.c:15:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<a;i++)scanf("%lld",&s[i]);
                  ^
./Main.c:16:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<b;i++)scanf("%lld",&t[i]);
                  ^
./Main.c:17:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<q;i++)scanf("%lld",&x[i]);
                  ^