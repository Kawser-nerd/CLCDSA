#include <stdio.h>
#include <string.h>
int main(void){
    int h,w,i,j,b[111]={0};
    char a[111][111];
    scanf("%d%d",&h,&w);
    for(i=0;i<h;i++) {
        scanf("%s",a[i]);
        if(strchr(a[i],'#')==0){
            i--;
            h--;
        }
        for(j=0;j<w;j++){
            if(a[i][j]=='#') b[j]++;
        }
    }
    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
            if(b[j]!=0) printf("%c",a[i][j]);
        }
        printf("\n");
    }
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&h,&w);
     ^
./Main.c:8:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s",a[i]);
         ^