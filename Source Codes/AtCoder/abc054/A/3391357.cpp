#include<stdio.h>
int main()
{
	int A,B;
	scanf("%d%d",&A,&B);
	if(A!=1&&B!=1)
	{
		if(A>B)
			printf("Alice\n");
			else if(A==B)
				printf("Draw\n");
				else
					printf("Bob\n");
	}
	if(A==1&&B!=1)
	{
		printf("Alice\n");
	}
	if(A!=1&&B==1)
	{
		printf("Bob\n");
	}
	if(A==1&&B==1)
	{
		printf("Draw\n");
	}
}