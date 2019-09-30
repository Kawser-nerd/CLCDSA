#include <stdio.h>
int main(void){
    int a[4][4],i,j,tf=0;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<4;i++){
        for(j=0;j<3;j++){
            if(a[i][j]!=a[i][j+1]) tf++;
        }
    }
    for(j=0;j<4;j++){
        for(i=0;i<3;i++){
            if(a[i][j]!=a[i+1][j]) tf++;
        }
    }
    if(tf==24) printf("GAMEOVER\n");
    else printf("CONTINUE\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d",&a[i][j]);
             ^