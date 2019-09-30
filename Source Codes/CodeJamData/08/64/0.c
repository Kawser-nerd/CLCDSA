#include<stdio.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

void intReverse(int d[],int size){
  int a=0, b=size-1, t;
  while(a<b) t=d[a], d[a]=d[b], d[b]=t, a++, b--;
}

int intNextPermutation(int d[],int size){
  int i,j,k;

  for(k=size-2;k>=0;k--) if(d[k]<d[k+1]) break;
  if(k<0){intReverse(d,size); return 0;}

  for(i=size-1;;i--) if(d[i]>d[k]) break;
  j=d[i], d[i]=d[k], d[k]=j;
  intReverse(d+k+1, size-k-1);
  
  return 1;
}

int n,m;
int edge[10][10];
int tar[10][10];
int d[10];

int main(){
  int i,j,k,l;
  int size,count=0;
  int res;

  scanf("%d",&size);
  while(size--){
    scanf("%d",&n); res=0;
    rep(i,n) rep(j,n) edge[i][j]=0;
    REP(k,1,n){
      scanf("%d%d",&i,&j); i--; j--;
      edge[i][j]=edge[j][i]=1;
    }
    scanf("%d",&m);
    rep(i,m) rep(j,m) tar[i][j]=0;
    REP(k,1,m){
      scanf("%d%d",&i,&j); i--; j--;
      tar[i][j]=tar[j][i]=1;
    }
    rep(i,10) d[i]=i;
    do{
      int tmp=0;
      rep(i,m) if(!tmp) rep(j,m) if( edge[d[i]][d[j]] != tar[i][j] ) {tmp=1; break;}
      if(tmp==0){res=1; break;}
    } while(intNextPermutation(d,n));

    printf("Case #%d: ",++count);
    if(res==0) puts("NO"); else puts("YES");
  }

  return 0;
}
