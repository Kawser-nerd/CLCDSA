#include<stdio.h>

int main(void)
{
	int N,T,c,t,i,ansCost=1000,flag=0;
	
	scanf("%d %d",&N,&T);

	for(i=0;i<N;i++){		
		scanf("%d %d",&c,&t);
		
		if(t<=T){
			if(c<ansCost) ansCost=c;
		}else{
			flag++;
		}
	}
	if(flag!=i)printf("%d",ansCost);
	else printf("TLE");

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&N,&T);
  ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&c,&t);
   ^