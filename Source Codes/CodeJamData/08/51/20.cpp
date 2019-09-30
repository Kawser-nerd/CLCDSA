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

#define PROBLEM "a"

const int M = 3005;

// left
char dir[4][2] = {{0,1},{-1,0},{0,-1},{1,0}};
int dmove[4][2][3] = {{{0,0,1},{-1,0,3}}, {{-1,0,2},{-1,-1,0}}, {{-1,-1,3},{0,-1,1}}, {{0,-1,0},{0,0,2}}};

int border[2*M+1][2*M+1][4];
int used[2*M+1][2*M+1];

int minr[2*M+1], maxr[2*M+1], minc[2*M+1], maxc[2*M+1];

char str[1010];

int main(){
  freopen(PROBLEM".in", "r", stdin);
  freopen(PROBLEM".out", "w", stdout);
  int tn, tst;
  scanf("%d", &tn);
  for (tst=1; tst<=tn; tst++){
    printf("Case #%d: ", tst);
    int n, times, i, j, h, ans=0;
    scanf("%d\n", &n);
    int sx=M, sy=M, sdir = 0;
    int mx=2*M+2, my=2*M+2, Mx=-1, My=-1;

    for (i=0; i<2*M; i++){
      minr[i] = minc[i] = 2*M+1;
      maxr[i] = maxc[i] = -1;
    }

    for (i=1; i<=n; i++){
      scanf("%s %d ", &str, &times);
      int len = strlen(str);
      for (j=0; j<times; j++){
        for (h=0; h<len; h++){
          if (str[h] == 'L') sdir = (sdir + 1) % 4;
          else if (str[h] == 'R') sdir = (sdir + 3) % 4;
          else{
            for (int z=0; z<2; z++){
              border[sx + dmove[sdir][z][0]][sy + dmove[sdir][z][1]][dmove[sdir][z][2]] = tst;
            }
            if (sdir==3){
              if (sy-1 < minc[sx]) minc[sx] = sy-1;
              if (sy > maxc[sx]) maxc[sx] = sy;
            }
            else if (sdir == 0){
              if (sx-1 < minr[sy]) minr[sy] = sx-1;
              if (sx > maxr[sy]) maxr[sy] = sx;
            }
            else if (sdir == 1){
              if (sy-1 < minc[sx-1]) minc[sx-1] = sy-1;
              if (sy > maxc[sx-1]) maxc[sx-1] = sy;
            }
            else{
              if (sx-1 < minr[sy-1]) minr[sy-1] = sx-1;
              if (sx > maxr[sy-1]) maxr[sy-1] = sx;
            }
            sx += dir[sdir][0];
            sy += dir[sdir][1];
            //printf("%d %d\n", sx, sy);
            if (sx < mx) mx = sx;
            if (sx > Mx) Mx = sx;
            if (sy < my) my = sy;
            if (sy > My) My = sy;
          }
        }
      }
    }
    /*printf("\n");
    for (i=0; i<=3; i++){
      for (j=0; j<=3; j++){
        printf("%d %d\n", i, j);
        for (h=0; h<4; h++) printf("%d ", border[i+M][j+M][h]);
        printf("\n");
      }
    }*/
    for (i=mx-1; i<=Mx+1; i++){
      int bn = 0;
      for (j=my-1; j<=My+1; j++){
        bn += (border[i][j][2] == tst);
        if ((bn > 0) && ((bn&1)==0) && (used[i][j] != tst) && (j > minc[i]) && (j < maxc[i])){
          used[i][j] = tst;
          //printf("%d %d\n", i-M, j-M);
          ans++;
        }
      }
    }
    for (j=my-1; j<=My+1; j++){
      int bn = 0;
      for (i=mx-1; i<=Mx+1; i++){
        bn += (border[i][j][1] == tst);
        if ((bn > 0) && ((bn&1)==0) && (used[i][j] != tst)  && (i > minr[j]) && (i < maxr[j])){
          used[i][j] = tst;
          //printf("%d %d\n", i-M, j-M);
          ans++;
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}