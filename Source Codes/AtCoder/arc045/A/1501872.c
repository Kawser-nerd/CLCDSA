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
char str[10];
int main(void)
{
	int flag=1;
	while(scanf("%s",str)!=EOF){
		if(flag) flag=0;
		else putchar(' ');
		switch(str[0]){
			case 'L': putchar('<');break;
			case 'R': putchar('>');break;
			default: putchar('A');break;
		}
	}
	puts("");
	return 0;
}