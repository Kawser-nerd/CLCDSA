#include<stdio.h>

long long powermod(long long a,long long n,long long mod){
    long long pw;

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

int main(void){
    int fin,max,min,i,j,n,count;
    long long index[50],exl,A,B,aa[50],a[50],b,c,d[50],e[50];

    scanf("%d %lld %lld",&n,&A,&B);

    for(i = 0;i < n;i++)
        scanf("%lld",&aa[i]);

    for(i = 0;i < n;i++)
        a[i] = aa[i];

    for(i = 0;i < n;i++)
        index[i] = 0;

    max = 0;
    for(i = 1;i < n;i++){
        if(a[max] <= a[i])
            max = i;
    }

    count = 0;fin = 1;
    if(A != 1)
        do{
            min = 0;
            for(i = 1;i < n;i++){
                if(a[min] > a[i])
                    min = i;
            }
            a[min] *= A;
            index[min]++;
            count++;
            if(count == B){
                fin = 0;
                break;
            }
        }while(index[max] == 0);
    else
        fin = 0;
    for(i = 0;i < n;i++){
        for(j = n - 1;j > i;j--){
            if(a[j - 1] > a[j]){
                exl = a[j - 1];a[j - 1] = a[j];a[j] = exl;
                exl = aa[j - 1];aa[j - 1] = aa[j];aa[j] = exl;
                exl = index[j - 1];index[j - 1] = index[j];index[j] = exl;
            }
        }
    }

    if(fin){
        b = (B - count) / n;
        for(i = 0;i < n;i++){
            index[i] += b;
        }
        c = (B - count) % n;
        for(i = 0;i < c;i++){
            index[i]++;
            d[i] = aa[i];
            e[i] = index[i];
        }
        for(i = c;i < n;i++){
            aa[i - c] = aa[i];
            index[i - c] = index[i];
        }
        for(i = n - c;i < n;i++){
            aa[i] = d[i - n + c];
            index[i] = e[i - n + c];
        }
    }

    for(i = 0;i < n;i++){
        c = powermod(A,index[i],1000000007);
        printf("%lld\n",aa[i] * c % 1000000007);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:22:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %lld %lld",&n,&A,&B);
     ^
./Main.c:25:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld",&aa[i]);
         ^