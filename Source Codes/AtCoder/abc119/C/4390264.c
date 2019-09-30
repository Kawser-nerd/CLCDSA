#include <stdlib.h> 
#include <stdio.h>
long long Max(long long x,long long y){
    return x>y?x:y;
}
long long Min(long long x,long long y){
    return x<y?x:y;
}
long long p=1000000000,n,a,b,c,l[10];
void dfs(long long i,long long A,long long B,long long C,long long T){
    if(i==n+1){return;}
    if(A>0&&B>0&&C>0){
        p=Min(p,abs(a-A)+abs(b-B)+abs(c-C) + 10*(Max(0,T-3)));
        
    }
        dfs(i+1,A+l[i],B,C,T+1);
        dfs(i+1,A,B+l[i],C,T+1);
        dfs(i+1,A,B,C+l[i],T+1);
        dfs(i+1,A,B,C,T);
}

int main()
{
    
    scanf("%lld%lld%lld%lld",&n,&a,&b,&c);
    for(int i=0;i<n;i++){
        scanf("%lld",&l[i]);
    }
    dfs(0,0,0,0,0);
    printf("%lld",p);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:25:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lld%lld%lld",&n,&a,&b,&c);
     ^
./Main.c:27:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld",&l[i]);
         ^