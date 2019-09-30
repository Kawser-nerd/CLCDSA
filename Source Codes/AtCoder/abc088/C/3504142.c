#include <stdio.h>
int main(){
    int i,j,a[3][3];
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            scanf("%d",&a[i][j]);
        }
    }
    if(a[0][0]-a[0][1]==a[1][0]-a[1][1]&&a[0][0]-a[0][1]==a[2][0]-a[2][1]&&a[2][0]-a[2][1]==a[1][0]-a[1][1]&&
       a[0][0]-a[0][2]==a[1][0]-a[1][2]&&a[0][0]-a[0][2]==a[2][0]-a[2][2]&&a[2][0]-a[2][2]==a[1][0]-a[1][2]&&
       a[0][1]-a[0][2]==a[1][1]-a[1][2]&&a[0][1]-a[0][2]==a[2][1]-a[2][2]&&a[1][1]-a[1][2]==a[2][1]-a[2][2]&&
       a[0][0]-a[1][0]==a[0][1]-a[1][1]){
           printf("Yes");
       }else{
           printf("No");
       }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d",&a[i][j]);
             ^