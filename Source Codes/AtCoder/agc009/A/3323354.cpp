#include<cstdio>

#define MAXN 100000
int N;
long long A[MAXN+5],B[MAXN+5];

int main(){
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
        scanf("%lld%lld",&A[i],&B[i]);
    long long Ans=0;
    for(int i=N;i>=1;i--){
        A[i]+=Ans;
        Ans+=(B[i]-(A[i]%B[i]))%B[i];
    }
    printf("%lld",Ans);
}