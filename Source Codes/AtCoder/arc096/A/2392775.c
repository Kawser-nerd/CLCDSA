#include<stdio.h>

int main(){
    int A,B,C,X,Y;
    scanf("%d %d %d %d %d",&A,&B,&C,&X,&Y);                                                    
    int a,b,c;
    a = A*X+B*Y;
    b = 2*C*X;
    if(X<Y)     b+=B*(Y-X);
    c = 2*C*Y;
    if(Y<X)     c+=A*(X-Y);
    if(a>b)     a=b;
    if(a>c)     a=c;
    printf("%d",a);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d %d %d",&A,&B,&C,&X,&Y);                                                    
     ^