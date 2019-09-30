#include<stdio.h>
int main(){
	int n,m,i,d[100010],c[100010]={};
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)scanf("%d",&d[i]);
	while(m--){
		if(c[d[m]]==0)printf("%d\n",d[m]);
		c[d[m]]=1;
	}
	for(i=0;i<n;i++){
		if(c[i+1]==0)printf("%d\n",i+1);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&n,&m);
  ^
./Main.c:5:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<m;i++)scanf("%d",&d[i]);
                  ^