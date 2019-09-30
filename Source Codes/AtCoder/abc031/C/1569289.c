#include <stdio.h>

int max(int a,int b){return a>b ? a : b;}
int min(int a,int b){return a<b?a:b;}

int main(void){
    int N;
    scanf("%d",&N);
    int a[N];
    for(int i=0;i<N;i++)scanf("%d",&a[i]);
    int kisu[N+1],gusu[N+1];
    kisu[0]=0;
    for(int i=1;i<=N;i++){if(i%2==1)kisu[i]=kisu[i-1]+a[i-1];else kisu[i]=kisu[i-1];}
    gusu[0]=0;
    for(int i=1;i<=N;i++){if(i%2==0)gusu[i]=gusu[i-1]+a[i-1];else gusu[i]=gusu[i-1];}
    int ans=-1145141919;
    int karians;
    int po=-1145141919;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
        if(i!=j&&po<(min(i,j)%2==1?gusu[max(i,j)]-gusu[min(i,j)-1]:kisu[max(i,j)]-kisu[min(i,j)-1])){po=(min(i,j)%2==1?gusu[max(i,j)]-gusu[min(i,j)-1]:kisu[max(i,j)]-kisu[min(i,j)-1]);karians=(min(i,j)%2==0?gusu[max(i,j)]-gusu[min(i,j)-1]:kisu[max(i,j)]-kisu[min(i,j)-1]);}
    }
    if(karians>ans)ans=karians;
    po=-1145141919;
    }
    printf("%d\n",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N);
     ^
./Main.c:10:25: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(int i=0;i<N;i++)scanf("%d",&a[i]);
                         ^