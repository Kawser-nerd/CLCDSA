#include <stdio.h>
#include <algorithm>

using namespace std;

struct node
{
    int x, y;
} data[1000];
int conn[1000][1000];
int color[1000];
int n;
node datas[30][1000];
int dps[30];
int prev[1000], pp;
int cur[1000], cp;

int a[3000], bt[3000], b[3000], c[3000], tp;

void get_all_triangles (int r)
{
    tp = 0;
    if (r == 0)
        return;
        
    int j = 0;
    for (int i = 0; i < dps[r] && j < dps[r - 1];)
    {
        if (datas[r][i].x < datas[r - 1][j].x)
        {
            if (i + 1 < dps[r] && j < dps[r - 1])
            {
                a[tp] = i;
                bt[tp] = 0;
                b[tp] = i + 1;
                c[tp] = j;
                
                tp ++;
                i ++;
            }
            else
                break;
        }
        else
        {
            if (i < dps[r] && j + 1 < dps[r - 1])
            {
                a[tp] = i;
                bt[tp] = 1;
                b[tp] = j;
                c[tp] = j + 1;
                
                tp ++;
                j ++;
            }
            else
                break;
        }
    }
}

bool work (int r)
{
    pp = cp;
    for (int i = 0; i < pp; i ++)
        prev[i] = cur[i];
    cp = dps[r];
    for (int i = 0; i < dps[r]; i ++)
        cur[i] = -1;
    
    bool allneg = true;
    for (int i = 0; i < pp; i ++)
        if (prev[i] >= 0)
            allneg = false;
    
    get_all_triangles (r);
    
    if (allneg)
    {
        if (tp == 0)
            return true; // oops!
        
        cur[a[0]] = 0;
        if (bt[0] == 0)
            cur[b[0]] = 1;
        else
            prev[b[0]] = 1;
        prev[c[0]] = 2;
    }
    
/*
    for (int i = 0; i < tp; i ++)
        printf("%d %d %d %d\n", a[i], bt[i], b[i], c[i]);
    for (int i = 0; i < pp; i ++)
        printf("%d ", prev[i]);
    printf("\n");
    for (int j = 0; j < cp; j ++)
        printf("%d ", cur[j]);
    printf("\n");
*/
    
    while (1)
    {
        bool changed = false;
        
        for (int i = 0; i < tp; i ++)
        {
            int &aa = cur[a[i]], &bb = (bt[i] == 0? cur[b[i]] : prev[b[i]]), &cc = prev[c[i]];
            
            if (aa != -1 && aa == bb)
                return false;
            if (aa != -1 && aa == cc)
                return false;
            if (cc != -1 && cc == bb)
                return false;
            if ((aa == -1) + (bb == -1) + (cc == -1) == 1)
            {
                changed = true;
                if (aa == -1)
                    aa = 3 - bb - cc;
                if (bb == -1)
                    bb = 3 - aa - cc;
                if (cc == -1)
                    cc = 3 - bb - aa;
            }
        }
        if (!changed)
        {
/*
            printf("r = %d\n", r);
    for (int i = 0; i < pp; i ++)
        printf("%d ", prev[i]);
    printf("\n");
    for (int j = 0; j < cp; j ++)
        printf("%d ", cur[j]);
    printf("\n");
*/
    
            return true;
        }
    }
}

bool check_3 ()
{
    for (int i = 0; i < 30; i ++)
        dps[i] = 0;
    for (int i = 0; i < n; i ++)
        datas[data[i].y - 1][dps[data[i].y - 1] ++] = data[i];
    cp = 0;
    for (int i = 0; i < 30; i ++)
        if (!work(i))
            return false;
    return true;
}

bool operator < (const node& a, const node& b)
{
    return a.x < b.x;
}

bool check_1 ()
{
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < n; j ++)
            if (conn[i][j])
                return false;
    return true;
}

bool dfs (int x, int c)
{
    color[x] = c;
    for (int i = 0; i < n; i ++)
        if (conn[x][i])
        {
            if (color[i] == c)
                return false;
            if (color[i] == -1 && !dfs(i, !c))
                return false;
        }
    return true;
}

bool check_2 ()
{
    for (int i = 0; i < n; i ++)
        color[i] = -1;
    for (int i = 0; i < n; i ++)
        if (color[i] == -1 && !dfs(i, 0))
            return false;
    return true;
}

int main ()
{
    int t, ct = 0;
    
    for (scanf ("%d", &t); t > 0; t --)
    {
        scanf ("%d", &n);
        for (int i = 0; i < n; i ++)
            scanf ("%d%d", &data[i].x, &data[i].y);
        sort(data, data + n);
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < n; j ++)
                conn[i][j] = 0;
        for (int i = 0; i < n; i ++)
        {
            for (int k = data[i].y - 1; k <= data[i].y + 1; k ++)
            {
                int j;
                for (j = i + 1; j < n; j ++)
                    if (data[j].y == k)
                        break;
                conn[i][j] = conn[j][i] = 1;
            }
        }
        
        int ans;
        if (check_1())
            ans = 1;
        else
            if (check_2())
                ans = 2;
            else
                if (check_3())
                    ans = 3;
                else
                    ans = 4;
        printf("Case #%d: %d\n", ++ ct, ans);
    }
    
    return 0;
}
/*
10

7
1 1
2 2
3 1
4 1
5 2
6 1
7 2

9
1 1
2 2
3 1
4 3
5 1
6 2
7 1
8 3
9 2

*/
