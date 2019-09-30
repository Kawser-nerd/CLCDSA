#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 15
#define MAXPEOPLE 7

struct coord
{
     int x, y;
};

struct pos
{
     int n;
     char type;
     struct coord a[MAXPEOPLE];
};

void sort (struct coord a[MAXPEOPLE], int l, int r)
{
     int i, j;
     struct coord x, y;
     i = l; j = r; x = a[(l+r)/2];
     while (i <= j)
     {
          while ((a[i].x < x.x) || ((a[i].x == x.x) && (a[i].y < x.y))) i++;
          while ((a[j].x > x.x) || ((a[j].x == x.x) && (a[j].y > x.y))) j--;
          if (i <= j)
          {
               y = a[i]; a[i] = a[j]; a[j] = y;
               i++; j--;
          }
     }
     if (l < j) sort(a,l,j);
     if (i < r) sort(a,i,r);
}

char IsEqual (struct coord a[MAXPEOPLE], struct coord b[MAXPEOPLE], int N)
{
     sort(a,0,N-1);
     sort(b,0,N-1);
     int i;
     for (i = 0; i < N; i++)
     {
          if ((a[i].x != b[i].x) || (a[i].y != b[i].y)) return 0;
     }
     return 1;
}

char GetData (char data[MAXN][MAXN], int x, int y, int N, int M)
{
     if ((x >= 0) && (x < N) && (y >= 0) && (y < M)) return data[x][y];
     else return '#';
}

char IsRepeat (struct coord a[MAXPEOPLE], int N)
{
     sort(a,0,N-1);
     int i;
     for (i = 0; i < (N-1); i++)
     {
          if ((a[i].x == a[i+1].x) && (a[i].y == a[i+1].y)) return 1;
     }
     return 0;
}

int cnt;

void DFS (char dat[MAXN][MAXN], int x, int y)
{
     if (dat[x][y] == 1)
     {
          cnt++;
          dat[x][y] = 0;
     }
     int nx, ny;
     
     nx = x-1;
     ny = y;
     if ((nx >= 0) && (dat[nx][ny] == 1)) DFS(dat,nx,ny);
     
     nx = x+1;
     ny = y;
     if (dat[nx][ny] == 1) DFS(dat,nx,ny);
     
     nx = x;
     ny = y-1;
     if ((ny >= 0) && (dat[nx][ny] == 1)) DFS(dat,nx,ny);
     
     nx = x;
     ny = y+1;
     if (dat[nx][ny] == 1) DFS(dat,nx,ny);
}

char IsDangerous (struct coord a[MAXPEOPLE], int N)
{
     char dat[MAXN][MAXN];
     memset(dat,0,sizeof(dat));
     int i;
     for (i = 0; i < N; i++)
     {
          dat[a[i].x][a[i].y] = 1;
     }
     cnt = 0;
     DFS(dat,a[0].x,a[0].y);
     if (cnt == N) return 'O';
     else return 'D';
}

int GetPos (struct pos a, int num, char t, int N)
{
     if (num >= N) return 0;
     if (t == 'x') return a.a[num].x;
     else return a.a[num].y;
}

int main ()
{
     int T, iT;
     scanf("%d",&T);
     int N, M;
     static char data[MAXN][MAXN];
     int i, j, k, n;
     struct pos st, fin, t1, t2;
     static struct pos q[2000000];
     static char b[MAXN][MAXN][MAXN][MAXN]; //Don't care about hard anymore!!!
     int r, w;
     int moves;
     for (iT = 0; iT < T; iT++)
     {
          //if (iT == 5) break;
          
          memset(b,0,sizeof(b));
          scanf("%d %d\n",&N,&M);
          st.n = 0;
          fin.n = 0;
          st.type = 'O';
          fin.type = 'O';
          for (i = 0; i < N; i++)
          {
               gets(data[i]);
               for (j = 0; j < M; j++)
               {
                    if ((data[i][j] == 'o') || (data[i][j] == 'w'))
                    {
                         st.a[st.n].x = i;
                         st.a[st.n].y = j;
                         st.n++;
                    }
                    if ((data[i][j] == 'x') || (data[i][j] == 'w'))
                    {
                         fin.a[fin.n].x = i;
                         fin.a[fin.n].y = j;
                         fin.n++;
                    }
               }
          }
          //LAZY
          moves = -1;
          n = st.n;
          r = 0;
          w = 1;
          memcpy(&q[r],&st,sizeof(st));
          q[r].n = 0;
          b[GetPos(q[r],0,'x',n)][GetPos(q[r],0,'y',n)][GetPos(q[r],1,'x',n)][GetPos(q[r],1,'y',n)] = 1;
          while (w > r)
          {            
               if (IsEqual(q[r].a,fin.a,n))
               {
                    moves = q[r].n;
                    break;
               }
               
               for (k = 0; k < n; k++)
               {                
                    //printf("(%d ; %d) ",q[r].a[k].x,q[r].a[k].y);
                    //Up && Down
                    if ((GetData(data,q[r].a[k].x-1,q[r].a[k].y,N,M) != '#') && (GetData(data,q[r].a[k].x+1,q[r].a[k].y,N,M) != '#'))
                    {
                         memcpy(&t1,&q[r],sizeof(q[r]));
                         memcpy(&t2,&q[r],sizeof(q[r]));
                         t1.a[k].x--;
                         t2.a[k].x++;
                         
                         if ((!IsRepeat(t1.a,n)) && (!IsRepeat(t2.a,n)))
                         {                         
                              memcpy(&q[w],&q[r],sizeof(q[r]));
                              q[w].a[k].x--;
                              q[w].n++;
                              q[w].type = IsDangerous(q[w].a,n);
                              if ((q[r].type == 'O') || (q[w].type == 'O'))
                              {
                                   if (b[GetPos(q[w],0,'x',n)][GetPos(q[w],0,'y',n)][GetPos(q[w],1,'x',n)][GetPos(q[w],1,'y',n)] == 0)
                                   {
                                        b[GetPos(q[w],0,'x',n)][GetPos(q[w],0,'y',n)][GetPos(q[w],1,'x',n)][GetPos(q[w],1,'y',n)] = 1;
                                        w++;
                                   }
                              }
                                   
                              memcpy(&q[w],&q[r],sizeof(q[r]));
                              q[w].a[k].x++;
                              q[w].n++;
                              q[w].type = IsDangerous(q[w].a,n);
                              if ((q[r].type == 'O') || (q[w].type == 'O'))
                              {
                                   if (b[GetPos(q[w],0,'x',n)][GetPos(q[w],0,'y',n)][GetPos(q[w],1,'x',n)][GetPos(q[w],1,'y',n)] == 0)
                                   {
                                        b[GetPos(q[w],0,'x',n)][GetPos(q[w],0,'y',n)][GetPos(q[w],1,'x',n)][GetPos(q[w],1,'y',n)] = 1;
                                        w++;
                                   }
                              }
                         }
                    }
                    
                    //Left && Right
                    if ((GetData(data,q[r].a[k].x,q[r].a[k].y-1,N,M) != '#') && (GetData(data,q[r].a[k].x,q[r].a[k].y+1,N,M) != '#'))
                    {
                         memcpy(&t1,&q[r],sizeof(q[r]));
                         memcpy(&t2,&q[r],sizeof(q[r]));
                         t1.a[k].y--;
                         t2.a[k].y++;
                         
                         if ((!IsRepeat(t1.a,n)) && (!IsRepeat(t2.a,n)))
                         {                         
                              memcpy(&q[w],&q[r],sizeof(q[r]));
                              q[w].a[k].y--;
                              q[w].n++;
                              q[w].type = IsDangerous(q[w].a,n);
                              if ((q[r].type == 'O') || (q[w].type == 'O'))
                              {
                                   if (b[GetPos(q[w],0,'x',n)][GetPos(q[w],0,'y',n)][GetPos(q[w],1,'x',n)][GetPos(q[w],1,'y',n)] == 0)
                                   {
                                        b[GetPos(q[w],0,'x',n)][GetPos(q[w],0,'y',n)][GetPos(q[w],1,'x',n)][GetPos(q[w],1,'y',n)] = 1;
                                        w++;
                                   }
                              }
                                   
                              memcpy(&q[w],&q[r],sizeof(q[r]));
                              q[w].a[k].y++;
                              q[w].n++;
                              q[w].type = IsDangerous(q[w].a,n);
                              if ((q[r].type == 'O') || (q[w].type == 'O'))
                              {
                                   if (b[GetPos(q[w],0,'x',n)][GetPos(q[w],0,'y',n)][GetPos(q[w],1,'x',n)][GetPos(q[w],1,'y',n)] == 0)
                                   {
                                        b[GetPos(q[w],0,'x',n)][GetPos(q[w],0,'y',n)][GetPos(q[w],1,'x',n)][GetPos(q[w],1,'y',n)] = 1;
                                        w++;
                                   }
                              }
                         }
                    }                    
               }
               
               //printf("\n");
               r++;
          }
          printf("Case #%d: %d\n",iT+1,moves);
     }
     return 0;
}
