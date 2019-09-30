#include <stdio.h>
#include <stdlib.h>
int t[30][200001];
int tmp[200001];
int a[200001];
int ans[200001];

void Swap(int a[],int x,int y){
    int tmp=a[x];
    a[x]=a[y];
    a[y]=tmp;
}

int main(){
    int n,m;
    long long d;
    scanf("%d %d %lld",&n,&m,&d);

    int i,j,k;
    for(i=1;i<=n;i++)tmp[i]=i;
    for(i=0;i<m;i++){
        scanf("%d",&a[i]);
    }
    for(i=m-1;i>=0;i--){
        Swap(tmp,a[i],a[i]+1);
    }
    for(i=1;i<=n;i++){
        t[0][i]=tmp[i];
    }
    for(i=1;i<30;i++){
        for(j=1;j<=n;j++){
            t[i][j]=t[i-1][t[i-1][j]];
        }
    }
    for(i=1;i<=n;i++)ans[i]=i;
    int x=0;
    while(d){
        if(d&1){
            for(i=1;i<=n;i++)ans[i]=t[x][ans[i]];
        }
        d=d>>1;
        x++;
    }
    for(i=1;i<=n;i++){
        printf("%d\n",ans[i]);
    }
} ./Main.c: In function ‘main’:
./Main.c:17:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %lld",&n,&m,&d);
     ^
./Main.c:22:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&a[i]);
         ^