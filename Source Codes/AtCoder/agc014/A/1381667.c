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
int main(void)
{
	int a,b,c,t1,t2,cnt=0;
	scanf("%d%d%d",&a,&b,&c);
	while(!(a%2)&&!(b%2)&&!(c%2)){
		if(a==b&&b==c){
			puts("-1");
			return 0;
		}
		cnt++;
		t1=a,t2=b;
		a=(b+c)/2;
		b=(t1+c)/2;
		c=(t1+t2)/2;
	}
	printf("%d\n",cnt);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:22:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&a,&b,&c);
  ^