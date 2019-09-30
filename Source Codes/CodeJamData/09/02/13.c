#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int alt[110][110];
int dir[110][110];
char group[110][110];
int H,W;
char next;

int d[][2] = {-1,0, 0,-1, 0,1, 1,0};

void prtgroup() {
  int i,j;
  for (i=0;i<H;i++) {
    printf("%c",group[i][0]);
    for (j=1;j<W;j++)
      printf(" %c",group[i][j]);
    printf("\n");
  }
}

void prt() {
  int i,j;
  printf("Alt:\n");
  for (i=0;i<H;i++) {
    for (j=0;j<W;j++)
      printf("%4d ",alt[i][j]);
    printf("\n");
  }
  printf("Dir:\n");
  for (i=0;i<H;i++) {
    for (j=0;j<W;j++) {
      switch (dir[i][j]) {
      case 0: printf("   U "); break;
      case 1: printf("   L "); break;
      case 2: printf("   R "); break;
      case 3: printf("   D "); break;
      case 9: printf("   S "); break;
      }
    }
    printf("\n");
  }
}

void mkdir() {
  int i,j,k,min,kmin,ii,jj;
  for (i=0;i<H;i++)
    for (j=0;j<W;j++) {
      /* printf("pos (%d,%d)\n",i,j); */
      kmin = -1;
      for (k=0;k<4;k++) {
        ii = i+d[k][0];
        jj = j+d[k][1];
        if (ii < 0 || ii >= H || jj < 0 || jj >= W) {
          /* printf("- skiping pos (%d,%d)\n",ii,jj); */
          continue;
        }
        /* printf("- trying with pos (%d,%d) = %d\n",ii,jj,alt[ii][jj]); */
        if (alt[ii][jj] < min || kmin == -1) {
          /* printf("-- New min\n"); */
          min = alt[ii][jj];
          kmin = k;
        }
      }
      if (kmin != -1 && min < alt[i][j]) {
        dir[i][j] = kmin;
      } else {
        dir[i][j] = 9;
      }
    }
}

char mkijgrp(int i, int j) {
  if (group[i][j]>0) return group[i][j];
  if (dir[i][j]==9) return group[i][j] = next++;
  return group[i][j] = mkijgrp(i+d[dir[i][j]][0],j+d[dir[i][j]][1]);
}

void mkgrp() {
  int i,j;
  memset(group,0,sizeof(group));
  next = 'a';
  for (i=0;i<H;i++)
    for (j=0;j<W;j++)
      mkijgrp(i,j);
}


int main() {
  int T,t,i,j;
  scanf("%d",&T);
  for (t=0;t<T;t++) {
    scanf("%d",&H);
    scanf("%d",&W);
    for (i=0;i<H;i++)
      for (j=0;j<W;j++)
        scanf("%d",&alt[i][j]);
    mkdir();
    //        prt();
    mkgrp();
    printf("Case #%d:\n",t+1);
    prtgroup();
  }
}
