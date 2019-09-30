#include<stdio.h>

int sum(int N, int s[]){
	int sum=0;
	int i;
	for(i=0;i<N;i++){
		sum=sum+s[i];
	}
	
	return sum;
}

int main(void){
	int N,i,min=101;
	int s[100];
	int point;
	
	scanf("%d",&N);
	
	i=0;
	
	while(i<N){
		scanf("%d",&s[i]);
		if(s[i]%10!=0 && min>s[i]){
			min=s[i];
		}
		i++;
	}        
	
	point=sum(N,s);
	
	if(point%10!=0){
		printf("%d\n",point);
	}else if(min!=101){
		printf("%d\n",point-min);
	}else{
		printf("0\n");
	}
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:18:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c:23:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&s[i]);
   ^