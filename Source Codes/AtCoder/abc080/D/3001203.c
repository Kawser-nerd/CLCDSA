#include <stdio.h>
int N,C;
    int s[100005],t[100005],c[100005];
    int sm[200002];
    int tt[200002];
int main(){
    scanf("%d%d",&N,&C);
    for(int i=0; i<N; i++)scanf("%d%d%d",&s[i],&t[i],&c[i]);

    for(int i=1; i<=C; i++){
        for(int j=0; j<200002; j++)tt[j]=0;
        for(int j=0; j<N; j++){
            if(c[j]==i){
                tt[s[j]*2-1]++;
                tt[t[j]*2]--;
            }
        }
        for(int j=1; j<200002; j++){
            tt[j]+=tt[j-1];
        }
        for(int j=0;j<200002;j++){
            if(tt[j]>0)sm[j]++;
        }
    }
    int max=0;
    for(int i=0; i<200002; i++)if(sm[i]>max)max=sm[i];
    printf("%d\n",max);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&N,&C);
     ^
./Main.c:8:27: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(int i=0; i<N; i++)scanf("%d%d%d",&s[i],&t[i],&c[i]);
                           ^