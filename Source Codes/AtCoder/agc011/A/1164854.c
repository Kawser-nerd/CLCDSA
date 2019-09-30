#include <stdio.h>
#include <stdlib.h>
#define FOR(i,a,n) for(int i=a;i<n;i++)

int t[1000000];
int comp(const void* a,const void* b){
	return *(int*)a-*(int*)b;
}
int main(void)
{
    int n,c,k;
    int m=0,ans=0;
    scanf("%d %d %d",&n,&c,&k);
    FOR(i,0,n) scanf("%d",&t[i]);
    qsort(t,n,sizeof(int),comp);
    while(m<n){
        int num=0;
        int p=m;
        ans++;
        while(t[m]<=t[p]+k&&num<c&&m<n) m++,num++;
    }
    printf("%d\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d",&n,&c,&k);
     ^
./Main.c:14:16: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     FOR(i,0,n) scanf("%d",&t[i]);
                ^