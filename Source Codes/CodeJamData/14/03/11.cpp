#include <cstdio>
#include <queue>
#include <utility>
#include <cstring>
#include <cassert>
using namespace std;

int T, M, R, C;

void check(char g[51][51], int RR, int CC, int MM)
{
    int mcnt=0, ccnt=0;
    queue<pair<int, int> > q;
    for(int r=0; r<RR; r++)
    for(int c=0; c<CC; c++)
    {
        int o=g[r][c];
        assert(o=='.' || o=='c' || o=='*');
        if(o=='c'){
            ccnt++;
            q.push(make_pair(r, c));
        }
        if(o=='*') mcnt++;
    }
    assert(ccnt==1);
    assert(mcnt==MM);
    for(; !q.empty(); q.pop())
    {
        int r=q.front().first;
        int c=q.front().second;
        bool adj=false;
        for(int rr=-1; rr<=1; rr++)
        for(int cc=-1; cc<=1; cc++)
        {
            int nr=r+rr;
            int nc=c+cc;
            if(0<=nr && nr<R && 0<=nc && nc<C && g[nr][nc]=='*')
                adj=true;
        }
        if(!adj)
        for(int rr=-1; rr<=1; rr++)
        for(int cc=-1; cc<=1; cc++)
        {
            int nr=r+rr;
            int nc=c+cc;
            if(0<=nr && nr<R && 0<=nc && nc<C && g[nr][nc]=='.')
            {
                g[nr][nc]='c';
                ccnt++;
                q.push(make_pair(nr,nc));
            }
        }
    }
    assert(ccnt==RR*CC-MM);
}

int main()
{
    scanf("%d", &T);
    for(int t=1; t<=T; t++)
    {
        scanf("%d%d%d", &R, &C, &M);
        printf("Case #%d:\n", t);
        int RC = R*C;
        int avail = RC-M;
        bool swapped = false;
        char res[51][51];
        if(R>C)
        {
            swapped=true;
            swap(R, C);
        }
        int RR=R, CC=C, MM=M;
        for(int r=0; r<R; r++)
        {
            for(int c=0; c<C; c++)
            {
                res[r][c]='.';
            }
            res[r][C]=0;
        }
        if (avail==1)
        {
            for(int r=0; r<R; r++)
            for(int c=0; c<C; c++)
            {
                res[r][c]='*';
            }
            res[R-1][C-1]='c';
        }
        else if (R==1)
        {
            res[R-1][C-1]='c';
            for(int c=0; c<M; c++)
                res[0][c]='*';
        }
        else
        {
            while(M>=R || M>=C)
            {
                if(R>=C)
                {
                    R--;
                    M-=C;
                    for(int c=0; c<C; c++)
                        res[R][c]='*';
                }
                else
                {
                    C--;
                    M-=R;
                    for(int r=0; r<R; r++)
                        res[r][C]='*';
                }
            }
            if(R==1)
            {
                puts("Impossible");
                continue;
            }
            else if (R==2)
            {
                if(avail&1)
                {
                    puts("Impossible");
                    continue;
                }
                assert(M==0);
                res[0][0]='c';
            }
            else if (R==3 && C==3 && M==2)
            {
                puts("Impossible");
                continue;
            }
            else
            {
                res[0][0]='c';
                if(M)
                {
                    if(M>1)
                    {
                        res[R-1][C-2]='*';
                    }
                    for(int i=0; i<max(1,M-1); i++)
                    {
                        res[R-1-i][C-1]='*';
                    }
                }
            }
        }
        if(!swapped)
        {
            for(int r=0; r<RR; r++)
                puts(res[r]);
        }
        else
        {
            for(int c=0; c<CC; c++)
            {
                for(int r=0; r<RR; r++)
                {
                    putchar(res[r][c]);
                }
                puts("");
            }
        }
        check(res, RR, CC, MM);
    }
    return 0;
}
