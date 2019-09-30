#include<stdio.h>
#include<string.h>
int main(void)
{
	int strNum,num,diff,ans=753,a,i;
	char S[10];
	
	scanf("%s",S);
	strNum=strlen(S);

	for(i=0;i<strNum-2;i++){
		num=(S[i]-'0')*100 + (S[i+1]-'0')*10 + (S[i+2]-'0');
		diff=abs(num-753);
		if(diff<ans) ans=diff;
	}

	printf("%d\n",ans);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:8: warning: implicit declaration of function ‘abs’ [-Wimplicit-function-declaration]
   diff=abs(num-753);
        ^
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",S);
  ^