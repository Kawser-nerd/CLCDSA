#include <stdio.h>
#include <string.h>
int main(void){
    char s[51][51];
    int h,w,i,j,b;
    scanf("%d%d",&h,&w);
    for(i=0;i<h;i++){
        scanf("%s",s[i]);
    }
    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
            if(s[i][j]=='.'){
                b=0;
                    if(s[i-1][j-1]=='#') b++;
                    if(s[i-1][j]=='#') b++;
                    if(s[i-1][j+1]=='#') b++;
                    if(s[i+1][j-1]=='#') b++;
                    if(s[i+1][j]=='#') b++;
                    if(s[i+1][j+1]=='#') b++;
                    if(s[i][j-1]=='#') b++;
                    if(s[i][j+1]=='#') b++;
                s[i][j]=b+0x30;
            }
        }
        printf("%s\n",s[i]);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&h,&w);
     ^
./Main.c:8:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s",s[i]);
         ^