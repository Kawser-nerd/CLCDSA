#include <stdio.h>

int main(void)
{
	char s[2],t[2];
	int i=0;
	scanf("%d%d",&s[0],&s[1]);
	for(i;i <= 1;i++)
	{
		if(s[i]==2)
			{t[i]=0;}
		else if(s[i]==4 || s[i]==6 || s[i]==9 || s[i]==11)
			{t[i]=1;}
		else
			{t[i]=2;}
	}
	if(t[0]==t[1])
		{printf("Yes");}
	else
		{printf("No");}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:8: warning: format ‘%d’ expects argument of type ‘int *’, but argument 2 has type ‘char *’ [-Wformat=]
  scanf("%d%d",&s[0],&s[1]);
        ^
./Main.c:7:8: warning: format ‘%d’ expects argument of type ‘int *’, but argument 3 has type ‘char *’ [-Wformat=]
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&s[0],&s[1]);
  ^