#include <stdio.h>
#include <string.h>

int fx[] = 
    {1, 1, 0, -1, -1,  0};
int fy[] =
    {0, 1, 1,  0, -1, -1};
int s, m;

int data[6003][6003];
int xx[10000];
int yy[10000];
int fb[3];

int count2;

struct fun
{
    int ecset;
    int dadx, dady;
} set[6003][6003];

int min(int x, int y){return x<y?x:y;}

bool inrange (int x, int y)
{
    return (x >= 1 && x <= s + s - 1) && (x <= s? (y >= 1 && y <= x + s - 1) : (y >= x - s + 1 && y <= s + s - 1));
}

bool atedge (int x, int y)
{
    return x == 1 || y == 1 || x == s + s - 1 || y == s + s - 1 || x - y == s - 1 || y - x == s - 1;
}


void init1 (int x, int y)
{
    set[x][y].dadx = x;
    set[x][y].dady = y;
    set[x][y].ecset = 0;
    if (x == 1 && y == 1)
        set[x][y].ecset |= 1;
    if (x == s && y == 1)
        set[x][y].ecset |= 2;
    if (x == s + s - 1 && y == s)
        set[x][y].ecset |= 4;
    if (x == s + s - 1 && y == s + s - 1)
        set[x][y].ecset |= 8;
    if (x == s && y == s + s - 1)
        set[x][y].ecset |= 16;
    if (x == 1 && y == s)
        set[x][y].ecset |= 32;
    if (y == 1 && x > 1 && x < s)
        set[x][y].ecset |= 64;
    if (x - y == s - 1 && y > 1 && y < s)
        set[x][y].ecset |= 128;
    if (x == s + s - 1 && y > s && y < s + s - 1)
        set[x][y].ecset |= 256;
    if (y == s + s - 1 && x > s && x < s + s - 1)
        set[x][y].ecset |= 512;
    if (y - x == s - 1 && x > 1 && x < s)
        set[x][y].ecset |= 1024;
    if (x == 1 && y > 1 && y < s)
        set[x][y].ecset |= 2048;
}

void init2 (int x, int y)
{
    set[x][y].dadx = x;
    set[x][y].dady = y;
}

void anc (int& x, int& y)
{
    if (x != set[x][y].dadx || y != set[x][y].dady)
    {
        anc (set[x][y].dadx, set[x][y].dady);

        int ty = set[x][y].dady;
        x = set[x][y].dadx;
        y = ty;
    }
}

void merge1 (int x1, int y1, int x2, int y2)
{
    anc(x1,y1);
    anc(x2,y2);

    if (x1 != x2 || y1 != y2)
    {
//        printf ("MERGE: %d %d %d %d\n",x1,y1,x2,y2);
        set[x2][y2].dadx = x1;
        set[x2][y2].dady = y1;

        set[x1][y1].ecset |= set[x2][y2].ecset;
    }
}

void merge2 (int x1, int y1, int x2, int y2)
{
    anc(x1,y1);
    anc(x2,y2);

    if (x1 != x2 || y1 != y2)
    {
//        printf ("MERGE: %d %d %d %d\n",x1,y1,x2,y2);
        set[x2][y2].dadx = x1;
        set[x2][y2].dady = y1;

        count2 --;
    }
}

int judge1 (int x, int y)
{
    anc(x, y);

    int cornerset[64] =
    {
        0, 0, 0, 1, 0, 1, 1, 1,
        0, 1, 1, 1, 1, 1, 1, 1,
        0, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1,
        0, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1,
    };
    int edgeset[64] =
    {
        0, 0, 0, 0, 0, 0, 0, 1,
        0, 0, 0, 1, 0, 1, 1, 1,
        0, 0, 0, 1, 0, 1, 1, 1,
        0, 1, 1, 1, 1, 1, 1, 1,
        0, 0, 0, 1, 0, 1, 1, 1,
        0, 1, 1, 1, 1, 1, 1, 1,
        0, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1,
    };
    int ans = 0;

//    printf ("JUDGE: CORNERSET %d\n", (set[x][y].ecset & 63));

    if (cornerset[set[x][y].ecset & 63])
        ans |= 1;
    if (edgeset[(set[x][y].ecset >> 6) & 63])
        ans |= 2;

    return ans;
}

int main ()
{
    int t, ct;

    scanf ("%d", &t);
    for (ct = 1; ct <= t; ct ++)
    {
        scanf ("%d%d", &s, &m);

        for (int i = 0; i < m; i ++)
        {
            scanf ("%d%d", xx+i, yy+i);
        }
        
        for (int i = 0; i < 3; i ++)
            fb[i] = 2147483647;

        memset(data, 0, sizeof(data));
         
        for (int i = 0; i < m; i ++)
        {
            data[xx[i]][yy[i]] = 1;
            init1 (xx[i], yy[i]);
            for (int j = 0; j < 6; j ++)
                if (data[xx[i] + fx[j]][yy[i] + fy[j]])
                    merge1(xx[i], yy[i], xx[i]+fx[j], yy[i]+fy[j]);

            int jj = judge1 (xx[i], yy[i]);
            if ((jj & 1) && fb[0] > i)
                fb[0] = i;
            if ((jj & 2) && fb[1] > i)
                fb[1] = i;
        }

        count2 = 1;
        init2 (0, 0);
        for (int i = 1; i <= s + s - 1; i ++)
            for (int j = 1; j <= s + s - 1; j ++)
                if (inrange(i, j) && !data[i][j])
                {
                    data[i][j] = 2;
                    init2 (i, j);
                    count2 ++;
                    for (int k = 0; k < 6; k ++)
                        if (data[i + fx[k]][j + fy[k]] == 2)
                            merge2 (i, j, i + fx[k], j + fy[k]);
                    if (atedge(i, j))
                        merge2(i, j, 0, 0);
                }

//        printf ("count2 = %d\n", count2);

        if (count2 > 1)
            fb[2] = m - 1;
        for (int i = m - 1; i > 0; i --)
        {
            data[xx[i]][yy[i]] = 2;
            init2 (xx[i], yy[i]);
            count2 ++;
            for (int j = 0; j < 6; j ++)
                if (data[xx[i] + fx[j]][yy[i] + fy[j]] == 2)
                    merge2(xx[i], yy[i], xx[i]+fx[j], yy[i]+fy[j]);
            if (atedge(xx[i], yy[i]))
                merge2(xx[i], yy[i], 0, 0);

//            printf ("count2 = %d\n", count2);
            if (count2 > 1)
                fb[2] = i - 1;
        }

        printf ("Case #%d: ", ct);
        int xx = min(min(fb[0], fb[1]), fb[2]);
        if (xx > m)
            printf ("none\n");
        else
        {
            bool hyphen = false;
            if (xx == fb[0])
            {
                printf ("bridge");
                hyphen = true;
            }
            if (xx == fb[1])
            {
                if (hyphen) printf ("-");
                printf ("fork");
                hyphen = true;
            }
            if (xx == fb[2])
            {
                if (hyphen) printf ("-");
                printf ("ring");
                hyphen = true;
            }

            printf (" in move %d\n", xx + 1);
        }
    }

    return 0;
}
