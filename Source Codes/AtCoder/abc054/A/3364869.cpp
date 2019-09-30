#include<stdio.h>
#include<stdlib.h>
int main(void){
	int a,b;
	scanf("%d",&a);
	scanf("%d",&b);
	if(a>b&&b!=1){
		printf("Alice\n");
	} if(a!=1&&a<b){
		printf("Bob\n");
	} if(a==b){
		printf("Draw\n");
	} if(a==1&&b>1){
		printf("Alice\n");
	} if(a>1&&b==1){
		printf("Bob\n");
	}
	system("pause");
	return 0;
}