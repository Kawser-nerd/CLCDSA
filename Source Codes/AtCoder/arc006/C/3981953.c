#include<stdio.h>
#include<string.h>
int stack[50];
int main(){
	memset(stack,0,4*50);
	int n;int sum=0;int a;int b=0;int last=0;int o=0;
	scanf("%d",&n);
	if(n>50){
			printf("%d",0);
		return 0;
	}
	//n--;
	for(int j=1;j<=n;j++){
	
		scanf("%d",&a);
		if(a>100000){
		printf("%d",0);
		return 0;
		}
		int t=100000;
		for(int i=0;i<=last;i++){
			if(stack[i]>=a){
				if(stack[i]<t) {
				//	if(stack[i]==0) 
					t=stack[i];
					o=i;
				}
			}
		}
	if(t<100000){
		stack[o]=a;
		
	}else{
		stack[last++]=a;
	}
	
		
	}
	printf("%d\n",last);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a);
   ^