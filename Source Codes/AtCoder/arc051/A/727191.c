#include<stdio.h>

#define  NI(A) ((A) * (A))
int main(void){
    int i,j,k,x1,x2,x3,y1,y2,y3,r;

    scanf("%d %d %d %d %d %d %d",&x1,&y1,&r,&x2,&y2,&x3,&y3);

    if(x1 + r <= x3 && x1 - r >= x2 && y1 + r <= y3 && y1 - r >= y2)
        printf("NO\n");
    else
        printf("YES\n");

    r *= r;
    if(NI(x1 - x2) + NI(y1 - y2)<= r && NI(x1 - x2) + NI(y1 - y3)<= r && NI(x1 - x3) + NI(y1 - y2)<= r && NI(x1 - x3) + NI(y1 - y3)<= r)
        printf("NO\n");
    else
        printf("YES\n");

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d %d %d %d %d",&x1,&y1,&r,&x2,&y2,&x3,&y3);
     ^