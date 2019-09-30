#include <stdio.h>
int main(){
	int a,b;
	scanf ("%d%d",&a,&b);
	if(a==1)
	{
		a=14;
	}
	if(b==1)
	{
		b=14;
	}
	if(a==b){
printf("Draw");
	}
	else if(a>b){
	printf("Alice");
		}
		else
		{
	printf("Bob");
		}
	return 0;
	} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf ("%d%d",&a,&b);
  ^