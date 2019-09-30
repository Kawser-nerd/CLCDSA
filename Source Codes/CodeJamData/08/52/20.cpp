#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <cstdlib>
using namespace std;

#define PROBLEM "b"

const int MAX = 20;

int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

int n, m;
int sx, sy, fx, fy;
char field[MAX][MAX];
int ansd[MAX][MAX];
int d[MAX][MAX][MAX][MAX];
char used[MAX][MAX][MAX][MAX];
int queue[MAX*MAX*MAX*MAX][4], qbeg, qend;

void push(int x, int y, int px, int py){
  qend++;
  queue[qend][0] = x;
  queue[qend][1] = y;
  queue[qend][2] = px;
  queue[qend][3] = py;
  used[x][y][px][py] = 1;
  if (ansd[x][y] > d[x][y][px][py]) ansd[x][y] = d[x][y][px][py];
  return;
}

inline int bad(int x, int y){
  return ((x<=0) || (x>n) || (y<=0) || (y>m) || (field[x][y]));
}

void push_coord(int x, int y, int zd){
  int i;

  if (ansd[x][y] > zd) ansd[x][y] = zd;

  for (i=0; i<4; i++){
    int cx = x, cy = y;
    while (!bad(cx, cy)){
      cx += dir[i][0];
      cy += dir[i][1];
    }
    cx -= dir[i][0];
    cy -= dir[i][1];
    /*if ((x == 1) && (y == 3)){
      printf("%d %d %d\n", cx, cy, zd);
    }*/
    if (!used[x][y][cx][cy]){
      d[x][y][cx][cy] = zd;
      push(x, y, cx, cy);
    }
  }
  return;
}

void go(int x, int y, int px, int py){
  int i;
  for (i=0; i<4; i++){
    int nx = x + dir[i][0];
    int ny = y + dir[i][1];
    int nd = d[x][y][px][py] + 1;
    if (!bad(nx, ny)){
      if (d[nx][ny][px][py] > nd){
        d[nx][ny][px][py] = nd;
        if (ansd[nx][ny] > nd) ansd[nx][ny] = nd;
      }
      if (!used[nx][ny][px][py]){
        push(nx, ny, px, py);
        push_coord(nx, ny, nd);
      }
    }
    else{
      push_coord(px, py, nd);
    } 
  }
  return;
}

int main(){
  freopen(PROBLEM".in", "r", stdin);
  freopen(PROBLEM".out", "w", stdout);
  int tn, tst;
  scanf("%d", &tn);
  for (tst=1; tst<=tn; tst++){
    printf("Case #%d: ", tst);
    scanf("%d%d\n", &n, &m);
    memset(field, 0, sizeof(field));
    int i, j;
    char ch;
    for (i=1; i<=n; i++){
      for (j=1; j<=m; j++){
        scanf("%c", &ch);
        if (ch == '#') field[i][j] = 1;
        else if (ch == 'O'){
          sx = i;
          sy = j;
        }
        else if (ch == 'X'){
          fx = i;
          fy = j;
        }
      }
      scanf("\n");
    }
    memset(d, 0x3f, sizeof(d));
    memset(ansd, 0x3f, sizeof(ansd));
    memset(used, 0, sizeof(used));
    qbeg = 1;
    qend = 0;
    push_coord(sx, sy, 0);
    while (qbeg <= qend){
      go(queue[qbeg][0], queue[qbeg][1], queue[qbeg][2], queue[qbeg][3]);
      qbeg++;
    }
    /*printf("\n");
    for (i=1; i<=n; i++){
      for (j=1; j<=m; j++){
        printf("%d ", ansd[i][j]);
      }
      printf("\n");
    }*/
    //printf("\n%d\n", d[1][3][4][3]);
    if (ansd[fx][fy] == 0x3f3f3f3f){
      printf("THE CAKE IS A LIE\n");
    }
    else{
      printf("%d\n", ansd[fx][fy]);
    }
  }
  return 0;
}