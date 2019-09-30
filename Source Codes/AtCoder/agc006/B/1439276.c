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
int ans[200000];
int main(void)
{
	int n,x,l,r,num=1,i;
	scanf("%d%d",&n,&x);
	if(x==1||x==2*n-1) puts("No");
	else{
		puts("Yes");
		if(n==2) printf("1\n2\n3\n");
		else{
			if(x==2){
				ans[n-2]=3,ans[n-1]=1,ans[n]=2,ans[n+1]=4;
				l=1,r=4;
			}else{
				ans[n-2]=x-1,ans[n-1]=x+1,ans[n]=x,ans[n+1]=x-2;
				l=x-2,r=x+1;
			}
			FOR(i,0,2*n-1){
				if(!ans[i]){
					while(l<=num&&num<=r) num++;
					ans[i]=num++;
				}
			}
			FOR(i,0,2*n-1) printf("%d\n",ans[i]);
		}
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:24:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&x);
  ^