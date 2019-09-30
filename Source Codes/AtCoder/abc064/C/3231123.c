#include <stdio.h>
#include <stdlib.h>

int main(void){
	int n,a,i,color[110]={0},max=8,m=0;
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%d",&a);
		if(a<400){
			color[0]++;
		}else if(a<800){
			color[1]++;
		}else if(a<1200){
			color[2]++;
		}else if(a<1600){
			color[3]++;
		}else if(a<2000){
			color[4]++;
		}else if(a<2400){
			color[5]++;
		}else if(a<2800){
			color[6]++;
		}else if(a<3200){
			color[7]++;
		}else{
			color[max]++;
			max++;
			m++;
		}
	}
	
	int sum = 0;
	for(i=0;i<8;i++){if(color[i] != 0)sum++;
	}
	if(n==m)printf("1");
	else	printf("%d",sum);
	for(i=8;i<110;i++){if(color[i] != 0)sum++;
	}
	printf(" %d",sum);
	
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a);
   ^