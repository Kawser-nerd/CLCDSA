#include <stdio.h>
#include <string.h>

typedef long long ll;

int q[3000],qs,qe;
int seen[2000];
int R,k,N;
int caseno=1;
ll earned[1000000];

void brute() {
  int i,j,taken;
  ll euro=0;
  qs=qe=0;
  for(i=0;i<R;i++) {
    taken=0;
    qe=qs;
    while(qe-qs<N) {
      if(taken+q[qe]>k) break;
      taken+=q[qe++];
    }
    euro+=taken;
    qs=qe;
    while(qs>=N) qs-=N;
  }
  printf("Case #%d: %d\n",caseno++,euro);
}

void clever() {
  ll euro=0;
  ll taken;
  int i,j;
  int cycle;

  memset(earned,0,sizeof(earned));
  qs=qe=0;
  for(i=0;i<R;i++) {
    if(i>3000 && seen[qs]>=0) {
//      printf("at %d : seen[%d]=%d earned[%d]=%I64d\n",i,qs,seen[qs],seen[qs],earned[seen[qs]]);
      cycle=i-seen[qs];
      if((R-i)%cycle==0) {
//        printf("at %d av %d, cycle %d, %I64d %I64d\n",i,R,cycle,earned[seen[qs]],earned[seen[qs]-cycle]);
        euro+=((((ll)R-i)/cycle))*((ll)-earned[seen[qs]-cycle]+earned[seen[qs]]);
        goto done;
      }
    } else seen[qs]=i,earned[i]=euro;
    taken=0;
    qe=qs;
    while(qe-qs<N) {
      if(taken+q[qe]>k) break;
      taken+=q[qe++];
    }
    euro+=taken;
    qs=qe;
    while(qs>=N) qs-=N;
  }
done:
  printf("Case #%d: %I64d\n",caseno++,euro);
}

int main() {
  int cases,caseno,i;
  scanf("%d",&cases);
  while(cases--) {
    scanf("%d %d %d",&R,&k,&N);
    for(i=0;i<N;i++) scanf("%d",&q[i]),q[i+N]=q[i+N+N]=q[i];
    memset(seen,-1,sizeof(seen));
//    brute();
clever();
    
  }
  return 0;
}
