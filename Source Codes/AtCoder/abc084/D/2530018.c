#include <stdio.h>
#include <math.h>

int isPrime(int n){
    int i;
    for(i=2;i<=(int)sqrt(n);i++){
        if(n%i==0) return 0;
    }
    return 1;
}

int main(){
    int q;
    scanf("%d", &q);
    int l[q+1], r[q+1];
    int i;
    for(i=1;i<=q;i++) scanf("%d %d", &l[i], &r[i]);
    int sosu_num[100002];
    for(i=0;i<=100001;i++) sosu_num[i] = 0;
    for(i=3;i<=100000;i++){
        sosu_num[i] = sosu_num[i-1];
        if(i%2==1&&isPrime(i)==1&&isPrime((i+1)/2)) sosu_num[i] += 1;
    }
    for(i=1;i<=q;i++) printf("%d\n", sosu_num[r[i]] - sosu_num[l[i]-1]);
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &q);
     ^
./Main.c:17:23: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(i=1;i<=q;i++) scanf("%d %d", &l[i], &r[i]);
                       ^