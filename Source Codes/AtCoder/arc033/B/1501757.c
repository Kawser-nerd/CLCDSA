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
int binary_search(int a[],int n,int k){
	int left=0,right=n;
	while(right>left){
		int mid=(left+right)/2;
		if(a[mid]==k) return 1;
		if(a[mid]<k) left=mid+1;
		else right=mid;
	}
	return 0;
}
int a[100000];
int main(void)
{
	int na,nb,b,s1=0,i;
	scanf("%d%d",&na,&nb);
	FOR(i,0,na) scanf("%d",&a[i]);
	qsort(a,na,sizeof(int),comp);
	FOR(i,0,nb){
		scanf("%d",&b);
		if(binary_search(a,na,b)) s1++;
	}
	printf("%.10lf\n",(double)s1/(na+nb-s1));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:34:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&na,&nb);
  ^
./Main.c:35:14: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  FOR(i,0,na) scanf("%d",&a[i]);
              ^
./Main.c:38:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&b);
   ^