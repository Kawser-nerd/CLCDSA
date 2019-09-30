#include<stdio.h>

unsigned long long powermod(unsigned long long a,unsigned long long n,unsigned long long mod){
    unsigned long long pw;

    pw = 1;

    while(n >= 1){
        if(n & 1){
            pw = pw * a % mod;
        }
        a = a * a % mod;
        n /= 2;
    }
    return pw;
}

void matrixpowermod(unsigned long long *a,unsigned long long *b,int N,unsigned long long  n,unsigned long long mod){
    int i,j,k;
    unsigned long long c[N][N],d[N][N],x;

    for(i = 0;i < N;i++)
        for(j = 0;j < N;j++){
            c[i][j] = a[i * N + j] % mod;
            b[i * N + j] = 0;
        }

    for(i = 0;i < N;i++)
        b[i * N + i] = 1;
    while(n >= 1){
        if(n & 1){
            for(i = 0;i < N;i++){
                for(j = 0;j < N;j++){
                    d[i][j] = 0;
                    for(k = 0;k < N;k++){
                        d[i][j] += b[i * N + k] * c[k][j] % mod;
                    }
                }
            }
            for(i = 0;i < N;i++)
                for(j = 0;j < N;j++)
                    b[i * N + j] = d[i][j];
        }

        for(i = 0;i < N;i++){
            for(j = 0;j < N;j++){
                d[i][j] = 0;
                for(k = 0;k < N;k++){
                    d[i][j] += c[i][k] * c[k][j] % mod;
                }
            }
        }
        for(i = 0;i < N;i++)
            for(j = 0;j < N;j++)
                c[i][j] = d[i][j];
        n = n / 2;
    }
}

unsigned long long gcd(long a,long b){
    unsigned long long ex;

    if(a < b){
        ex = a;a = b;b = ex;
    }

    ex = a % b;
    if(ex == 0)
        return b;
    else
        return gcd(b,ex);
}

int main(void){
    int i,j;
    unsigned long long ans,a,b,m,g,mata[2][2],matb[2][2];

    scanf("%lld %lld %lld",&a,&b,&m);

    g = gcd(a,b);

    mata[0][0] = 10;mata[0][1] = 1;mata[1][0] = 0;mata[1][1] = 1;

    matrixpowermod(&mata[0][0],&mata[0][0],2,a - 1,m);

    ans = (mata[0][0] + mata[0][1]) % m;

    matb[0][0] = powermod(10,g,m);matb[0][1] = 1;matb[1][0] = 0;matb[1][1] = 1;

    matrixpowermod(&matb[0][0],&matb[0][0],2,b / g - 1,m);

    ans *= (matb[0][0] + matb[0][1]) % m;

    printf("%lld\n",ans % m);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:78:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld %lld %lld",&a,&b,&m);
     ^