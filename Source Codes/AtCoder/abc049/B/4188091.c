#include<stdio.h>
int main(void){
    int h,w,i,j;
    char s[101][101];
    scanf("%d%d",&h,&w);
    for(i=0;i<h;i++){
        scanf("%s",s[i]);
    }
    for(i=0;i<h;i++){
        printf("%s\n%s\n",s[i],s[i]);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&h,&w);
     ^
./Main.c:7:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s",s[i]);
         ^