#include <stdio.h>
#include <stdlib.h>
#define swap(type,a,b) do{type t=a;a=b;b=t;}while(0);
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ll long long
#define INF 100000000
#define FOR(i,a,n) for(i=a;i<n;i++)
char str[50][51];
int a[50][27];
int ans[27];
int size=0;
int main(void){
    int n,i,j;
    scanf("%d",&n);
    FOR(i,0,27) ans[i]=INF;
    FOR(i,0,n){
        scanf("%s",str[i]);
    }
    FOR(i,0,n){
        for(j=0;str[i][j]!='\0';j++){
            a[i][str[i][j]-'a']++;
        }
        FOR(j,0,27) ans[j] = MIN(ans[j],a[i][j]);
    }
    FOR(i,0,27){
        if(ans[i]!=INF){
            while(ans[i]-->0) printf("%c",'a'+i);
        }
    }
    puts("");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:18:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s",str[i]);
         ^