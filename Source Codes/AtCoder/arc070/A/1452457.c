#include<stdio.h>
//Regular 070 C
int main(){

    int X, x;
    int point = 0;
    x = 1;

    scanf("%d", &X);
    while(point<=X){
	point += x;
	x++;
    }

    point -= x-1;
    if(point==X) printf("%d\n",x-2);
    else printf("%d\n", x-1);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &X);
     ^