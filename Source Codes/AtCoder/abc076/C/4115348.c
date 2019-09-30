#include<stdio.h>
#include<string.h>
int main()
{
	int j, i, k, flag = 0, tt = 0;
	char S[60], T[60], temp[60];
	gets(S);
	gets(T);

	for (i = strlen(S) - strlen(T); i >= 0; i--)
	{
		strcpy(temp, S);
		strcpy(temp + i, T);
		temp[i + strlen(T)] = S[i + strlen(T)];
		for (j = 0; j < strlen(S); j++)
		{
			if (S[j] != '?')
			{
				if (S[j] != temp[j])
				{
					break;
				}
			}
			if (j == strlen(S) - 1)
			{
				flag = 1;
				for (i = 0; i < strlen(temp); i++)
					if (temp[i] == '?') printf("a");
					else printf("%c", temp[i]);
				goto end;
			}
		}
	}

end:
	if (flag == 0)
		printf("UNRESTORABLE");


} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
  gets(S);
  ^
/tmp/ccWcvkmA.o: In function `main':
Main.c:(.text.startup+0x30): warning: the `gets' function is dangerous and should not be used.