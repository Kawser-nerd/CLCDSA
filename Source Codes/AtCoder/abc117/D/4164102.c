#include<stdio.h>
#include<math.h>


int main(void){
    int N=0;
    long K=0;
    int bin[50]={0};
    long long sum=0;
    long X=0;

    scanf("%d %ld",&N,&K);

    long A[N];

    for(int i=0;i<N;i++){
        A[i]=0;
        scanf("%ld",&A[i]);
        sum+=A[i];
        for(int j=0;j<50;j++){
            if((long)A[i]%2) bin[j]++;
            A[i]/=(long)2;
        }
    }

    for(int i=49;i>=0;i--){
        if(bin[i]<(int)(N+1)/2){
            if(X+(long)(pow(2,i))<=K){
                X+=(long)pow(2,i);
                sum+=(long long)pow(2,i)*(long long)(N-bin[i]*2);
            }
        }
    }
    
    printf("%lld",sum);
    

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %ld",&N,&K);
     ^
./Main.c:18:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%ld",&A[i]);
         ^