#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
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
char str[100001];
int main(void)
{
    int i,len;
    ll ans=0;
    scanf("%s",str);
    len=strlen(str);
    FOR(i,0,len){
        if(str[i]=='U'){
            ans += (len-i-1);
            ans += 2*i;
        }
        else{
            ans += i;
            ans += 2*(len-i-1);
        }
    }
    printf("%lld\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:24:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",str);
     ^