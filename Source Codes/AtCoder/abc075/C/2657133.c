#include <stdio.h>
#include <stdbool.h>

int N,M,i,j;
bool graph[55][55];
bool visited[55];
int a[50],b[50];

void dfs(int v)
{
    // ???????
    int v2; 

    // ?v???????
    visited[v] = true;

    for(v2=0;v2<N;v2++){
        // 2????????????
        if( graph[v][v2] == false ){
            continue;
        }
        // ?????
        if( visited[v2] == true ){
            continue;
        }
        // ?v???v2????????v2???????v2?????????
        dfs(v2);
    }

}

int main()
{
    scanf("%d%d",&N,&M);

    for(i=0;i<M;i++){
        scanf("%d%d",&a[i],&b[i]);
        a[i]--;
        b[i]--;
        graph[a[i]][b[i]] = true;
        graph[b[i]][a[i]] = true;
    }

    int count = 0;

    for(i=0;i<M;i++){
        // ????????
        graph[a[i]][b[i]] = false;
        graph[b[i]][a[i]] = false;

        // ??????????
        for(j=0;j<N;j++){
            visited[j] = false;
        }

        // ??????
        dfs(0);

        bool bridge = false;
        for(j=0;j<N;j++){
            if( visited[j] == false ){
                bridge = true;
            }
        }
        if( bridge ){
            count++;
        }

        // ?????????
        graph[a[i]][b[i]] = true;
        graph[b[i]][a[i]] = true;

    }

    printf("%d\n",count);

} ./Main.c: In function ‘main’:
./Main.c:34:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&N,&M);
     ^
./Main.c:37:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d",&a[i],&b[i]);
         ^