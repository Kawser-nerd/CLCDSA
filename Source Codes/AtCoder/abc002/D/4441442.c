#include<stdio.h>

int n, m;

typedef struct {
    int x;
    int y;
} relation;

relation gen_relation()
{
    relation r;
    scanf("%d", &r.x);
    scanf("%d", &r.y);
    return r;
}

int is_related(int x, int y, relation* r)
{
    int i;
    for(i = 0; i < m; i++)
    {
        if(((r[i].x == x) & (r[i].y == y)) | ((r[i].x == y) & (r[i].y == x)))
            return 1;
    }
    return 0;
}

int main()
{
    scanf("%d", &n);
    scanf("%d", &m);

    relation r[m];
    int i;
    for(i = 0; i < m; i++)
        r[i] = gen_relation();
    
    int count, max_count;
    count = 0;
    max_count = 0;

    int j, k;
    int g[n];
    int flg = 0;
    for(i = 0; i < n; i++) g[i] = 0;
    for(i = 1; i <= n; i++)
    {
        g[0] = i;
        for(k = 1; k < n; k++) g[k] = 0;
        for(j = 1; j <= n; j++)
        {
            for(k = 0; k < n; k++)
            {
                if(g[k] == 0) break;
                if(g[k] == j | !is_related(g[k], j, r))
                {
                    flg = 1;
                    break;
                }
            }
            if(!flg)
            {
                count++;
                g[count] = j;
            }
            flg = 0;
        }
        if(max_count < count)
            max_count = count;
        count = 0;
    }

    printf("%d\n", max_count + 1);
    ;
    return 0;
} ./Main.c: In function ‘gen_relation’:
./Main.c:13:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &r.x);
     ^
./Main.c:14:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &r.y);
     ^
./Main.c: In function ‘main’:
./Main.c:31:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:32:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &m);
     ^