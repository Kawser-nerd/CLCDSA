#include <stdio.h>
int main(void){
    int N,M,D;
    scanf("%d %d %d",&N,&M,&D);
    int A[M];
    for(int i=0;i<M;i++)scanf("%d",&A[i]);
    int po[N];
    for(int i=0;i<N;i++)po[i]=i+1;
    for(int i=M-1;i>=0;i--){
        int tmp=po[A[i]];
        po[A[i]]=po[A[i]-1];
        po[A[i]-1]=tmp;
    }
    int ans[N];
    int buri[N];
    int size;
    for(int i=0;i<N;i++)ans[i]=-1;
    for(int i=0;i<N;i++){
        if(ans[i]==-1){
            int unpo=po[i];
            buri[0]=i+1;
            size=1;
            while(unpo!=i+1){
                buri[size]=unpo;
                unpo=po[unpo-1];
                size++;
            }
            for(int i=0;i<size;i++){
                ans[buri[i]-1]=buri[(i+D)%size];
            }
        }
        printf("%d\n",ans[i]);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d",&N,&M,&D);
     ^
./Main.c:6:25: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(int i=0;i<M;i++)scanf("%d",&A[i]);
                         ^