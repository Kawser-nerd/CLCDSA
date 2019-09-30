#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

void intIntSort(int d[],int m[],int s){int i=-1,j=s,k,t;if(s<=1)return;k=(d[0]+d[s-1])/2;for(;;){while(d[++i]<k);while(d[--j]>k);if(i>=j)break;t=d[i];d[i]=d[j];d[j]=t;t=m[i];m[i]=m[j];m[j]=t;}intIntSort(d,m,i);intIntSort(d+j+1,m+j+1,s-j-1);}

int X, Y, N;
int r[2000], ind[2000], val[2000];
int resX[2000], resY[2000];

int solve(int times){
  int i,j,k;
  int nowX, nowY;
  int putX, putY;
  int next;

  if(times){
    rep(i,N) val[i] = rand()%198247;
  } else {
    rep(i,N) val[i] = -r[ind[i]];
  }

  intIntSort(val, ind, N);

  nowX = nowY = 0;
  next = 0;
  rep(i,N){
    if(nowX == 0) putX = 0;
    else          putX = nowX + r[ind[i]];
    if(nowY == 0) putY = 0;
    else          putY = nowY + r[ind[i]];

    if(putX > X) break;
    if(putY > Y){ nowX = next; nowY = 0; i--; continue; }

    resX[ind[i]] = putX;
    resY[ind[i]] = putY;

    putX += r[ind[i]];
    putY += r[ind[i]];
    if(next < putX) next = putX;
    nowY = putY;
  }
  if(i==N) return 1;

  nowX = nowY = 0;
  rep(i,N){
    if(nowX == 0) putX = 0;
    else          putX = nowX + r[ind[i]];
    if(nowY == 0) putY = 0;
    else          putY = nowY + r[ind[i]];

    if(putY > Y) break;
    if(putX > X){ nowY = next; nowX = 0; i--; continue; }

    resX[ind[i]] = putX;
    resY[ind[i]] = putY;

    putX += r[ind[i]];
    putY += r[ind[i]];
    if(next < putY) next = putY;
    nowX = putX;
  }
  if(i==N) return 1;

  return 0;
}

int main(){
  int i,j,k;
  int size,count=0;

  scanf("%d",&size);
  while(size--){
    fprintf(stderr,"rest %d\n",size);
    
    scanf("%d%d%d",&N,&X,&Y);
    rep(i,N) scanf("%d",r+i);
    rep(i,N) ind[i] = i;

    for(k=0;;k++){
      if(solve(k)) break;
      fprintf(stderr,"WORNING!!!!\n");
    }

    printf("Case #%d:",++count);
    rep(i,N) printf(" %d %d",resX[i],resY[i]);
    puts("");
  }

  return 0;
}
