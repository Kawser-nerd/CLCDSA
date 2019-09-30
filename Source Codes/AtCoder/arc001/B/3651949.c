#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	//?????
	int a,b;
	
	//??????
	int i,j,k,l;
	int flag=0;
	int ans=0;
	int count=0;
	int temp,temp1,temp2;
	int min;
	int len;
	//????????
	
	scanf("%d %d",&a,&b);
	
//	printf("n?%d??\n", n);
//	printf("??????????\n");
	//?????
	
	ans=abs(a-b)/10;
	temp=abs(a-b)%10;
	
	if(temp==0) ans=ans;
	if(temp==1) ans=ans+1;
	if(temp==2) ans=ans+2;
	if(temp==3) ans=ans+3;
	if(temp==4) ans=ans+2;
	if(temp==5) ans=ans+1;
	if(temp==6) ans=ans+2;
	if(temp==7) ans=ans+3;
	if(temp==8) ans=ans+3;
	if(temp==9) ans=ans+2;
	
//	printf("??????\n");
	//??
	
	printf("%d\n",ans);
	
//	printf("???????\n");
	
	return 0;
	
} ./Main.c: In function ‘main’:
./Main.c:22:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&a,&b);
  ^