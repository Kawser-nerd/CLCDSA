#include <stdio.h>
#include <stdlib.h>

long comb(long n){
    return n*(n-1)/2;
}

int compare_int(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int a[n];
    int sum[n];
    int i;
    long result = 0;
    for(i=0;i<n;i++) scanf("%d", &a[i]);
    sum[0] = a[0] % m;
    for(i=1;i<n;i++) sum[i] = (sum[i-1] + a[i]) % m;
    qsort(sum, n, sizeof(int), compare_int);
    int now = 0;
    for(i=1;i<n;i++){
        if(sum[i]==sum[i-1]) now++;
        else if(sum[i-1]==0){
            result += (now+1)*(now+2)/2;
            now = 0;
        }else{
            if(now>=1) result += comb(now+1);
            now = 0;
        }
    }
    if(sum[n-1]==0) result += comb(now+2);
    else if(now>=1) result += comb(now+1);
    
    printf("%ld", result);
    


    return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &n, &m);
     ^
./Main.c:21:22: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(i=0;i<n;i++) scanf("%d", &a[i]);
                      ^