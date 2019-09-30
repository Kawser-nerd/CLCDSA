#include<stdio.h>
int main(){
	long long n,m,i,j,l[2010],a[2010],b[2010],c[2010],co[2010]={};
	for(i=2;i<2000;i++)co[i]=-1e18;
	scanf("%lld %lld",&n,&m);
	for(i=0;i<m;i++)scanf("%lld %lld %lld",&a[i],&b[i],&c[i]);
	for(i=0;i<n;i++){
		for(j=l[i]=0;j<m;j++){
			if(co[a[j]]+c[j]>co[b[j]])co[b[j]]=co[a[j]]+c[j];
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(co[a[j]]+c[j]>co[b[j]]){
				co[b[j]]=co[a[j]]+c[j];
				l[b[j]]=1;
			}
			if(l[a[j]])l[b[j]]=1;
		}
	}
	if(l[n]==0)printf("%lld\n",co[n]);
	else       printf("inf\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld %lld",&n,&m);
  ^
./Main.c:6:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<m;i++)scanf("%lld %lld %lld",&a[i],&b[i],&c[i]);
                  ^