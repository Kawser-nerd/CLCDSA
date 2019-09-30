#include <stdio.h>
#include <stdlib.h>
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int f[10][10]={0};
    int i,j,k;
    for(i=0;i<m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        f[a-1][b-1]=1;
        f[b-1][a-1]=1;
    }
    for(i=0;i<n;i++){
        int cnt=0;
        int ff[10]={0};
        for(j=0;j<n;j++){
            if(f[i][j]){
                for(k=0;k<n;k++){
                    if(i!=k&&!f[i][k]&&f[j][k]){
                        ff[k]=1;
                    }
                }
            }
        }
        for(j=0;j<n;j++){
            if(ff[j])cnt++;
        }
        printf("%d\n",cnt);
    }
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&n,&m);
     ^
./Main.c:10:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d",&a,&b);
         ^