#include<stdio.h>
#include<stdlib.h>

void S(char *p1, char *p2, char *p3, char *p, char *str);
void cut(char *p);

int main()
{
	char Sa[101], Sb[101], Sc[101];
	char ch = 'A', *p = &ch;
	char *str = Sa;
	Sa[0] = 'A';
	Sb[0] = 'B';
	Sc[0] = 'C';
	
	gets(Sa+1);
	gets(Sb+1);
	gets(Sc+1);
	
	S(Sa, Sb, Sc, p, str);
	
	printf("%c\n", *p);
	
	return 0;
}
void S(char *p1, char *p2, char *p3, char *p, char *str)
{
	switch(str[1]){
		case 'a':
			cut(str);
			S(p1, p2, p3, p, p1);
			break;
		case 'b':
			cut(str);
			S(p1, p2, p3, p, p2);
			break;
		case 'c':
			cut(str);
			S(p1, p2, p3, p, p3);
			break;
		case '\0':
			*p = str[0];
	}
}
void cut(char *p)
{
	int i;
	for( i=1; p[i]!='\0'; i++){
		p[i] = p[i+1];
	}
	p[i-1] = '\0';
} ./Main.c: In function ‘main’:
./Main.c:16:2: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
  gets(Sa+1);
  ^
/tmp/ccUnfQbK.o: In function `main':
Main.c:(.text.startup+0x3c): warning: the `gets' function is dangerous and should not be used.