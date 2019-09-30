#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int won(int a, int b, int r) {
  int s,k,ak,nw=0;

  if (a < b) { s=a; a=b; b=s; }
  if (b <= 0) {
    //printf("a=%d b=%d r=%d\n",a,b,r);
    return(r%2 == 0);
  }
  if (b==1 && a>b) {
    return(r%2 == 0);
  }
  if (b==2 && a>3) {
    return(r%2 == 0);
  }
  if (b==2 && a==3) {
    return(r%2 == 1);
  }

  k = a/b;
  if (a%b == 0 && k > 1) {
    return(r%2 == 0);
  }
  if (k<1) k = 1;

  // printf("a=%d b=%d d=%d k=%d\n",a,b,d,k);

  for(ak=k;ak>=1;ak--)
    if (won(b, a-ak*b, r+1)) {
      nw++;
      if (r%2 == 0) return 1;
    }

  if (nw == k && r%2 == 1) return 1;

  return 0;
}

int main(int argc, char **argv) {
  int t,a1,a2,b1,b2;
  int i,j,k,w;

  scanf("%d\n",&t);


  for(i=1;i<=t;i++) {

    scanf("%d %d %d %d\n",&a1,&a2,&b1,&b2);

    //printf("%d-%d %d-%d\n",a1,a2,b1,b2);

    w = 0;
    for(j=a1;j<=a2;j++)
      for(k=b1;k<=b2;k++) {
	//printf("%d %d\n",j,k);
	if (won(j,k,0)) ++w;
      }

    printf("Case #%d: %d\n",i,w);

  }

  return 0;
}
