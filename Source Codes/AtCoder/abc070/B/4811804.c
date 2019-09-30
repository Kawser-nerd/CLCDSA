#include<stdio.h>
int main(void)
{
	int a,b,c,d;
	scanf("%d %d %d %d",&a,&b,&c,&d);
	if(b<c || d<a){
		printf("0\n");
	}
	else if(c<=a && b<=d){
		printf("%d\n",b-a);
	}
	else if(a<=c && d<=b){
		printf("%d\n",d-c);
	}
	else if(a<=c && b<=d){
		printf("%d\n",b-c);
	}
	else if(c<=a && d<=b){
		printf("%d\n",d-a);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d %d",&a,&b,&c,&d);
  ^