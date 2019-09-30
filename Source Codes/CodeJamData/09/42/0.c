#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 12
#define INFINITY 2000000000
#define MAXPOS 8200

struct point
{
     int x, y, pos;
};

int ConvToPos (char data[MAXN][MAXN], int x, int C)
{
     int res = 0;
     int i, j;
     for (i = x; i <= x+1; i++)
     {
          for (j = 0; j < C; j++)
          {
               res = res * 2;
               if (data[i][j] == '#') res++;
          }
     }
     return res;
}

void ConvToGrid (char a[MAXN][MAXN], int x, int pos, int C)
{
     int i, j;
     for (i = x+1; i >= x; i--)
     {
          for (j = C-1; j >= 0; j--)
          {
               a[i][j] = pos % 2;
               if (a[i][j] == 0) a[i][j] = '.';
               else a[i][j] = '#';
               pos /= 2;
          }
     }
}

int main ()
{
     int T, iT;
     scanf("%d",&T);
     int R, C, F;
     static char data[MAXN][MAXN];
     static struct point q[MAXN*MAXN*MAXN*MAXN];
     static int a[MAXN][MAXN][MAXPOS];
     static char gr[MAXN][MAXN];
     int r, w;
     int i, j, k;
     int total;
     int min;
     int x, y;
     char left, right;
     for (iT = 0; iT < T; iT++)
     {
          scanf("%d %d %d\n",&R,&C,&F);
          total = 1;
          for (i = 1; i <= 2*C; i++) total *= 2;
          for (i = 0; i < R; i++) gets(data[i]);
          for (i = 0; i < R; i++)
          {
               for (j = 0; j < C; j++)
               {
                    for (k = 0; k < total; k++)
                    {
                         a[i][j][k] = INFINITY;
                    }
               }
          }
          r = 0;
          w = 1;
          q[0].x = 0;
          q[0].y = 0;
          q[0].pos = ConvToPos(data,0,C);
          a[0][0][q[0].pos] = 0;
          while (w > r)
          {
               //printf("%d %d %d\n",q[r].x,q[r].y,q[r].pos);
               
               left = 0;
               right = 0;
               
               if (q[r].x < (R-1))
               {
                    memcpy(gr,data,sizeof(data));
                    ConvToGrid(gr,q[r].x,q[r].pos,C);
                    
                    //Move left
                    x = q[r].x;
                    y = q[r].y - 1;
                    if ((y >= 0) && (gr[x][y] == '.'))
                    {
                         left = 1;
                         while ((x < (R-1)) && (gr[x+1][y] == '.')) x++;
                         if (x - q[r].x <= F)
                         {
                              if (x == (R-1)) k = 0;
                              else
                              {
                                   k = ConvToPos(gr,x,C);
                              }
                              if (a[q[r].x][q[r].y][q[r].pos] < a[x][y][k])
                              {
                                   a[x][y][k] = a[q[r].x][q[r].y][q[r].pos];
                                   q[w].x = x;
                                   q[w].y = y;
                                   q[w].pos = k;
                                   w++;
                              }
                         }
                    }
                    
                    //Move right
                    x = q[r].x;
                    y = q[r].y + 1;
                    if ((y < C) && (gr[x][y] == '.'))
                    {
                         right = 1;
                         while ((x < (R-1)) && (gr[x+1][y] == '.')) x++;
                         if (x - q[r].x <= F)
                         {
                              if (x == (R-1)) k = 0;
                              else
                              {
                                   k = ConvToPos(gr,x,C);
                              }
                              if (a[q[r].x][q[r].y][q[r].pos] < a[x][y][k])
                              {
                                   a[x][y][k] = a[q[r].x][q[r].y][q[r].pos];
                                   q[w].x = x;
                                   q[w].y = y;
                                   q[w].pos = k;
                                   w++;
                              }
                         }
                    }
                    
                    //Dig left
                    x = q[r].x + 1;
                    y = q[r].y - 1;
                    if ((left) && (gr[x][y] == '#'))
                    {
                         gr[x][y] = '.';
                         k = ConvToPos(gr,q[r].x,C);
                         if ((a[q[r].x][q[r].y][q[r].pos]+1) < a[q[r].x][q[r].y][k])
                         {
                              a[q[r].x][q[r].y][k] = a[q[r].x][q[r].y][q[r].pos]+1;
                              q[w].x = q[r].x;
                              q[w].y = q[r].y;
                              q[w].pos = k;
                              w++;
                         }
                         gr[x][y] = '#';
                    }
                    
                    //Dig right
                    x = q[r].x + 1;
                    y = q[r].y + 1;
                    if ((right) && (gr[x][y] == '#'))
                    {
                         gr[x][y] = '.';
                         k = ConvToPos(gr,q[r].x,C);
                         if ((a[q[r].x][q[r].y][q[r].pos]+1) < a[q[r].x][q[r].y][k])
                         {
                              a[q[r].x][q[r].y][k] = a[q[r].x][q[r].y][q[r].pos]+1;
                              q[w].x = q[r].x;
                              q[w].y = q[r].y;
                              q[w].pos = k;
                              w++;
                         }
                         gr[x][y] = '#';
                    }
                    
               }
               r++;
          }
          printf("Case #%d: ",iT+1);
          min = INFINITY;
          for (j = 0; j < C; j++)
          {
               if (a[R-1][j][0] < min) min = a[R-1][j][0];
          }
          if (min == INFINITY)
          {
               printf("No\n");
          }
          else
          {
               printf("Yes %d\n",min);
          }
     }
     return 0;
}
