#include <stdio.h>
#include <string.h>

int main(void)
{
	int n,k,i,count=0,sum=0;
	int t[100005];
	scanf("%d %d",&n,&k);
	
	for(i=0;i<n;i++){
		scanf("%d",&t[i]);
	}
	
	for(i=0;i<=n-3;i++){
		if(t[i]+t[i+1]+t[i+2]<k){
			printf("%d\n",i+3);
			break;
		} else{
			count++;
		}
	}
	
	for(i=0;i<=n-3;i++){
		sum++;
	}
	
	if(sum==count){
		printf("-1\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&n,&k);
  ^
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&t[i]);
   ^