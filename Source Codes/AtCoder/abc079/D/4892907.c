#include <stdio.h>

int main()
{   int h,w;
    scanf("%d%d",&h,&w);
    int c[10][10];
    int a[h][w];
    
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            scanf("%d",&c[i][j]);
        }
    }
    
    long long ans=0;
    for(int k=0;k<10;k++){
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                if(c[i][j]>c[i][k]+c[k][j]){
                    c[i][j]=c[i][k]+c[k][j];   
                }
            }
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            scanf("%d",&a[i][j]);
            if(a[i][j]>-1){
                ans+=c[a[i][j]][1];
            }
        }
    }
    printf("%lld",ans);
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&h,&w);
     ^
./Main.c:12:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d",&c[i][j]);
             ^
./Main.c:28:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d",&a[i][j]);
             ^