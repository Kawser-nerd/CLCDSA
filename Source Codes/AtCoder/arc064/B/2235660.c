#include<stdlib.h>
#include<string.h>

char s[100010];
int main(){
	scanf("%s",s);
	int n=strlen(s);
	puts((s[0]==s[n-1])^(n%2)?"First":"Second");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
  scanf("%s",s);
  ^
./Main.c:6:2: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:6:2: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:8:2: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
  puts((s[0]==s[n-1])^(n%2)?"First":"Second");
  ^