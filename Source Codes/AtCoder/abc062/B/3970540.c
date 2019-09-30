#include <stdio.h>
int main(){
    int h,w;
    scanf("%d%d",&h,&w);
    char s[h][w+1];
    for(int i=0;i<h;i++){
        scanf("%s",s[i]);
    }
    for(int i=0;i<=w+1;i++){
    printf("#");
    }
    printf("\n");
    for(int i=0;i<h;i++){
        printf("#%s#\n",s[i]);
    }
    for(int i=0;i<=w+1;i++){
    printf("#");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&h,&w);
     ^
./Main.c:7:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s",s[i]);
         ^