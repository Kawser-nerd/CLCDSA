#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

const int N = (2000 + 10);

int tc, n;

int a[N];
int b[N];
int l[N];
int c[N];
int res[N];

bool map[N][N];

void input()
{
    int i;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for(i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
    }
}

void process()
{
    int i, j, k;
    
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            map[i][j] = false;
        }
    }
    for(i = 0; i < n; i++)
    {
        l[a[i]] = i;
        for(j = 0; j < i; j++)
        {
            if(a[i] <= a[j])
            {
                map[i][j] = true;
            }
        }
        if(1 < a[i])
        {
            map[l[a[i] - 1]][i] = true;
        }
    }
    for(i = n - 1; 0 <= i; i--)
    {
        l[b[i]] = i;
        for(j = n - 1; i < j; j--)
        {
            if(b[i] <= b[j])
            {
                map[i][j] = true;
            }
        }
        if(1 < b[i])
        {
            map[l[b[i] - 1]][i] = true;
        }
    }
    
    for(i = 0; i < n; i++)
    {
        c[i] = 0;
        res[i] = 0;
        for(j = 0; j < n; j++)
        {
            if(map[j][i])
            {
                c[i]++;
            }
        }
    }
    for(i = 0; i < n; i++)
    {
        for(j = 0; res[j] || c[j]; j++);
        res[j] = i + 1;
        for(k = 0; k < n; k++)
        {
            if(map[j][k])
            {
                c[k]--;
            }
        }
    }
}

void output()
{
    int i;
    printf("Case #%d:", tc);
    for(i = 0; i < n; i++)
    {
        printf(" %d", res[i]);
    }
    printf("\n");
}

int main()
{
    int t;
    
    freopen("/Users/protos37/Downloads/C-large.in", "r", stdin);
    freopen("/Users/protos37/Downloads/output.txt", "w", stdout);
    
    scanf("%d", &t);
    for(tc = 1; tc <= t; tc++)
    {
        input();
        process();
        output();
    }
    return 0;
}