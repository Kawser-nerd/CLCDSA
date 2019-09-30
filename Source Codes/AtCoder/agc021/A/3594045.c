#include<stdio.h>
int main(void){
    long int C,Q,R=0;
    long int j,h=0;
    scanf("%ld",&C);
    long int X[17];
    for(int i=0;i<17;i++){X[i]=0;}
    for(long int i=0;i<17;i++){
        X[i]=C%10;
        R+=X[i];
        C=(C-X[i])/10;
        if(C==0){j=i+1;break;}
    }
    Q=X[j-1]-1+9*(j-1);
    if(R==(Q+1)){
        printf("%ld\n",R);
    }else{
        printf("%ld\n",Q);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld",&C);
     ^