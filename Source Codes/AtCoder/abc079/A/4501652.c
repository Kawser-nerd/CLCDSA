#include<stdio.h>
#include<string.h>
int main(void){
    int A,B,C,D,E,X,cou=0,v[3];
    char S[10];
    scanf("%d",&A);
    B=A/1000;
    C=A/100-B*10;
    D=A/10-A/100*10;
    E=A%10;
    if((B==C)&&(C==D)){
        printf("Yes");
    }else if((C==D)&&(D==E)){
        printf("Yes");
    }else{
        printf("No");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&A);
     ^