#include<stdio.h>
int main(){
    int n,i = 0;
    scanf("%d",&n);
    printf("%d\n",n);
    while(i<n){
        printf("1\n");
        i++;
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^