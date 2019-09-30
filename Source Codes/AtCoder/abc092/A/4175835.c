#include<stdio.h>

int main() {
int a, b, c, d;
scanf ("%d", &a);
scanf ("%d", &b);
scanf ("%d", &c);
scanf ("%d", &d);
if (a>=b){
    a=b;
}
if (c>=d){
    c=d;
}
printf ("%d", a+c);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf ("%d", &a);
 ^
./Main.c:6:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf ("%d", &b);
 ^
./Main.c:7:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf ("%d", &c);
 ^
./Main.c:8:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf ("%d", &d);
 ^