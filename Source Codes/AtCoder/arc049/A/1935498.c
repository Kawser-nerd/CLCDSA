#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <limits.h>
#include <assert.h>
#define FOR(i,a,n) for(i=(a);i<(n);i++)
#define swap(type,a,b) do{type t=a;a=b;b=t;}while(0)
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define ll long long
#define INF 100000000
#define MOD 1000000007
#define SIZE 100005
#define LOCAL
#ifdef LOCAL
    #define DEBUG(...) printf(" "__VA_ARGS__)
#else
    #define DEBUG(...)
#endif /* LOCAL */
int comp(const void* a,const void* b){
	return *(int*)a-*(int*)b;
}
char str[101];
int main(void)
{
	int a,b,c,d;
	scanf("%s%d%d%d%d",str,&a,&b,&c,&d);
	printf("%.*s",a,str);
	putchar('\"');
	printf("%.*s",b-a,str+a);
	putchar('\"');
	printf("%.*s",c-b,str+b);
	putchar('\"');
	printf("%.*s",d-c,str+c);
	putchar('\"');
	printf("%.*s\n",strlen(str)-d,str+d);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:38:9: warning: field precision specifier ‘.*’ expects argument of type ‘int’, but argument 2 has type ‘size_t {aka long unsigned int}’ [-Wformat=]
  printf("%.*s\n",strlen(str)-d,str+d);
         ^
./Main.c:29:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s%d%d%d%d",str,&a,&b,&c,&d);
  ^