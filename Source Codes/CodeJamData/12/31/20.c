#include<stdio.h>

int graph[1005][15],sources[1000],sz,visit[1005],queue[10005];

int bfs(int s)
{
    int i,j,k,l,f=0,b=0;

    for(i=0;i<1005;i++) visit[i]=0;

    queue[b++]=s;

    while(f!=b)
    {
        k=queue[f++];

        for(i=1;i<=graph[k][0];i++)
        {
            if(visit[graph[k][i]]) return 1;
            queue[b++]=graph[k][i];
            visit[graph[k][i]]=1;
        }
    }
    return 0;
}

int main()
{
    int t,n,tc,i,j,k,l;

    scanf("%d",&t);

    for(tc=1;tc<=t;tc++)
    {
        sz=0;
        char map[1002]={0};
        scanf("%d",&n);

        for(i=0;i<n;i++)
        {
            scanf("%d",&graph[i+1][0]);

            for(j=0;j<graph[i+1][0];j++)
            {
                scanf("%d",&graph[i+1][j+1]);
                map[graph[i+1][j+1]]=1;
            }
        }

        for(i=1;i<=n;i++)
        {
            if(!map[i]) sources[sz++]=i;
        }

        for(i=0;i<sz;i++)
        {
            if(bfs(sources[i])) break;
        }

        if(i==sz) printf("Case #%d: No\n",tc);
        else printf("Case #%d: Yes\n",tc);
    }


    return 0;
}
