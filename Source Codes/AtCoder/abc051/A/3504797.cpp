#include<stdio.h>
#include<string.h>
int main()
{
	char a[25];
	scanf("%s",&a);
	for(int i=0;i<=18;i++)
	{
		if(i==5||i==13)
		{
			printf(" ");
		}
	else printf("%c",a[i] );
	}
} ./Main.cpp:6:13: warning: format specifies type 'char *' but the argument has type 'char (*)[25]' [-Wformat]
        scanf("%s",&a);
               ~~  ^~
1 warning generated.