#include<cstdio>
using namespace std;
int n,m,d,x[30][100001],a,ans[100001],ans2[100001];
int main(){
    scanf("%d %d %d",&n,&m,&d);
    for(int i=0;i<=n;i++){
        x[0][i]=i;
        ans[i]=i;
    }
    for(int i=0;i<m;i++){
        scanf("%d",&a);
        x[0][a]^=x[0][a+1];
        x[0][a+1]^=x[0][a];
        x[0][a]^=x[0][a+1];
        for(int j=1;j<=n;j++){
        }
    }
    if(1&d){
        for(int i=1;i<=n;i++){
            ans[i]=x[0][ans[i]];
        }
    }
    for(int i=1;i<30;i++){
        for(int j=1;j<=n;j++){
            x[i][j]=x[i-1][x[i-1][j]];
        }
        if((1<<i)&d){
            for(int j=1;j<=n;j++){
                ans[j]=x[i][ans[j]];
            }
        }
    }
    for(int i=1;i<=n;i++){
        ans2[ans[i]]=i;
    }
    for(int i=1;i<=n;i++){
        printf("%d\n",ans2[i]);
    }
}