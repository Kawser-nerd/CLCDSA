#include <stdio.h>
long lucas(int n);
int main(void){
    int n;
    scanf("%d",&n);
    
    long ans = lucas(n);
    printf("%ld\n",ans);
    return 0;
}

long lucas(int n){
    long l[100];
    l[0] = 2;
    l[1] = 1;
    int i = 2;
    while(i<=n)
    {
        l[i] = l[i-1]+l[i-2];
        i++;
    }
    return l[i-1];
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^