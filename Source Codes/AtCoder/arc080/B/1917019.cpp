#include <iostream>
#include <stdio.h>
#include <cstdlib>
using namespace std;

const int N = 2e5;
int h,w,n;
int G[105][105];
int a[N];
void init()
{
    cin >> h >> w;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
}

void solve()
{
    int cnt=0,flag=0;
    for(int i=0; i<h; i++)
    {
        if(i%2 == 0)
        {
            for(int j=flag%w; j<w; j++)
            {
                if(a[cnt] > 0){G[i][j]=cnt+1; a[cnt]--;}
                else if(a[cnt] == 0){cnt++; G[i][j]=cnt+1; a[cnt]--;}
                flag++;
            }

        }else
        {
            for(int j=w-flag%w-1; j>=0; j--)
            {
                if(a[cnt] > 0){G[i][j]=cnt+1; a[cnt]--;}
                else if(a[cnt] == 0){cnt++; G[i][j]=cnt+1; a[cnt]--;}
                flag++;
            }
        }
    }
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<w; j++)
        {
            if(j != w-1)
                cout << G[i][j] << " ";
            else
                cout << G[i][j] << " " << endl;
        }
    }
}

int main()
{
    init();
    solve();
    return 0;
}