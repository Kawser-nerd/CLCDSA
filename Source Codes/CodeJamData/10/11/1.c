#include <stdio.h>

char m[64][64];
char o[64][64];
int N,K;

void rot() {
  int i,j;
  for(i=0;i<N;i++) for(j=0;j<N;j++) o[N-j-1][i]=m[i][j];
  for(i=0;i<N;i++) for(j=0;j<N;j++) m[i][j]=o[i][j];
}

void fall() {
  int i,j,k;
  for(i=0;i<N;i++) {
    j=N-1;
    for(k=N-1;k>=0;k--) if(m[k][i]!='.') m[j--][i]=m[k][i];
    while(j>=0) m[j--][i]='.';
  }
}

int dx[]={1,1,0,-1};
int dy[]={0,1,1,1};

int check(char w) {
  int i,j,k,l,x,y;
  for(i=0;i<N;i++) for(j=0;j<N;j++) if(m[i][j]==w) {
    for(k=0;k<4;k++) {
      for(l=1;l<K;l++) {
        x=i+dx[k]*l; y=j+dy[k]*l;
        if(x<0 || y<0 || x>=N || y>=N) break;
        if(m[x][y]!=w) break;
      }
      if(l==K) return 1;
    }
  }
  return 0;
}

int main() {
  int cases,caseno=1,i,res;
  scanf("%d",&cases);
  while(cases--) {
    scanf("%d %d",&N,&K);
    for(i=0;i<N;i++) scanf("%s",m[i]);
    rot();
    rot();
    rot();
    fall();
    res=check('R')+2*check('B');
    printf("Case #%d: %s\n",caseno++,
      res<2?(res?"Red":"Neither")
        :(res>2?"Both":"Blue"));
  }
  return 0;
}
