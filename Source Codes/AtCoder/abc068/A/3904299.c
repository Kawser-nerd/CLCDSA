#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

char s[99];
int main(){
	printf("ABC%s",gets(s));
} ./Main.c: In function ‘main’:
./Main.c:11:17: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
  printf("ABC%s",gets(s));
                 ^
./Main.c:11:9: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘int’ [-Wformat=]
  printf("ABC%s",gets(s));
         ^
/tmp/ccPU7Zad.o: In function `main':
Main.c:(.text.startup+0xc): warning: the `gets' function is dangerous and should not be used.