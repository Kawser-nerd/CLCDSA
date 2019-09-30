#include <stdio.h>
#include <string.h>

int b[256][256];
int c[256][256];

int main() {
  int cases,r,x1,y1,x2,y2,i,j,k,tid,caseno=1;
  scanf("%d",&cases);
  while(cases--) {
    memset(b,0,sizeof(b));
    scanf("%d",&r);
    for(i=0;i<r;i++) {
      scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
      for(j=x1;j<=x2;j++) for(k=y1;k<=y2;k++) b[j][k]=1;
    }
    for(tid=1;;tid++) {
      memcpy(c,b,sizeof(b));
      for(i=1;i<256;i++) for(j=1;j<256;j++) {
        if(b[i][j] && !b[i-1][j] && !b[i][j-1]) c[i][j]=0;
        if(!b[i][j] && b[i-1][j] && b[i][j-1]) c[i][j]=1;
      }
      k=0;
      for(i=1;i<256;i++) for(j=1;j<256;j++) k+=c[i][j];
      memcpy(b,c,sizeof(b));
      if(!k) break;
    }
    printf("Case #%d: %d\n",caseno++,tid);
  }
  
  
  
  return 0;
}
