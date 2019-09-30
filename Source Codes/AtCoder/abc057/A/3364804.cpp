#include<stdio.h>
#include<stdlib.h>
int main(void){
	int A,B,sum;
	scanf("%d",&A);
	scanf("%d",&B);
	sum=A+B;
	if(sum>=24){
		sum=sum-24;
	}
	printf("%d",sum);
	system("pause");
	return 0;
}