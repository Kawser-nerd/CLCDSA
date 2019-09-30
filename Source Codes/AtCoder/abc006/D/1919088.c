#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    int c[30000];
    int INF=1000000;
    scanf("%d",&N);
    int i,j;
    for(i=0;i<N;i++){
        scanf("%d",&c[i]);
    }
    int min[30000];
    for(i=0;i<N;i++){
        min[i]=INF;
    }
    int len=0;
    for(i=0;i<N;i++){
        if(min[len]>c[i]){
            for(j=0;j<N;j++){
                if(min[j]>c[i]){
                    min[j]=c[i];
                    break;
                }
            }
        }else{
            min[++len]=c[i];
        }
    }
    printf("%d\n",N-(len+1));
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N);
     ^
./Main.c:12:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&c[i]);
         ^