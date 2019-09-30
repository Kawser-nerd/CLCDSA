#include<stdio.h>
int MAX(int a,int b){return a<b?b:a;}
int main(){
	int n,i,p[100010],c[100010],m[100010]={};
	int d[100010]={};
	scanf("%d",&n);
	p[0]=0;
	for(i=1;i<n;i++)scanf("%d",&p[i]);
	for(i=n;i--;){
		c[i]++;
		d[i]=MAX(m[i],n-c[i]);
		m[p[i]]=MAX(m[p[i]],c[i]);
		c[p[i]]+=c[i];
	}
	for(i=0;i<n;i++)printf("%d\n",d[i]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:8:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=1;i<n;i++)scanf("%d",&p[i]);
                  ^