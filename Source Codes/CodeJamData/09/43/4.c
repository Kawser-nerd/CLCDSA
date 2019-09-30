#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 30
#define INFINITY 2000000000

struct point
{
     int c;
     int a[MAXN];
};

int res;

char IsOK (int a[MAXN][MAXN], int x, int y, int K)
{
     int temp;
     if (a[x][0] > a[y][0])
     {
          temp = x;
          x = y;
          y = temp;
     }
     int i;
     for (i = 0; i < K; i++)
     {
          if (a[x][i] >= a[y][i]) return 0;
     }
     return 1;
}

void FindRes (struct point a[MAXN], char b[MAXN][MAXN], int point, int N, int K, int count)
{
     if (point == N)
     {
          if (count < res) res = count;
     }
     else
     {
          //Trying to put somewhere graph point
          int i, j;
          int cnt = 0;
          char flag;
          for (i = 0; i < count; i++)
          {
               flag = 1;
               for (j = 0; j < a[i].c; j++)
               {
                    if (!b[point][a[i].a[j]])
                    {
                         flag = 0;
                         break;
                    }
               }
               if (flag)
               {
                    a[i].a[a[i].c] = point;
                    a[i].c++;
                    FindRes(a,b,point+1,N,K,count);
                    a[i].c--;
                    cnt++;
                    if (cnt == 2) break;
               }
          }
          //Try to create a new group
          a[count].c = 1;
          a[count].a[0] = point;
          FindRes(a,b,point+1,N,K,count+1);
     }
}

int main ()
{
     int T, iT;
     scanf("%d",&T);
     static struct point a[MAXN];
     static int data[MAXN][MAXN];
     static char b[MAXN][MAXN];
     int N, K;
     int i, j;
     for (iT = 0; iT < T; iT++)
     {
          scanf("%d %d",&N,&K);
          memset(b,0,sizeof(b));
          for (i = 0; i < N; i++)
          {
               for (j = 0; j < K; j++)
               {
                    scanf("%d",&(data[i][j]));
               }
          }
          
          for (i = 0; i < N; i++)
          {
               a[i].c = 0;
               b[i][i] = 1;
               for (j = i+1; j < N; j++)
               {
                    b[i][j] = IsOK(data,i,j,K);
                    b[j][i] = b[i][j];
               }
          }
          
          res = INFINITY;
          FindRes(a,b,0,N,K,0);
          
          printf("Case #%d: %d\n",iT+1,res);
     }
     return 0;
}
