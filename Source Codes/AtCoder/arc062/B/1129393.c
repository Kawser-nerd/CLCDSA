#include <stdio.h>

int main(void)
{
	int  n, i, g_cnt = 0, p_cnt = 0;
	char s[100000];
	gets(s);
	for(i = 0; i < 100000; i++){
		if(s[i] == 'g')g_cnt++;
		else if(s[i] == 'p')p_cnt++;
		else break;
		}
		printf("%d\n", (g_cnt - p_cnt) / 2);
		
		
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
  gets(s);
  ^
/tmp/ccZTNVZo.o: In function `main':
Main.c:(.text.startup+0x1e): warning: the `gets' function is dangerous and should not be used.