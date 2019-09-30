#include <stdio.h>

int main(void){
    int i, j=0, t, p, c;
    scanf("%d %d",&t,&p);
    int a[p];
    for(i=0; i<p; i++) scanf("%d",&a[i]);
    scanf("%d",&c);
    int b[c], rem = p-c;
    for(i=0; i<c; i++) scanf("%d",&b[i]);
    i=0;
    for(; j<c; j++){
        if(b[j] < a[i]){
            printf("no\n");
            return 0;
        }
        while(a[i++]+t < b[j]){
            if(p == i || --rem < 0){
                printf("no\n");
                return 0;
            }
        }
    }
    printf("yes\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&t,&p);
     ^
./Main.c:7:24: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(i=0; i<p; i++) scanf("%d",&a[i]);
                        ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&c);
     ^
./Main.c:10:24: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(i=0; i<c; i++) scanf("%d",&b[i]);
                        ^