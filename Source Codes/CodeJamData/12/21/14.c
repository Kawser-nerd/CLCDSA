#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

int n, j[200], x, i;

double bs(double imin, double imax) {
  int k;
  double imid=(imin+imax)/2.;
  if(imax-imin<1e-12)
    return imid;
  double pt=j[i]+imid*x, ptl=1.-imid;
  for(k=0;k<n;k++)
    if(k!=i && j[k]<pt)
      ptl-=(pt-j[k])/x;
  if(ptl>=0.)
    return bs(imid,imax);
  else
    return bs(imin,imid);
}

//pt=j[i]+x*y[i];
int main(void) {
  int tc, cn;
  scanf("%d", &tc);
  for(cn=1;cn<=tc;cn++) {
    x=0;
    scanf("%d", &n);
    for(i=0;i<n;i++) {
      scanf("%d", &j[i]);
      x+=j[i];
    }
    printf("Case #%d:", cn);
    for(i=0;i<n;i++)
      printf(" %.6lf", bs(0., 1.)*100.0);
    printf("\n");
  }
  return 0;
}
