#include<stdio.h>
int main(){
	long long n,m,a,b=0,i,j,k,s=0,c=1,d[10010]={};
	scanf("%lld %lld %lld",&n,&a,&m);
	for(i=0;i<n;i++){
		scanf("%lld",&k);
		for(j=i;j&&d[j-1]<k;j--)d[j]=d[j-1];
		d[j]=k;
	}//for(i=0;i<n;i++)printf("%lld ",d[i]);printf("\n");
	for(i=0;i<a;i++)s+=d[i];
	for(j=0;d[i-1]-d[j];j++);
	for(k=j;d[i-1]==d[k];k++);//printf("%lld %lld %lld\n",i,j,k);
	i=i-j;
	j=k-j;//printf("%lld %lld\n",i,j);
	if(d[0]==d[a-1])i=m+1;
	for(n=0;n<i;n++){
		if(n>=a)b+=c;
		c*=j-n;//printf("%lld ",c);
		c/=n+1;//printf("%lld\n",c);
	}
	printf("%f\n%lld\n",1.0*s/a,d[0]-d[a-1]?c:b);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld %lld %lld",&n,&a,&m);
  ^
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&k);
   ^