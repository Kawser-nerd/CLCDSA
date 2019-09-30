#include<cstdio>

int main(){
	int A, B;
	char op;
	scanf("%d %c %d", &A,&op,&B);
	if(op == '+') printf("%d\n", A+B);
	if(op == '-') printf("%d\n", A-B);

	return 0;
}