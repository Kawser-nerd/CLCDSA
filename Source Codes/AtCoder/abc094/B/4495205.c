#include <stdio.h>

int main(void){
	
	int n,m,x,a[100];
	int cost_1=0;
	int cost_2=0;
	
	scanf("%d%d%d",&n,&m,&x);
	
	for(int i=0;i<m;i++){
		scanf("%d",&(a[i]));
	}
	
	int y=x;
	
	while(y!=n){
		for(int j=0;j<m;j++){
			if(y==a[j]){
				cost_1++;
			}
		}
		y++;
	}
	
	y=x;
	
	while(y!=0){
		for(int k=0;k<m;k++){
			if(y==a[k]){
				cost_2++;
			}
		}
		y--;
	}
		
	if(cost_1<cost_2){
		printf("%d\n",cost_1);
	}else{
		printf("%d\n",cost_2);
	}
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&n,&m,&x);
  ^
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&(a[i]));
   ^