#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TIME 3600

int t, na, nb;
int a[MAX_TIME], b[MAX_TIME];

int main() {
  int i,j,k,n,m,h,aux;
  int mina, minb;

  scanf("%d",&n);
  for (i=1; i<=n; i++) {
    scanf("%d",&t);
    scanf("%d %d",&na,&nb);
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    for (j=0; j<na; j++) {
      scanf("%d:%d",&h,&m); aux=h*60+m;
      for (k=aux;k<MAX_TIME;k++) a[k]--;
      scanf("%d:%d",&h,&m); aux=h*60+m;
      for (k=aux+t;k<MAX_TIME;k++) b[k]++;
    }
    for (j=0; j<nb; j++) {
      scanf("%d:%d",&h,&m); aux=h*60+m;
      for (k=aux;k<MAX_TIME;k++) b[k]--;
      scanf("%d:%d",&h,&m); aux=h*60+m;
      for (k=aux+t;k<MAX_TIME;k++) a[k]++;
    }

    mina = minb = 0;
    for (k=0; k<MAX_TIME; k++) {
      if (a[k]<mina) mina=a[k];
      if (b[k]<minb) minb=b[k];
    }
    printf("Case #%d: %d %d\n",i,-mina,-minb);
  }


  return 0;
}
