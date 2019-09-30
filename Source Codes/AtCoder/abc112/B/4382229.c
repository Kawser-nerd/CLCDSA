#include <stdio.h>
int main (){
int n,t,i,x[102]={0},k,min=1003,ya=0;
	scanf("%d %d",&n,&t);
	for(i=0;i<n;i++){
	scanf ("%d %d",&x[i],&k);
		if(k<=t)
		{
			if(min>x[i])
			{
				min=x[i];
			}
		}
		else
		{
		ya++;
		}	
	}
	if(ya==n)
	{
	printf("TLE");	
	}
	else
	{
	printf("%d",min);	
	}
	return 0;
	} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&n,&t);
  ^
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf ("%d %d",&x[i],&k);
  ^