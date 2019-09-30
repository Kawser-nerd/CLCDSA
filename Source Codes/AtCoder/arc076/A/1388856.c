#include <stdio.h>

int abs(int x){
    if(x>0) return x;
    else return -x;
}

long long factorial(int x){
    if(x==0) return 1;
    else return x*((factorial(x-1))%1000000007)%1000000007;
}

long long combi(int m, int n){
    if(abs(m-n)>=2){
        return 0;
    }else if(abs(m-n)==1){
        return (factorial(m)*factorial(n))%1000000007;
    }else{
        return (2*factorial(m)*factorial(n))%1000000007;
    }
}

int main(){
    int n, m;
    scanf("%d%d",&n,&m);
    printf("%lld\n", combi(m, n));
    return 0;
    
} ./Main.c: In function ‘main’:
./Main.c:25:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&m);
     ^