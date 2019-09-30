#include <stdio.h>
int main(void)
{
	int a,b,c=0,d,i;
	scanf("%d%d",&a,&b);
	d=b-a;
	for(i=1; i<=d; i++){
		c=c+i;
	}
	printf("%d\n",c-b);
	return 0;
}