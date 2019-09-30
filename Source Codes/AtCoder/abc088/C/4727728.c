#include <stdio.h>
int main(void){
    // Your code here!
    int grid[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&grid[i][j]);
        }
    }
    int x[3],y[3];
    x[0]=0;
    for(int i=0;i<3;i++)y[i]=grid[0][i]-x[0];
    for(int i=0;i<3;i++)x[i]=grid[i][0]-y[0];
    int flag=1;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(x[i]+y[j]!=grid[i][j]) flag=0;
        }
    }
    if(flag) puts("Yes");
    else puts("No");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d",&grid[i][j]);
             ^