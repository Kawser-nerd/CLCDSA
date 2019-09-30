#include <stdio.h>

int main(){
    int N,i;
    int a[4];
    scanf("%d",&N);
    
    for (i=0; i<4; i++) {
        a[i] = N%10;
        N = N/10;
    }
    if (((a[0] == a[1])&&(a[0]==a[2]))||((a[1] == a[2])&&(a[2]==a[3]))) {
        printf("Yes");
    }else{
        printf("No");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N);
     ^