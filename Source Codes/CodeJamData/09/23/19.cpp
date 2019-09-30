#pragma comment(linker,"/STACK:100000000")  

#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <iostream>
#include <cassert>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int n, tn, nt;

char a[25][25];

#define MAX_TIME 1006

int ans[MAX_TIME][20][20];
string res[MAX_TIME][20][20];

int qx[MAX_TIME*20*20+1], qy[MAX_TIME*20*20+1], d[MAX_TIME*20*20+1], qval[MAX_TIME*20*20+1], qb, qe;

void add(int x, int y, int D, int val, string &how)
{
   val+=(MAX_TIME/2);
   if (val<0 || val>=MAX_TIME) return;
   if (ans[val][x][y]==-1)
   {
      ans[val][x][y]=D;
      res[val][x][y]=how;
      qx[qe]=x;
      qy[qe]=y;
      qval[qe]=val;
      d[qe++]=D;
      return;
   }
   if (ans[val][x][y]<D) return;
   if (res[val][x][y]>how) res[val][x][y]=how;
}

int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};

int main(void)
{
   int i, j, k, l, m;
   //freopen("C-small-attempt0.in", "r", stdin);
   //freopen("C-small-attempt0.out", "w", stdout);
   freopen("C-large.in", "r", stdin);
   freopen("C-large.out", "w", stdout);

   scanf("%d\n", &nt);
   for (tn=0; tn<nt; tn++)
   {
      fprintf(stderr, "Case #%d: ", tn+1);

      qb=qe=0;
      memset(ans, -1, sizeof(ans));

      scanf("%d %d\n", &n, &m);
      for (i=0; i<n; i++)
         gets(a[i]);
      for (i=0; i<n; i++)
         for (j=0; j<n; j++)
         {
            if (a[i][j]!='-' && a[i][j]!='+')
            {
               string temp=(string)""+a[i][j];
               add(i, j, 0, a[i][j]-'0', temp);
            }
         }

      printf("Case #%d: \n", tn+1);

      while (qb!=qe)
      {
         int x=qx[qb], y=qy[qb], val=qval[qb], D=d[qb++]+1;
         string cur=res[val][x][y];
         val-=(MAX_TIME/2);
         cur.resize(cur.size()+2);
         for (i=0; i<4; i++)
         {
            int nx=x+dx[i], ny=y+dy[i];
            if (nx>=0 && nx<n && ny>=0 && ny<n)
            {
               int mul=1;
               if (a[nx][ny]=='-')
               {
                  mul=-1;
                  cur[cur.size()-2]='-';
               }
               else cur[cur.size()-2]='+';
               for (j=0; j<4; j++)
               {
                 int tx=nx+dx[j], ty=ny+dy[j];
                 if (tx>=0 && tx<n && ty>=0 && ty<n)
                 {
                    cur[cur.size()-1]=a[tx][ty];
                    add(tx, ty, D, val+mul*(a[tx][ty]-'0'), cur);
                 }
               }
            }
         }
      }

      for (i=0; i<m; i++)
      {
        int need, bans=1000000;
        string Res="";
        scanf("%d", &need), need+=(MAX_TIME/2);
        for (j=0; j<n; j++)
           for (k=0; k<n; k++)
              if (ans[need][j][k]!=-1)
              {
                 if (ans[need][j][k]<bans)
                 {
                    bans=ans[need][j][k];
                    Res=res[need][j][k];
                 }
                 else if (ans[need][j][k]==bans && Res>res[need][j][k])
                    Res=res[need][j][k];
              }
        assert(Res!="");
        printf("%s\n", Res.c_str());
      }

   }
   return 0;
}
