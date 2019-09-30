#include<stdio.h>
int main(void)
{
	int a,b;
	scanf("%d %d",&a,&b);
	if(a==1){
		a=14;
	}
	if(b==1){
		b=14;
	}
	if(b<a){
		printf("Alice\n");
	}
	else if(a<b){
		printf("Bob\n");
	}
	else{
		printf("Draw\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&a,&b);
  ^