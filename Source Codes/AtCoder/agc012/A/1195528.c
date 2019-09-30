#include <stdio.h>
#include <stdlib.h>
#define swap(type,a,b) do{type t=a;a=b;b=t;}while(0);
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ll long long
#define INF 100000000
#define FOR(i,a,n) for(int i=a;i<n;i++)
int comp(const void* a,const void* b){
	return *(ll*)a-*(ll*)b;
}
void fill(int a[],int b,int c){
	for(int i=0;i<b;i++) a[i]=c;
	return;
}
int a[300000];
int main(void)
{
    int n;
    ll res=0;
    scanf("%d",&n);
    FOR(i,0,3*n) scanf("%d",&a[i]);
    qsort(a,3*n,sizeof(a[0]),comp);
    for(int i=n;i<3*n-1;i+=2){
        res += a[i];
    }
    printf("%lld\n",res);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:21:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:22:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     FOR(i,0,3*n) scanf("%d",&a[i]);
                  ^