#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1024
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
int map[MAX][MAX];
int n;
int floyd()
{
    int i,j,k;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            for(k = 1; k <= n; k++)
            {
                if(map[j][i] && map[i][k])map[j][k]++;
                if(map[j][k] > 1)return 1;
            }
        }
    }
    return 0;
}
int main()
{
    freopen("A-large (2).in","r",stdin);
    freopen("output.txt","w",stdout);
    int cases,case_index;
    int i,j,m,path,cons;
    scanf("%d", &cases);
    for(case_index = 1; case_index <= cases; case_index++)
    {
        scanf("%d", &n);
        memset(map, 0,sizeof(map));
        for(i = 1; i<= n; i++)
        {
            scanf("%d", &m);
            for(j = 1; j <= m; j++)
            {
                scanf("%d", &path);
                map[i][path] = 1;
            }
        }
        cons = floyd();
        if(cons)printf("Case #%d: Yes\n", case_index);
        else printf("Case #%d: No\n", case_index);
    }
    return 0;
}
