#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    int h,w;
    scanf("%d%d",&h,&w);
    char a[10][10];
    for (int i=0; i<h; i++){
            scanf("%s",a[i]);
    }
    for (int i=1; i<h; i++){
        for (int j=0; j<w-1; j++){
            if(a[i][j]=='#' && a[i-1][j+1]=='#'){
                printf ("Impossible\n");
                exit(0);
            }
        }
    }
    printf("Possible\n");
    return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&h,&w);
     ^
./Main.c:10:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%s",a[i]);
             ^