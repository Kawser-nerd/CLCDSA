#include <stdio.h>
#include <stdlib.h>
int n,k;
int a[5][5];
int sol(int x, int y,int num){
    //printf("%d %d %d\n",x,y,num);
    int ans=a[x][y]^num;
    if(x==n-1){
        if(ans==0){
            return 1;
        }
        return 0;
    }
    int i;
    for(i=0;i<k;i++){
        if(sol(x+1,i,ans))return 1;
    }
    return 0;
}
int main(){
    scanf("%d %d",&n,&k);

    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<k;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<k;i++){
        if(sol(0,i,0)){
            printf("Found\n");
            return 0;
        }
    }
    printf("Nothing\n");
} ./Main.c: In function ‘main’:
./Main.c:21:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&n,&k);
     ^
./Main.c:26:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d",&a[i][j]);
             ^