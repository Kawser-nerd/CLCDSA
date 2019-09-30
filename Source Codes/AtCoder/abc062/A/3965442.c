#include <stdio.h>
int main(void){
    int a[]={0,1,3,1,2,1,2,1,1,2,1,2,1};
    int x,y;
    scanf("%d%d",&x,&y);
    if(a[x]==a[y]) printf("Yes");
    else printf("No");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&x,&y);
     ^