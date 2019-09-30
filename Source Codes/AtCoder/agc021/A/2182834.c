#include<stdio.h>

int get_keta(long long n);
int all_9(long long n);
int saijoui(long long n, int keta);

int main()
{
    long long n;
    int keta;

    scanf("%lld", &n);
    keta = get_keta(n);

    if(all_9(n)){
        printf("%d\n", saijoui(n, keta) + 9 * (keta-1));
    }else{
        printf("%d\n", saijoui(n, keta)-1+(keta-1) * 9);
    }
    
    return 0;
}

int get_keta(long long n)
{
    int keta = 0;
    while(n > 0) {n /= 10; keta++;}
    return keta;
}

int all_9(long long n)
{
    int cnt = 0;

    while(n > 9){
        if(n % 10 != 9) return 0;
        n /= 10;
        cnt++;
    }

    return 1;
}

int saijoui(long long n, int keta)
{
    int i;
    for(i = 0; i < keta-1; i++) n /= 10;
    return (int)n;
} ./Main.c: In function ‘main’:
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld", &n);
     ^