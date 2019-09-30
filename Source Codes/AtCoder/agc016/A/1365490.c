#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define swap(type,a,b) do{type t=a;a=b;b=t;}while(0);
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define ll long long
#define INF 100000000
#define FOR(i,a,n) for(i=a;i<n;i++)
int comp(const void* a,const void* b){
	return *(int*)a-*(int*)b;
}
void fill(int a[],int b,int c){
	int i;
	FOR(i,0,b) a[i]=c;
	return;
}
char str[101];
char s[101];
int len;
int solve(char c){
	int flag=0,cnt=0,i;
	while(1){
		flag=1;
		for(i=0;s[i+1]!='\0';i++){
			if(s[i]!=c||s[i+1]!=c) flag=0;
			if(s[i+1]==c) s[i]=c; 
		}
		if(flag) break;
		s[i]='\0',cnt++;
	}
	return cnt;
}
int main(void)
{
	int res=INF,t,i;
	scanf("%s",str);
	len=strlen(str);
	FOR(i,0,26){
		strcpy(s,str);
		t=solve('a'+i);
		res=MIN(res,t);
	}
	printf("%d\n",res);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:38:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",str);
  ^