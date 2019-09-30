#include <stdio.h>

int main(void)
{
	int n, x, y, z, i, j;
	scanf("%d" "%d" "%d" "%d" , &n, &x, &y, &z);
	if(n==x || n==y || n==z)
	{
		printf("NO\n");
		return 0;
	}
	
	while(n>0)
	{
		i++;
		n=n-3;
		if(n==x || n==y || n==z){
			n++;
			if(n==x || n==y || n==z){
				n++;
				if(n==x || n==y || n==z){
				printf("NO\n");
				return 0;}

			}
		}
	}
	
	if(i<=100)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d" "%d" "%d" "%d" , &n, &x, &y, &z);
  ^