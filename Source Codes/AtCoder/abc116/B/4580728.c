#include <stdio.h>
int f(int n){
    return n%2 ? 3*n+1 : n/2;
}
int main(void){
    int a[1000000], i=1, j;
    scanf("%d", &a[0]);
    while(1){
        a[i] = f(a[i-1]);
        for(j=0; j<i; j++)
            if(a[j] == a[i]){
                printf("%d\n", i+1);
                return 0;
            }
        i++;
    }
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &a[0]);
     ^