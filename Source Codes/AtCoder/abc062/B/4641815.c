#include <stdio.h>
int main(void){
    char s[101][101];
    int h,w,i,j;
    scanf("%d%d",&h,&w);
    for(i=0;i<h;i++){
        scanf("%s",s[i]);
    }
    for(i=0;i<h+2;i++){
        if(i==0 || i==h+1){
            for(j=0;j<w+2;j++){
                printf("#");
            }
            printf("\n");
        }
        else printf("#%s#\n",s[i-1]);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&h,&w);
     ^
./Main.c:7:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s",s[i]);
         ^