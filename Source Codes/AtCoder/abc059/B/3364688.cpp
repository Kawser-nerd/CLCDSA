#include<stdio.h>
#include<stdlib.h>
int main()
{
    long double A,B;
    scanf("%Lf",&A);
    scanf("%Lf",&B);
    if(A>B)
	{
    printf("GREATER\n"); 
	} 
	if(A<B)
	{
		printf("LESS\n");
	} 
	if (A==B)
	{
		printf("EQUAL\n");
	}
    system("pause");
}