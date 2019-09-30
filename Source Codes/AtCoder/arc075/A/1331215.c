#include<stdio.h>

int main(void){
	int N,i,min=101;
	int s[100];
	int point=0;
	
	scanf("%d",&N);
	
	i=0;
	
	while(i<N){
		scanf("%d",&s[i]);
		i++;
	}       
	
	for(i=0;i<N;i++){
		point+=s[i];
	}
	
	if(point%10==0){
		for(i=0;i<N;i++){
			if(s[i]%10!=0 && min>s[i]){
				min=s[i];
			}
		}
		if(min!=101){
			point=point-min;
		}else{
			point=0;
		}
	}
	
	printf("%d\n",point);
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&s[i]);
   ^