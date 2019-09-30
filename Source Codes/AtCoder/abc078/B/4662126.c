#include <stdio.h>
int main(void){
    int x,y,z,p=0;
    scanf("%d%d%d",&x,&y,&z);
    while(x>=y+2*z){
        p++;
        x-=y+z;
    }
    printf("%d\n",p);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&x,&y,&z);
     ^