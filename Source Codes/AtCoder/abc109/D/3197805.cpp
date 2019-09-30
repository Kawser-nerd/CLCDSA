#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int h,w,i,j;
  scanf("%d",&h);
  scanf("%d",&w);
  int a[h][w];
  for(i=0;i<h;i++) {
    for(j=0;j<w;j++) {
      scanf("%d",&a[i][j]);
    }
  }
  int x[h*w][4];
  int n = 0;
  for(i=0;i<h;i++) {
    for(j=0;j<w-1;j++) {
      if(a[i][j]>0 && a[i][j]%2==1) {
        a[i][j]--;
        a[i][j+1]++;
        x[n][0] = i;
        x[n][1] = j;
        x[n][2] = i;
        x[n][3] = j+1;
        n++;
      }
    }
  }
  for(i=0;i<h-1;i++) {
    if(a[i][j]>0 && a[i][w-1]%2==1) {
      a[i][w-1]--;
      a[i+1][w-1]++;
      x[n][0] = i;
      x[n][1] = w-1;
      x[n][2] = i+1;
      x[n][3] = w-1;
      n++;
    }
  }
  printf("%d\n",n);
  if(n>0) {
    for(i=0;i<n;i++) {
      printf("%d %d %d %d\n",x[i][0]+1,x[i][1]+1,x[i][2]+1,x[i][3]+1);
    }
  }
  return 0;
}