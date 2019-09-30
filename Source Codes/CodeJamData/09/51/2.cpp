#include <stdio.h>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

struct coord
{
    int x, y;
    
    coord ()
    {
    }
    
    coord (int xx, int yy)
    {
        x = xx;
        y = yy;
    }
};

const int fx[4] = {-1,  0, +1,  0};
const int fy[4] = { 0, -1,  0, +1};
int n, m;

char data[12][12];

bool canpush (int x, int y, int f)
{
    if (x + fx[f] < 0 || x + fx[f] >= n || y + fy[f] < 0 || y + fy[f] >= m)
        return false;
    if (x + fx[f ^ 2] < 0 || x + fx[f ^ 2] >= n || y + fy[f ^ 2] < 0 || y + fy[f ^ 2] >= m)
        return false;
    if (data[x + fx[f]][y + fy[f]] == '#')
        return false;
    if (data[x + fx[f ^ 2]][y + fy[f ^ 2]] == '#')
        return false;
    return true;
}

bool operator < (const coord& a, const coord& b)
{
    return a.x < b.x || a.x == b.x && a.y < b.y;
}

int boxes, _boxes;

struct node
{
    coord data[5];
    bool stable;
} start, end;

bool operator < (const node& a, const node& b)
{
    for (int i = 0; i < boxes; i ++)
    {
        if (a.data[i] < b.data[i])
            return true;
        if (b.data[i] < a.data[i])
            return false;
    }
    return false;
}

bool operator == (const node& a, const node& b)
{
    for (int i = 0; i < boxes; i ++)
    {
        if (a.data[i] < b.data[i])
            return false;
        if (b.data[i] < a.data[i])
            return false;
    }
    return true;
}

map<node, int> M;
queue<node> Q;

void getstable (node& cur)
{
    int conn[boxes];
    
    for (int i = 0; i < boxes; i ++)
        conn[i] = 0;
    conn[0] = 1;
    for (int i = 0; i < boxes - 1; i ++)
    {
        for (int j = 0; j < boxes; j ++)
            if (conn[j])
                for (int k = 0; k < boxes; k ++)
                    if (abs(cur.data[j].x - cur.data[k].x) + abs(cur.data[j].y - cur.data[k].y) <= 1)
                        conn[k] = 1;
    }
    cur.stable = true;
    for (int i = 0; i < boxes; i ++)
        if (!conn[i])
            cur.stable = false;
}

void add (node& a, int len)
{
    sort (a.data, a.data + boxes);
    if (M.find(a) == M.end())
    {
/*
        if  (a.data[0].x == 2 && a.data[0].y == 1 && a.data[1].x == 2 && a.data[1].y == 2)
        {
            printf("addlen = %d\n", len);
        }
*/
        M[a] = len;
        Q.push(a);
    }
}

int main ()
{
    int t, ct = 0;
    
    for (scanf("%d", &t); t > 0; t --)
    {
        scanf ("%d%d", &n, &m);
        
        boxes = _boxes = 0;
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < m; j ++)
            {
                do scanf("%c", data[i] + j);
                    while (data[i][j] <= ' ');
                if (data[i][j] == 'o')
                {
                    start.data[boxes ++] = coord (i, j);
                    data[i][j] = '.';
                }
                if (data[i][j] == 'x')
                {
                    end.data[_boxes ++] = coord (i, j);
                    data[i][j] = '.';
                }
                if (data[i][j] == 'w')
                {
                    start.data[boxes ++] = coord (i, j);
                    end.data[_boxes ++] = coord (i, j);
                    data[i][j] = '.';
                }
            }
        sort(start.data, start.data + boxes);
        start.stable = true;
        sort(end.data, end.data + boxes);
        
        M.clear ();
        add (start, 0);
        while (!Q.empty ())
        {
            start = Q.front ();
            Q.pop ();
            
/*
            printf("len = %d\n", M[start]);
            for (int i = 0; i < boxes; i ++)
                printf("%d %d\n", start.data[i].x, start.data[i].y);
*/
            
            int len = M[start];
            
            for (int i = 0; i < boxes; i ++)
            {
                data[start.data[i].x][start.data[i].y] = '#';
            }

            for (int i = 0; i < boxes; i ++)
                for (int k = 0; k < 4; k ++)
                    if (canpush(start.data[i].x, start.data[i].y, k))
                    {
//                        printf("canpush!\n");
                        node neo = start;
                        
                        neo.data[i].x += fx[k];
                        neo.data[i].y += fy[k];
                        
                        getstable (neo);
                        
                    for (int i = 0; i < boxes; i ++)
/*
                        printf("(%d %d)  ", neo.data[i].x, neo.data[i].y);
                        if (neo.stable)
                            printf("stable\n");
                        else
                            printf("unstable\n");
*/
                        
                        if (neo.stable || start.stable)
                        {
//                            printf("add!\n");
                            add(neo, len + 1);
                        }
                    }

            for (int i = 0; i < boxes; i ++)
            {
                data[start.data[i].x][start.data[i].y] = '.';
            }
        }
        
        if (M.find(end) == M.end())
        {
            printf("Case #%d: -1\n", ++ ct);
        }
        else
        {
            printf("Case #%d: %d\n", ++ ct, M[end]);
        }
    }
    
    return 0;
}
