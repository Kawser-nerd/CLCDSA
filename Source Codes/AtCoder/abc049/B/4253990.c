#include<stdio.h>
#include<string.h>
int main()
{
	int a,b;
	int i,j;
	int m,n;
	char s[101][101];
	scanf("%d%d",&a,&b);
	for(i = 0;i<a;i++)
	{
	   scanf("%s",&s[i]);
	}
	for(i = 0;i<a;i++)
	{
	   printf("%s\n",s[i]);
	   printf("%s\n",s[i]);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:11: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[101]’ [-Wformat=]
     scanf("%s",&s[i]);
           ^
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&a,&b);
  ^
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",&s[i]);
     ^