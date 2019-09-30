#include<stdio.h>
#include<math.h>

long long int comb(int n,int r){
    long long int res = 1;
    int i;
    for (i=0;i<r;i++){
        res = res * (n-i)/(i+1);
    }
    return res;
}

int main(void){
    int N,P;scanf("%d %d",&N,&P);
    
    int i,j,odds=0,evens=0;
    for (i=0;i<N;i++){
        int a;scanf("%d",&a);
        if (a%2)odds++; else evens++;
    }

    long long int res = 0;

    for (i=P;i<=odds;i+=2){
        res += comb(odds,i);
    }
    res*= pow(2,evens);
    printf("%lld\n",res);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     int N,P;scanf("%d %d",&N,&P);
             ^
./Main.c:18:15: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         int a;scanf("%d",&a);
               ^