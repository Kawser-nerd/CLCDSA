#include<stdio.h>
int n,m,a,d[40][100010],c[100010],e[100010],i,j;
int main(){
	scanf("%d %d %d",&n,&m,&a);
	for(i=0;i<n;i++)c[i]=d[0][i]=i;
	while(m--){
		scanf("%d",&i);
		j=c[i];
		c[i]=c[i-1];
		c[i-1]=j;
		//for(i=0;i<n;i++)printf("%d ",d[0][i]+1);printf("\n");
	}
	for(i=0;i<n;i++)d[0][c[i]]=i;
	for(i=0;i<n;i++)c[i]=i;
	for(i=0;(1LL<<i)<=a;i++){
		for(j=0;j<n;j++)d[i+1][j]=d[i][d[i][j]];
	}
	for(i=0;(1LL<<i)<=a;i++){
		if((1LL<<i)&a){
			for(j=0;j<n;j++)e[j]=d[i][c[j]];
			for(j=0;j<n;j++)c[j]=e[j];
		}
	}
	for(i=0;i<n;i++)printf("%d\n",c[i]+1);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d",&n,&m,&a);
  ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&i);
   ^