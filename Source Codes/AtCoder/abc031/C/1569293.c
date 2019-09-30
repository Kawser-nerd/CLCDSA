#include <stdio.h>
 
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
        if(i!=j&&po<((i<j?i:j)%2==1?gusu[(i>j?i:j)]-gusu[(i<j?i:j)-1]:kisu[(i>j?i:j)]-kisu[(i<j?i:j)-1])){po=((i<j?i:j)%2==1?gusu[(i>j?i:j)]-gusu[(i<j?i:j)-1]:kisu[(i>j?i:j)]-kisu[(i<j?i:j)-1]);karians=((i<j?i:j)%2==0?gusu[(i>j?i:j)]-gusu[(i<j?i:j)-1]:kisu[(i>j?i:j)]-kisu[(i<j?i:j)-1]);}
    }
    if(karians>ans)ans=karians;
    po=-1145141919;
    }
    printf("%d\n",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N);
     ^
./Main.c:9:25: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(int i=0;i<N;i++)scanf("%d",&a[i]);
                         ^