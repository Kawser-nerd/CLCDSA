#include<stdio.h>

int quot_m2(int x){
	if(x>0)return -1*(x/2);
	return (-1*x+1)/2;
}

int ab(int x){
	if(x<0)return -x;
	return x;
}

int main(){
	int N,i=0;
	int ans[256];
	scanf("%d",&N);
	
	if(N==0){
		printf("0\n");
		return 0;
	}
	
	while(N!=0){
		ans[i]=ab(N)%2;
		N=quot_m2(N);
		i++;
	}
	for(i=i-1;i>=0;i--)printf("%d",ans[i]);
	printf("\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^