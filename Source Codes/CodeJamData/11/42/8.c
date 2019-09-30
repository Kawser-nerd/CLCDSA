#include <stdio.h>
#include <math.h>

char g[16][16];
int r,c,d;
#define EPS 1e-9
int ok(int size,int sx,int sy) {
  double cx=size*0.5,cy=size*0.5;
  double massx=0,massy=0,dx,dy;
  int i,j,p;
  int mass=0;
  for(i=0;i<size;i++) for(j=0;j<size;j++) {
    if((i==0 || i==size-1) && (j==0 || j==size-1)) continue;
    dx=i-cx+0.5;
    dy=j-cy+0.5;
    p=d+g[i+sx][j+sy]-48;
    massx+=dx*p;
    massy+=dy*p;
    mass+=p;
  }
  massx/=mass;
  massy/=mass;
/*  printf("tried size %d at %d,%d: (%f %f), expected (%f %f)\n",size,sx,sy,massx,massy,cx,cy);*/
  return fabs(massx)<EPS && fabs(massy)<EPS;
}

int main() {
  int cases,caseno=1,i,j,size;
  scanf("%d",&cases);
  while(cases--) {
    scanf("%d %d %d",&r,&c,&d);
    for(i=0;i<r;i++) scanf("%s",g[i]);
    /*  try all sizes */
    for(size=10;size>2;size--) {
      for(i=0;i<=r-size;i++) for(j=0;j<=c-size;j++) {
        /*  make a blade starting at i,j (upper left) */
        if(ok(size,i,j)) {
          printf("Case #%d: %d\n",caseno++,size);
          goto done;
        }
      }
    }
    printf("Case #%d: IMPOSSIBLE\n",caseno++);
  done:;
  }
  return 0;
}
