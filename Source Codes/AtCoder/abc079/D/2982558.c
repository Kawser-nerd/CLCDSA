#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

int main(void){
    int h,w,ans=0;
    scanf("%d%d",&h,&w);
    int c[10][10];
    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){
            scanf("%d",&c[i][j]);
        }
    }
    for (int k=0; k<10; k++){
        for (int i=0; i<10; i++){
            for (int j=0; j<10; j++){
                if (c[i][j]>c[i][k]+c[k][j]){
                    c[i][j]=c[i][k]+c[k][j];
                }
            }
        }
    }
    for (int i=0; i<h; i++){
        for (int i=0; i<w; i++){
            int a;
            scanf("%d",&a);
            if (a!=-1){
                ans+=c[a][1];
            }
        }
    }
    printf("%d\n",ans);
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&h,&w);
     ^
./Main.c:14:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d",&c[i][j]);
             ^
./Main.c:29:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d",&a);
             ^