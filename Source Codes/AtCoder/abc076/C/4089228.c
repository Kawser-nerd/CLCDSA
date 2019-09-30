#include<stdio.h>
#include<string.h>
int main()
{
	char s[200000];
	char t[100];
	scanf("%s", s);
	scanf("%s", t);
	int aim;
	int ls, lt,i,flag=0;
	ls = strlen(s);
	lt = strlen(t);
	for (aim = ls - lt; aim > -1; aim--)
	{
		if (!flag)
		{
			flag = 1;
			for (i = 0; i < lt; i++)
			{
				if (s[aim + i] != '?'&&s[aim + i] != t[i])
				{
					flag = 0;
					break;
				}
			}
		}
		else
			break;
	}
	aim++;
	if (flag)
	{
		for (i = 0; i < aim; i++)
		{
			if (s[i] == '?')
				printf("a");
			else
				printf("%c", s[i]);
		}
		printf("%s", t);
		for (i = aim + lt; i < ls; i++)
		{
			if (s[i] == '?')
				printf("a");
			else
				printf("%c",s[i]);
		}
	}
	else
		printf("UNRESTORABLE");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", s);
  ^
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", t);
  ^