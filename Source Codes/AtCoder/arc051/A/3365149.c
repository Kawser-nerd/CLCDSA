#include <stdio.h>
int main(void){
    int x1,y1,r,x2,y2,x3,y3;
    scanf("%d%d%d%d%d%d%d",&x1,&y1,&r,&x2,&y2,&x3,&y3);
    if (x2<=x1-r && x3>=x1+r && y2<=y1-r && y3>=y1+r){
        printf("NO\n");
    } else {
        printf("YES\n");
    }
    if ((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)<=r*r && (x3-x1)*(x3-x1)+(y2-y1)*(y2-y1)<=r*r && (x2-x1)*(x2-x1)+(y3-y1)*(y3-y1)<=r*r && (x3-x1)*(x3-x1)+(y3-y1)*(y3-y1)<=r*r ){
        printf("NO\n");
    } else {
        printf("YES\n");
    }



    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d%d%d%d%d",&x1,&y1,&r,&x2,&y2,&x3,&y3);
     ^