#include<cstdio>
using namespace std;
int main(){
    int n,m,g[10][10]={},a,b,x[10]={},cnt;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d %d",&a,&b);
        a--;
        b--;
        g[a][b]=g[b][a]=1;
    }
    for(int i=0;i<n;i++){
        cnt=0;
        for(int j=0;j<n;j++){
            x[j]=0;
        }
        for(int j=0;j<n;j++){
            if(g[i][j]){
                for(int k=0;k<n;k++){
                    if(g[j][k]){
                        x[k]=1;
                    }
                }
            }
        }
        for(int j=0;j<n;j++){
            if(i==j||g[i][j]){
                x[j]=0;
            }
        }
        for(int j=0;j<n;j++){
            cnt+=x[j];
        }
        printf("%d\n",cnt);
    }
}