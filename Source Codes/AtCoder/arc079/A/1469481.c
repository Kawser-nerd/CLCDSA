#include<stdio.h>
#include<stdlib.h>

int main(void){
	int from[200000],to[200000];
	int n,m,p,q,i,j,in;
	
	scanf("%d%d",&n,&m);
	in=0;
	for(i=0;i<200000;i++) to[i]=0;
	for(i=0;i<m;i++){
		scanf("%d%d",&p,&q);
		if(p==1) from[in++]=q;
		if(q==n) to[p]=1;
	}
	int flg=0;
	for(i=0;i<in;i++){
		if(to[from[i]]==1){
			flg=1;
			break;
		}
	}
	
	if(flg==1) puts("POSSIBLE");
	else puts("IMPOSSIBLE");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&m);
  ^
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&p,&q);
   ^