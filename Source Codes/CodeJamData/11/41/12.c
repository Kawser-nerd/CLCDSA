#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int speed;
    int length;
} walkway;
walkway W[1001];

static int cmp(const void *p1, const void *p2)
{
  return ((walkway *)p1)->speed - ((walkway *)p2)->speed;
}

int main(int argc, char **argv) {
  int T,tc,X,S,R,t,N,B,E,ws,i;
  double run, time, ct;
  scanf("%d",&T);
  for(tc=1;tc<=T;++tc) {
    scanf("%d %d %d %d %d",&X,&S,&R,&t,&N);
    for(i=1;i<=N;++i) {
        scanf("%d %d %d",&B,&E,&ws);
        W[i].length=E-B;
        W[i].speed=ws;
        X-=E-B;
    }
    W[0].length=X;
    W[0].speed=0;
    qsort(W,N+1,sizeof(walkway),cmp);
    run=t;
    time=0;
    for(i=0;i<=N;++i) {
        if(run>0) {
            ct=((double)W[i].length)/((double)W[i].speed+R);
            if(run>=ct) {
                run-=ct;
                time+=ct;
            } else {
                time+=run+((double)W[i].length-run*((double)W[i].speed+R))/((double)W[i].speed+S);
                run=0;
            }
        } else {
            ct=((double)W[i].length)/((double)W[i].speed+S);
            time+=ct;
        }
    }
    printf("Case #%d: %.6lf\n", tc, time);
  }
  return 0;
}

