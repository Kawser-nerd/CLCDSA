#include<stdio.h>

long long ru2(int n){
	int i;
	long long r=1;
	for(i=0;i<n;i++)r=r*2;
	return r;
}

long long unsigned ncm(int n,int m){
	if(n<m)return 0;
	if(m==0)return 1;
	if(m>n/2)m=n-m;
	int i;
	long long unsigned r=1;
	for(i=m-1;i>=0;i--)r=r*(n-i);
	for(i=m;i>=1;i--)r=r/i;
	return r;
	
}

int main(){
	int n,p,a[100],i;
	scanf("%d%d",&n,&p);
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	int guki[2]={0};
	for(i=0;i<n;i++)guki[a[i]%2]++;
	long long ang=ru2(guki[0]),ank=0;
	for(i=0;i+p<=guki[1];i+=2){
		ank+=ncm(guki[1],i+p);
	}
	printf("%lld\n",ang*ank);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:24:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&p);
  ^
./Main.c:25:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<n;i++)scanf("%d",&a[i]);
                  ^