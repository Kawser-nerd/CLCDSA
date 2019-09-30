#include <stdio.h>

int main()
{   int h,w;
    scanf("%d%d",&h,&w);
    char s[h][w+1];
    for(int i=0;i<h;i++){
        scanf("%s",s[i]);
    }
    int grid[52][52]={0};
    for(int i=0;i<=h;i++){
        for(int j=0;j<=w;j++){
            int cnt=0;
            if(s[i-1][j-1]=='#'){
                cnt++;
            }
            if(s[i][j-1]=='#'){
                cnt++;
            }
            if(s[i+1][j-1]=='#'){
                cnt++;
            }
            if(s[i-1][j]=='#'){
                cnt++;
            }
            if(s[i][j]=='#'){
                grid[i][j]=-1;
                continue;
            }
            if(s[i+1][j]=='#'){
                cnt++;
            }
            if(s[i-1][j+1]=='#'){
                cnt++;
            }
            if(s[i][j+1]=='#'){
                cnt++;
            }if(s[i+1][j+1]=='#'){
                cnt++;
            }
            grid[i][j]=cnt;
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(grid[i][j]==-1){
                printf("#");
            }else{
                printf("%d",grid[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&h,&w);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s",s[i]);
         ^