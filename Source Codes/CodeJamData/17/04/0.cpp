#include <bits/stdc++.h>

using namespace std;

int N, M;
int ta[100][100];
int tb[100][100];
int ch[100][100];

void _main(int TEST)
{
    memset(ta, 0, sizeof ta);
    memset(tb, 0, sizeof tb);
    memset(ch, 0, sizeof ch);
    scanf("%d%d", &N, &M);
    map<int, int> diag1, diag2, axis1, axis2;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            diag1[i+j]=diag2[i-j]=axis1[i]=axis2[j]=1;
    char c;
    for(int i=0; i<M; i++)
    {
        int x, y;
        scanf(" %c%d%d", &c, &x, &y);
        x--, y--;
        if(c!='x')
            diag1[x+y]=diag2[x-y]=0, tb[x][y]++;
        if(c!='+')
            axis1[x]=axis2[y]=0, ta[x][y]++;
    }
    map<int, int> m;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            m[i+j]++;
    vector<pair<int, int>> v;
    for(auto& it: m)
        v.push_back({it.second, it.first});
    sort(v.begin(), v.end());
    for(int i=0; i<(int)v.size(); i++)
    {
        int s=v[i].second;
        if(diag1[s]==0)
            continue;
        for(int x=0; x<N; x++)
        {
            int y=s-x;
            if(y<0 || y>=N)
                continue;
            if(diag2[x-y])
            {
                diag1[x+y]=diag2[x-y]=0;
                tb[x][y]++;
                ch[x][y]=1;
                break;
            }
        }
    }
    for(int i=0; i<N; i++) if(axis1[i])
    {
        for(int j=0; j<N; j++) if(axis2[j])
        {
            axis1[i]=axis2[j]=0;
            ta[i][j]++;
            ch[i][j]=1;
            break;
        }
    }
    int ans=0;
    vector<pair<char, pair<int, int>>> rans;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
        {
            ans+=ta[i][j]+tb[i][j];
            if(ch[i][j])
            {
                if(ta[i][j] && tb[i][j])
                    rans.push_back({'o', {i+1, j+1}});
                else if(ta[i][j])
                    rans.push_back({'x', {i+1, j+1}});
                else if(tb[i][j])
                    rans.push_back({'+', {i+1, j+1}});
                else
                    assert(0);
            }
        }
    printf("%d %d\n", ans, (int)rans.size());
    for(auto& it: rans)
        printf("%c %d %d\n", it.first, it.second.first, it.second.second);
}

int main()
{
    freopen("D-large.in", "r", stdin);
    freopen("D-large.out", "w", stdout);
    int TEST;
    scanf("%d", &TEST);
    for(int i=1; i<=TEST; i++)
    {
        //cerr << i << endl;
        printf("Case #%d: ", i);
        _main(i);
    }
    return 0;
}
