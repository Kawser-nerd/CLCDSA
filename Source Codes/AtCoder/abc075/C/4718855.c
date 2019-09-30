#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define MIN 1E9
#define MAX -10000000

bool graph[60][60];
bool lg[60]={false};
int n,m,a[100],b[100];

void dfs(int x){
    if(lg[x]) return;
    lg[x]=true;
    for(int i=0;i<n;i++){
        if(graph[x][i]){
            dfs(i);
        }
    }
}

int main(void){
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d %d",&a[i],&b[i]);
        a[i]--;b[i]--;
        graph[a[i]][b[i]]=true;
        graph[b[i]][a[i]]=true;
    }
    int ans=0;
    bool connected=true;
    for(int i=0;i<m;i++){
        graph[a[i]][b[i]]=false;
        graph[b[i]][a[i]]=false;

        for(int j=0;j<n;j++)lg[j]=false;

        dfs(0);
        bool connect=false;
        for(int j=0;j<n;j++){
            if(!lg[j]) connect=true;
        }
        if(connect) ans+=1;

        graph[a[i]][b[i]]=true;
        graph[b[i]][a[i]]=true;
    }
    printf("%d",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:24:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&n,&m);
     ^
./Main.c:26:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d",&a[i],&b[i]);
         ^