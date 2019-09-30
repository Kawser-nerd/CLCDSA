#include <stdio.h>
int main(void){
    int h,w,i,j;
    scanf("%d%d\n",&h,&w);
    char e[h][w+1];
    for(i=0;i<h;i++){
        for(j=0;j<w+1;j++){
            scanf("%c",&e[i][j]);        }
    }
    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
            if(e[i][j]=='#'){
                int count=0;
                if(j!=0){if(e[i][j-1]=='#'){count++;}}
                if(j!=w){if(e[i][j+1]=='#'){count++;}}
                if(i!=0){if(e[i-1][j]=='#'){count++;}}
                if(i!=h-1){if(e[i+1][j]=='#'){count++;}}
                if(count==0){printf("No\n");return 0;}
            }
        }
    }
    printf("Yes\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d\n",&h,&w);
     ^
./Main.c:8:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%c",&e[i][j]);        }
             ^