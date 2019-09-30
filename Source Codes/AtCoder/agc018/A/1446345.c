#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gcd(int a, int b){
    int temp;
    while (b != 0){
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int a[n],i;
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    if(n==1){
        if(k!=a[0]) printf("IMPOSSIBLE\n");
        else printf("POSSIBLE\n");
        return 0;
    }
    int max=a[0];
    for(i=1;i<n;i++) if(a[i]>max) max=a[i];
    if(k>max){
        printf("IMPOSSIBLE\n");
        return 0;
    }
    int small=-1;
    small=gcd(a[0],a[1]);
    for(i=2;i<n;i++) small=gcd(small,a[i]);
    if(k%small==0) printf("POSSIBLE\n");
    else printf("IMPOSSIBLE\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:19:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&n,&k);
     ^
./Main.c:21:22: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(i=0;i<n;i++) scanf("%d",&a[i]);
                      ^