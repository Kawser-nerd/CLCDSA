#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, s, t) for(i = (s); i < (t); i++)
#define RFOR(i, s, t) for(i = (s)-1; i >= (t); i--)
const int MAXN = 3004;
const int MAXM = 10004;
const int dx[] = {1, 1, 0, -1, -1, 0};
const int dy[] = {0, 1, 1, 0, -1, -1};

bool a[MAXN*2][MAXN*2];
bool b[MAXN*2][MAXN*2];
int xx[MAXM], yy[MAXM];
int x[MAXM], y[MAXM];
bool f[MAXM][6];
int s, m;
bool b1, b2, b3;

void insert(int xx, int yy){
  int i, j, k;
  int h, t;
  ll area = 0;
  a[xx][yy] = 1;
  h = t = 0;
  x[h] = xx;
  y[t++] = yy;
  b[xx][yy] = 1;
  while(h < t){
    xx = x[h];
    yy = y[h++];
    for(int d = 0; d < 6; d++){
      int x1 = xx+dx[d];
      int y1 = yy+dy[d];
      if(a[x1][y1] && !b[x1][y1]){
        b[x1][y1] = 1;
        x[t] = x1;
        y[t++] = y1;
      }
    }
  }
  j = 0;
  for(i = 0; i < t; i++){
    f[i][0] = x[i]==1;
    f[i][1] = y[i]==1;
    f[i][2] = x[i]==s*2-1;
    f[i][3] = y[i]==s*2-1;
    f[i][4] = x[i]-y[i]==s-1;
    f[i][5] = y[i]-x[i]==s-1;
    k = 0;
    for(int i0 = 0; i0 < 6; i0++){
      k += f[i][i0];
    }
    if(k >= 2){
      j++;
      for(int i0 = 0; i0 < 6; i0++)
        f[i][i0] = 0;
    }
    for(int i0 = 0; i0 < 6; i0++){
      f[0][i0] |= f[i][i0];
    }
  }
  if(j >= 2)
    b1 = 1;
  k = 0;
  for(int i0 = 0; i0 < 6; i0++){
    k += f[0][i0];
  }
  if(k >= 3)
    b2 = 1;
  for(i = 0; i < t; i++)
    b[x[i]][y[i]] = 0;
  if(t < 2)
    return;
  i = 0;
  for(j = 1; j < t; j++)
    if(mp(x[j], y[j]) < mp(x[i], y[i]))
      i = j;
  k = 3;
  xx = x[i];
  yy = y[i];
  j = y[i];
  i = x[i];
  t = 0;
  do{
    t++;
    k = (k+2)%6;
    while(!a[i+dx[k]][j+dy[k]])
      k = (k+5)%6;
    area += i*(j+dy[k])-j*(i+dx[k]);
    i += dx[k];
    j += dy[k];
  }while(i != xx || j != yy);
  if(a[i+1][j] && a[i][j+1] && !a[i+1][j+1] && k == 5){
    do{
      t++;
      k = (k+2)%6;
      while(!a[i+dx[k]][j+dy[k]])
        k = (k+5)%6;
      area += i*(j+dy[k])-j*(i+dx[k]);
      i += dx[k];
      j += dy[k];
    }while(i != xx || j != yy);
  }
  if(h*2-t-2 != -area)
    b3 = 1;
}

int main()
{
  #ifdef __FIO
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  int T;
  scanf("%d", &T);
  for(int i0 = 1; i0 <= T; i0++){
    printf("Case #%d: ", i0);
    int i;
    scanf("%d%d", &s, &m);
    memset(a, 0, sizeof a);
    for(i = 1; i <= m; i++)
      scanf("%d%d", &xx[i], &yy[i]);
    b1 = b2 = b3 = 0;
    for(i = 1; i <= m; i++){
      insert(xx[i], yy[i]);
      if(b1||b2||b3)
        break;
    }
    if(i > m)
      printf("none\n");
    if(b1)
      printf("bridge");
    if(b2){
      if(b1)
        printf("-");
      printf("fork");
    }
    if(b3){
      if(b1||b2)
        printf("-");
      printf("ring");
    }
    if(i <= m){
       printf(" in move %d\n", i);
    }
  }
  return 0;
}
