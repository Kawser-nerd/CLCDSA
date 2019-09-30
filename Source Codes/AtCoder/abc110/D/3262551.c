#include <stdio.h>
long long int kaizyou(long long int x,long long int y,long long z){
    //x????mod y?
    long long int tmp=1;
    for(int i=x;i<=z;i++){
        tmp*=i;
        tmp%=y;
    }
    return tmp;
}

long long int ruizyou(long long int x,long long y,long long int z){
    //x???(modz)
    long long int tmp=1;
    long long int s[100]={};
    int memo[100]={};
    s[0]=x;
    for(int i=0;i<100;i++){
        memo[i]=y%2;
        y/=2;
    }
    for(int i=1;i<100;i++){
        s[i]=(x*x)%z;
        x=(x*x)%z;
    }
    for(int i=0;i<100;i++){
        if(memo[i]==1){
            tmp=(tmp*s[i])%z;
        }
    }
    return tmp;
}

long long int combination(long long int x,long long int y,long long int z){
    //xCy(mod z)
    long long int tmp=1;
    tmp=(tmp*kaizyou(y+1,z,x))%z;
    tmp=(tmp*ruizyou(kaizyou(1,z,x-y),z-2,z))%z;
    return tmp;
}


int main(void){
    long long int n,m,sosu[100]={},memo=0,copy_m,max=1,result=1;
    
    scanf("%lld%lld",&n,&m);
    
    copy_m=m;
    
    for(int i=2;i<32000;i++){
        if(m%i==0)memo++;
        next:
        if(m%i==0){
            m/=i;
            sosu[memo]++;
            max*=i;
            goto next;
        }
    }
   
    if(copy_m/max>=32000){
        sosu[memo+1]++;
    }
    
    for(int i=1;i<=99;i++){
        result*=combination(n+sosu[i]-1,n-1,1000000007);
        result%=1000000007;
    }
    printf("%lld",result);
    
    
} ./Main.c: In function ‘main’:
./Main.c:46:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lld",&n,&m);
     ^