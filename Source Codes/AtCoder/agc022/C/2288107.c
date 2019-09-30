#include <stdio.h>

int main(void){
    int N;
    scanf("%d",&N);
    int a[N];
    int b[N];
    for(int i=0;i<N;i++)scanf("%d",&a[i]);
    for(int i=0;i<N;i++){scanf("%d",&b[i]);if(a[i]!=b[i]&&b[i]*2>=a[i]){printf("-1");return 0;}}
    long long int d[51][51];
    for(int i=0;i<51;i++)for(int j=0;j<51;j++)d[i][j]=3223372036854775807;
    for(int i=0;i<51;i++)for(int j=50;j>=1;j--){d[i][i%j]=(long long int)1<<j;}
    for(int i=0;i<51;i++)d[i][i]=0;
    long long int maxcost=1;
    long long int ans=0;
    while(maxcost!=0){
    maxcost=0;
    for(int k=0;k<51;k++)for(int i=0;i<51;i++)for(int j=0;j<51;j++)if(d[i][j]>d[i][k]+d[k][j])d[i][j]=d[i][k]+d[k][j];
    for(int i=0;i<N;i++)if(a[i]!=b[i]&&maxcost<d[a[i]][b[i]])maxcost=d[a[i]][b[i]];
    for(int i=1;;i++){
        if((maxcost>>i)==0)break;
        else{
            int buri=(maxcost>>i)%2;
            if(buri==1)for(int j=0;j<51;j++)d[j][j%i]=0;
        }
    }
    ans|=maxcost;
    }
    printf("%lld",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N);
     ^
./Main.c:8:25: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(int i=0;i<N;i++)scanf("%d",&a[i]);
                         ^
./Main.c:9:26: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(int i=0;i<N;i++){scanf("%d",&b[i]);if(a[i]!=b[i]&&b[i]*2>=a[i]){printf("-1");return 0;}}
                          ^