#include <stdio.h>
#include <string.h>


int main(void){
    int N;
    scanf("%d",&N);
    char po[350][350];
    for(int i=0;i<N;i++)scanf("%s",po[i]);
    int ans=0;
    for(int i=0;i<N;i++){
        int flag=1;
        for(int j=0;j<N;j++)for(int k=0;k<N;k++){
        if(po[(i+j)%N][k]!=po[(k+i)%N][j]){flag=0;/*printf("%c %c\n",po[(i+j)%N][k],po[k][j]);*/}
    }
        if(flag==1)ans+=N;
    }
    printf("%d",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N);
     ^
./Main.c:9:25: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(int i=0;i<N;i++)scanf("%s",po[i]);
                         ^