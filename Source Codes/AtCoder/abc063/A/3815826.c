#include<stdio.h>
char A, B;
int main(){
	A=getchar()-'0';
	getchar();
	B=getchar()-'0';
	if(A+B<10){
		printf("%d\n", A+B);
	}else{
		printf("error\n");
	}
}