#include <stdio.h>
int main(){
    int h,w;
    scanf("%d%d", &h,&w);
    char pic[h+2][w+2],c;
    for (int i=1;i<h+1;i++){
        scanf("%c",&c);
        for (int j=1;j<w+1;j++){
            scanf("%c",&pic[i][j]);
        }
    }
    for (int i=0;i<h+2;i++){
        for (int j=0;j<w+2;j++){
            if (i==0 || i==h+1 || j==0 || j==w+1){
                pic[i][j]='#';
            }
            printf("%c",pic[i][j]);
        }
        printf("\n");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &h,&w);
     ^
./Main.c:7:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%c",&c);
         ^
./Main.c:9:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%c",&pic[i][j]);
             ^