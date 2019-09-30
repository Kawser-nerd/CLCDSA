#include<stdio.h>
long long int N;
char c;
int main(){
	c=getchar();
	while(c!='\n'){
		if(c!=' '){
			N *= 10;
			N += c-'0';
		}
		c=getchar();
	}
	printf("%d\n", N<<1);
} ./Main.c: In function ‘main’:
./Main.c:13:9: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long long int’ [-Wformat=]
  printf("%d\n", N<<1);
         ^