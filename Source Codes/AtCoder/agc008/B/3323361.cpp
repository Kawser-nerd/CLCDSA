#include<cstdio>
#include<algorithm>
using namespace std;

#define MAXN 100000
int N,K;
int A[MAXN+5];
long long SumP[MAXN+5],Sum[MAXN+5];

int main(){
    scanf("%d%d",&N,&K);
    for(int i=1;i<=N;i++){
        scanf("%d",&A[i]);
        Sum[i]=Sum[i-1]+A[i];
        SumP[i]=SumP[i-1]+(A[i]>0)*A[i];
    }
    long long Ans=0;
    for(int i=K;i<=N;i++){
        long long tmp=Sum[i]-Sum[i-K];
        tmp=(tmp>0)*tmp+SumP[i-K]+SumP[N]-SumP[i];
        Ans=max(Ans,tmp);
    }
    printf("%lld",Ans);
}