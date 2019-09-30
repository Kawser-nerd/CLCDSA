#include <stdio.h>

unsigned long long int combi(int a,int b)
{
    int i;
    unsigned long long int C=1;
    for(i=1;i<=b;i++){
        C = C*(a-i+1)/i;
    }
    return C;
}

int main()
{
    int N,A,B,i,j,sum,sub=0;
    unsigned long long int v[50],max,C=0,ave=0;
    scanf("%d %d %d",&N,&A,&B);
    for(i=0;i<N;i++){
        scanf("%lld",&v[i]);
        for(j=i;j>0;j--){
            if(v[j]>v[j-1]){
                max=v[j];
                v[j]=v[j-1];
                v[j-1]=max;
            }
        }
    }
    if(v[0]==v[A-1]){
        sum=A;
        for(i=A;i<N;i++){
            if(v[0]==v[i]){
                sum++;
            }
            else break;
        }
        for(i=A;i<=B;i++){
            C+=combi(sum,i);
            if(i==sum) break;
        }
        printf("%lf\n%lld\n",(double)v[0],C);
    }
    else{
        sum=0;
        for(i=0;i<A;i++) ave+=v[i];
        for(i=0;i<N;i++){
            if(v[A-1]==v[i]){
                sum++;
                if(i<A) sub++;
            }
            else if(i>=A && v[A-1]!=v[i]) break;
        }
        printf("%lf\n%lld\n",(double)ave/A,combi(sum,sub));
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:17:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d",&N,&A,&B);
     ^
./Main.c:19:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld",&v[i]);
         ^