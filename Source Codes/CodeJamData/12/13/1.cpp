#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;

int s[50], p[50], l[50];

#define debug(x) cerr<<#x<<" = "<<(x)<<endl;

struct event{
    int c1, c2;
    bool type;
    long long num, den;
};

bool operator<(const event& e1, const event& e2)
{
    long long s1=e1.num*e2.den;
    long long s2=e2.num*e1.den;
    if(s1<s2)
        return true;
    if(s1>s2)
        return false;
    return e1.type < e2.type;
}

char overlaps[50][50];
char graph[50][50];
int N;

void check(int c)
{
    bool has=false;
    for(int i=0; i<N; i++)
        if(overlaps[c][i])
        {
            has=true;
            break;
        }
    if(!has){
        for(int i=0; i<N; i++)
            graph[c][i]=graph[i][c]=2;
    }
}

void solve(){
    scanf("%d", &N);
    for(int i=0; i<N; i++)
    {
        char lane;
        scanf(" %c %d %d", &lane, s+i, p+i);
        l[i] = lane=='L';
    }
    memset(overlaps, 0, sizeof(overlaps));
    vector<event> e;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
        {
            if(i==j)
                continue;
            if(p[i]<=p[j] && p[i]+5>p[j])
                overlaps[i][j]=overlaps[j][i]=1;
            if(l[i]==l[j])
                graph[i][j]=0;
            else
                graph[i][j]=1;
            if(s[i]>=s[j])
                continue;
            if(p[j]<=p[i]-5)
            {
                event x;
                x.c1=i;
                x.c2=j;
                x.type=true;
                x.num=p[i]-5-p[j];
                x.den=s[j]-s[i];
                e.push_back(x);
            }
            if(p[j]<p[i]+5)
            {
                event x;
                x.c1=i;
                x.c2=j;
                x.type=false;
                x.num=p[i]+5-p[j];
                x.den=s[j]-s[i];
                e.push_back(x);
            }
        }
    sort(e.begin(), e.end());
    for(int i=0; i<N; i++)
        check(i);
    for(int ee=0; ee<e.size(); ee++)
    {
        event x = e[ee];
        int c1=x.c1;
        int c2=x.c2;
        if(!x.type)
        {
            assert(overlaps[c1][c2]);
            assert(overlaps[c2][c1]);
            overlaps[c1][c2]=overlaps[c2][c1]=0;
            check(c1);
            check(c2);
        }
        else
        {
            assert(!overlaps[c1][c2]);
            assert(!overlaps[c2][c1]);
            overlaps[c1][c2]=overlaps[c2][c1]=1;
            graph[c1][c2]=graph[c2][c1]=1;
            for(int k=0; k<N; k++)
                for(int i=0; i<N; i++)
                    for(int j=0; j<N; j++)
                    {
                        if(graph[i][k]!=2 && graph[k][j]!=2)
                        {
                            int nval = graph[i][k]^graph[k][j];
                            if(graph[i][j]==2)
                                graph[i][j]=graph[j][i]=nval;
                            if(graph[i][j]!=nval)
                            {
                                printf("%.6lf\n", (double)x.num/x.den);
                                return;
                            }
                        }
                    }
        }
    }
    printf("Possible\n");
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++)
    {
        printf("Case #%d: ", t);
        solve();
    }
    return 0;
}
