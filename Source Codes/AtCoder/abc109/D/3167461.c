#include <stdio.h>

int main(void)
{
    int h,w,a[500][500],n=0,t[500][500],i,j;
    scanf("%d%d",&h,&w);
    for(i=0;i<h;++i){
        for(j=0;j<w;++j){
            scanf("%d",&a[i][j]);
            t[i][j]=a[i][j];
        }
    }
    for(i=0;i<h-1;++i){
        for(j=0;j<w;++j){
            if(t[i][j]%2){
                --t[i][j];
                ++t[i+1][j];
                ++n;
            }
        }
    }
    for(i=0;i<w-1;++i){
        if(t[h-1][i]%2){
            --t[h-1][i];
            ++t[h-1][i+1];
            ++n;
        }
    }
    printf("%d\n",n);
    for(i=0;i<h-1;++i){
        for(j=0;j<w;++j){
            if(a[i][j]%2){
                --a[i][j];
                ++a[i+1][j];
                printf("%d %d %d %d\n",i+1,j+1,i+2,j+1);
            }
        }
    }
    for(i=0;i<w-1;++i){
        if(a[h-1][i]%2){
            --a[h-1][i];
            ++a[h-1][i+1];
            printf("%d %d %d %d\n",h,i+1,h,i+2);
        }
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&h,&w);
     ^
./Main.c:9:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d",&a[i][j]);
             ^