#include<stdio.h>

int main()
{
	int M,N,a,b;
	scanf("%d %d", &M,&N);
	scanf("%d %d", &a, &b);
	printf("%d", M*N - (a*N + (M - a) * b));
}