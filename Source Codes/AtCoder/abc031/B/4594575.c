#include <stdio.h>
int main(void){
    // Your code here!
    int l,h,n,x;
    scanf("%d%d%d",&l,&h,&n);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        if(l<=x && x<=h)
            printf("%d\n",0);
        else if(l>x)
            printf("%d\n",l-x);
        else
            printf("%d\n",-1);
    }
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&l,&h,&n);
     ^
./Main.c:7:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&x);
         ^