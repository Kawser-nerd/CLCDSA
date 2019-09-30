#include <stdio.h>

int main()
{   int w,h,n;
    scanf("%d%d%d",&w,&h,&n);
    int x[n],y[n],a[n];
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&x[i],&y[i],&a[i]);
    }
    int S[h][w];
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            S[i][j]=0;
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]==1){
            for(int j=0;j<h;j++){
                for(int k=0;k<x[i];k++){
                    S[j][k]=1;
                }
            }
        }
        if(a[i]==2){
            for(int j=0;j<h;j++){
                for(int k=x[i];k<w;k++){
                    S[j][k]=1;
                }
            }
        }
        if(a[i]==4){
            for(int j=y[i];j<h;j++){
                for(int k=0;k<w;k++){
                    S[j][k]=1;
                }
            }
        }
        if(a[i]==3){
            for(int j=0;j<y[i];j++){
                for(int k=0;k<w;k++){
                    S[j][k]=1;
                }
            }
        }
    }    
    int ans=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(S[i][j]==0){
                ans++;
            }
        }
    }
    printf("%d",ans);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&w,&h,&n);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d%d",&x[i],&y[i],&a[i]);
         ^