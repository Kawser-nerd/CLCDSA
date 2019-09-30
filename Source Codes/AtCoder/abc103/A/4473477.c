#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

int abs(int t){
    return t>0 ? t:-t;
}

int main(){
    int A1,A2,A3;
    scanf("%d %d %d",&A1,&A2,&A3);
    int max=0;
    max = max>abs(A1-A2) ? max:abs(A1-A2);
    max = max>abs(A2-A3) ? max:abs(A2-A3);
    max = max>abs(A3-A1) ? max:abs(A3-A1);
    printf("%d",max);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d",&A1,&A2,&A3);
     ^