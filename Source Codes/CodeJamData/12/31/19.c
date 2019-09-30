#include <stdio.h>
#include <string.h>

struct edge_t
{
    int node, next;
}edges[21000];
int shthead[1100], alloc;
int N, havein[1100];

void addedge(int x, int y)
{
    edges[alloc].node=y;
    edges[alloc].next=shthead[x];
    shthead[x]=alloc++;
    havein[y]++;
}

int bfs(int src)
{
#define QUEUESIZE 1100
    static int queue[QUEUESIZE];
    static int inqueue[1100];
    int head=-1, tail=0;
    memset(inqueue, 0, sizeof(inqueue));
    queue[tail]=src;
    while(head!=tail)
    {
        int cur=queue[++head];
        int q;
        for(q=shthead[cur]; q!=-1; q=edges[q].next)
        {
            if(!inqueue[edges[q].node])
            {
                inqueue[edges[q].node]=1;
                queue[++tail]=edges[q].node;
            }
            else return 0;
        }
    }
    return 1;
}

int main()
{
    int T;
    int Tcnt=0;
    for(scanf("%d", &T); T; T--,Tcnt++)
    {
        int i;
        scanf("%d", &N);
        alloc=0;
        memset(shthead, -1, sizeof(shthead));
        memset(havein, 0, sizeof(havein));
        for(i=0; i<N; i++)
        {
            int cnt;
            int j;
            scanf("%d", &cnt);
            for(j=0; j<cnt; j++)
            {
                int b;
                scanf("%d", &b);
                b--;
                addedge(i, b);
            }
        }
        for(i=0; i<N; i++)
        {
            if(!havein[i] && !bfs(i))
            {
                printf("Case #%d: Yes\n", Tcnt+1);
                break;
            }
        }
        if(i>=N) printf("Case #%d: No\n", Tcnt+1);
    }
    return 0;
}
