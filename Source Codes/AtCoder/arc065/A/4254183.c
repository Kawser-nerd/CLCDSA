#include<stdio.h>
#include<string.h>
char t1[10] = "dream";
char t2[10] = "dreamer";
char t3[10] = "erase";
char t4[10] = "eraser";

int main()
{
	char s[100000];
	gets(s);
	int i;
	int number = 0;
	int flag = 0;
	int m = strlen(s);
	for(i = 0;i < m;i++)
	{
		if(s[i] == 'e' && s[i+2] == 'a'||s[i] == 'd')
		{
		 number = 0;
		}
		if(s[i] == t1[number] || s[i] == t2[number] || s[i] == t3[number] || s[i] == t4[number] )
		{
			flag = 0;		
			number++;
		}
		else
		{
			flag = 1;
			break;
		}

	}
	if(flag == 0) printf("YES\n");
	if(flag == 1) printf("NO\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
  gets(s);
  ^
/tmp/cckypuQl.o: In function `main':
Main.c:(.text.startup+0x22): warning: the `gets' function is dangerous and should not be used.