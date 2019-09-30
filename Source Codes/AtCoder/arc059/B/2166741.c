#include<stdio.h>
#include<string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)

char s[100010];
int main(){
	gets(s);
	int n=strlen(s);
	rep(i,0,n-1){
		if(s[i]==s[i+1]){
			printf("%d %d\n",i+1,i+2);
			return 0;
		}
		if(s[i]==s[i+2]){
			printf("%d %d\n",i+1,i+3);
			return 0;
		}
	}
	puts("-1 -1");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
  gets(s);
  ^
./Main.c:12:11: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long long int’ [-Wformat=]
    printf("%d %d\n",i+1,i+2);
           ^
./Main.c:12:11: warning: format ‘%d’ expects argument of type ‘int’, but argument 3 has type ‘long long int’ [-Wformat=]
./Main.c:16:11: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long long int’ [-Wformat=]
    printf("%d %d\n",i+1,i+3);
           ^
./Main.c:16:11: warning: format ‘%d’ expects argument of type ‘int’, but argument 3 has type ‘long long int’ [-Wformat=]
/tmp/ccILOeGM.o: In function `main':
Main.c:(.text.startup+0xc): warning: the `gets' function is dangerous and should not be used.