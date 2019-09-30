#include <stdio.h>
#include <stdlib.h>
#define MAX 1000000
typedef struct {
  int B,E,w;
} rull;
int X,S,R,t,N;
rull a[MAX];

int compr(const void *A,const void *B) {
  rull *a=(rull *)A,*b=(rull *)B;
  if(a->w < b->w) return -1;
  if(a->w > b->w) return 1;
  return 0;
}

int main() {
  double tid,runleft,tt1,tt2,len,len2;
  int cases,caseno=1,i,un,ss,rr;
  scanf("%d",&cases);
  while(cases--) {
    scanf("%d %d %d %d %d",&X,&S,&R,&t,&N);
    un=X;
    for(i=0;i<N;i++) scanf("%d %d %d",&a[i].B,&a[i].E,&a[i].w),un-=a[i].E-a[i].B;
    qsort(a,N,sizeof(rull),compr);
    runleft=t;
    tid=0;

    len=un;
    tt1=len/S;
    tt2=len/R;
    if(tt2<runleft) {
      /*  we can run on all non-walkways */
      runleft-=tt2;
      tid+=tt2;
    } else {
      /*  use t time */
      len2=R*runleft;
      tid+=runleft+(len-len2)/S;
      runleft=0;
    }

    for(i=0;i<N;i++) {
      ss=S+a[i].w;
      rr=R+a[i].w;
      len=a[i].E-a[i].B;
      tt1=(double)len/ss;
      tt2=(double)len/rr;
      if(tt2<runleft) {
        runleft-=tt2;
        tid+=tt2;
      } else {
        len2=rr*runleft;
        tid+=runleft+(len-len2)/ss;
        runleft=0;
      }
    }


    
    printf("Case #%d: %.10f\n",caseno++,tid);
  }
  return 0;
}
