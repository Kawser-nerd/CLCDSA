#include<stdio.h>
int main(void){
    int A,B;
    scanf("%d %d",&A,&B);
    if((A==2)&&(B==2)){
        printf("Yes");
    }else if(((A==4)||(A==6)||(A==9)||(A==11))&&((B==4)||(B==6)||(B==9)||(B==11))){
        printf("Yes");
    }else if(((A==1)||(A==3)||(A==5)||(A==7)||(A==8)||(A==10)||(A==12))&&((B==1)||(B==3)||(B==5)||(B==7)||(B==8)||(B==10)||(B==12))){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&A,&B);
     ^