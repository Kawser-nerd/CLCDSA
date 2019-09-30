#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

int main(){
    int N,i;
    scanf("%d %d",&N,&i);
    printf("%d",N-i+1);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&N,&i);
     ^