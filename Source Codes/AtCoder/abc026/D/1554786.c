#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define M_PI 3.14159265359

long double A,B,C;

long double nibutan(long double a,long double b){
    long double mid=(a+b)/2;
    if(fabsl(A*mid+B*sin(C*M_PI*mid)-100.0f)<0.0000001f)return mid;
    if(A*mid+B*sin(C*M_PI*mid)-100.0f>0)return nibutan(a,mid);
    return nibutan(mid,b);
}

int main(void){
    scanf("%Lf %Lf %Lf",&A,&B,&C);
    printf("%.114Lf\n",nibutan(0,100));
    return 0;
} ./Main.c:4:0: warning: "M_PI" redefined
 #define M_PI 3.14159265359
 ^
In file included from ./Main.c:3:0:
/usr/include/math.h:372:0: note: this is the location of the previous definition
 # define M_PI  3.14159265358979323846 /* pi */
 ^
./Main.c: In function ‘main’:
./Main.c:16:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%Lf %Lf %Lf",&A,&B,&C);
     ^