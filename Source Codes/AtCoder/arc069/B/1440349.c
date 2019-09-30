#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#define swap(type,a,b) do{type t=a;a=b;b=t;}while(0);
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define ll long long
#define INF 100000000
#define FOR(i,a,n) for(i=(a);i<(n);i++)
int comp(const void* a,const void* b){
	return *(int*)a-*(int*)b;
}
void fill(int a[],int b,int c){
	int i;
	FOR(i,0,b) a[i]=c;
	return;
}
int a[100000];
int b[100000];
char str[2]="SW";
int n;
int check(){
	int i;
	FOR(i,2,n){
		if(b[i-1]==a[i-1]) b[i]=b[i-2];
		else b[i]=1-b[i-2];
	}
	if((a[0]==b[0])!=(b[1]==b[n-1])) return 0;
	else if((a[n-1]==b[n-1])!=(b[n-2]==b[0])) return 0;
	else return 1;
}
int main(void)
{
	int i,j;
	char s;
	scanf("%d%*c",&n);
	FOR(i,0,n){
		scanf("%c",&s);
		a[i]=(s!='o');
	}
	FOR(i,0,2){
		FOR(j,0,2){
			b[0]=i,b[1]=j;
			if(check()){
				FOR(i,0,n) putchar(str[b[i]]);
				puts("");
				return 0;
			}
		}
	}
	puts("-1");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:38:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%*c",&n);
  ^
./Main.c:40:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%c",&s);
   ^