#include<stdio.h>
    #include<string.h>
    int main(void){
    int A,B;
    double C;
    scanf("%d",&A);
    C=(double)A/1000.0;
    if(C<0.1){
        printf("00\n");
    }else if(C<1){
        C=C*10;
        printf("0%.0f\n",C);


    }else if(C<=5){
        C=C*10;
        printf("%.0f\n",C);
        
    }else if((C>=6)&&(C<=30)){
        printf("%.0f\n",C+50);
    }else if((C>=35)&&(C<=70)){
        printf("%.0f\n",(C-30)/5+80);
    }else{
        printf("89\n");
    }
    return 0;
    } ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&A);
     ^