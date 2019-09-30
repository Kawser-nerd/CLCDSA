#include<stdio.h>
#include<string.h>
int main()
{
	char s[100];
	int m,n,i,j;
	int count = 0;
	int max = 0;
	scanf("%d",&n);
	getchar();
	gets(s);
	for(i = 0;i < n;i++)
	{
		if(s[i] == 'I') 
		{
			count++;
		}
		if(s[i] == 'D')
		{
			count--;
		}
		if(max <= count)
		{
			max = count;
		}
	}
	printf("%d",max);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
  gets(s);
  ^
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
/tmp/cce9ojj2.o: In function `main':
Main.c:(.text.startup+0x3a): warning: the `gets' function is dangerous and should not be used.