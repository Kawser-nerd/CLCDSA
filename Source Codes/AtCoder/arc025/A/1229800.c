#include <stdio.h>

int main(void)
{
	int d[20],j[20],i,ans=0;

	scanf("%d %d %d %d %d %d %d",&d[0],&d[1],&d[2],&d[3],&d[4],&d[5],&d[6]);
	scanf("%d %d %d %d %d %d %d",&j[0],&j[1],&j[2],&j[3],&j[4],&j[5],&j[6]);
	
	
	for(i=0;i<=6;i++){
		if(d[i]>=j[i]){
			ans+=d[i];
		} else{
			ans+=j[i];
		}
	}
	
	printf("%d\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d %d %d %d %d",&d[0],&d[1],&d[2],&d[3],&d[4],&d[5],&d[6]);
  ^
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d %d %d %d %d",&j[0],&j[1],&j[2],&j[3],&j[4],&j[5],&j[6]);
  ^