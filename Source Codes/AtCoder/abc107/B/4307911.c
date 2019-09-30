#include <stdio.h>
int main(){
    int h,w;
    scanf("%d%d",&h,&w);
    char field[h][w];
    int checkh[h],checkw[w];
    for (int i=0;i<h;i++){
        scanf("%c",&field[i][0]);
        for (int j=0;j<w;j++){
            scanf("%c",&field[i][j]);
        }
    }
    for (int i=0;i<h;i++){
        checkh[i]=0;
        for (int j=0;j<w;j++){
            if (field[i][j]=='#'){
                checkh[i]=1;
                break;
            }
        }
        if (checkh[i]==1){
            continue;
        }
    }
    for (int j=0;j<w;j++){
        checkw[j]=0;
        for (int i=0;i<h;i++){
            if (field[i][j]=='#'){
                checkw[j]=1;
                break;
            }
        }
        if (checkw[j]==1){
            continue;
        }
    }
    for (int i=0;i<h;i++){
        if (checkh[i]){
            for (int j=0;j<w;j++){
                if (checkw[j]){
                    printf("%c",field[i][j]);
                }
            }
            printf("\n");
        }
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&h,&w);
     ^
./Main.c:8:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%c",&field[i][0]);
         ^
./Main.c:10:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%c",&field[i][j]);
             ^