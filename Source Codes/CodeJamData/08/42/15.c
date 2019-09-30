#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
  int i, j, k, test;
  int n, m, a, l, o, p, q;
  double a1, a2, a3, s;
  int x1, y1, x2, y2, f;

  scanf("%d",&test);
  for(k=1;k<=test;k++){
    scanf("%d%d%d",&n,&m,&a);
    f=0;
    for(i=0;i<=n;i++){
      for(j=0;j<=m;j++){
	for(p=0;p<=n;p++){
	  for(q=0;q<=m;q++){
	    a1=(double)sqrt(i*i+j*j);
	    a2=(double)sqrt(p*p+q*q);
	    a3=(double)sqrt((i-p)*(i-p)+(j-q)*(j-q));
	    s=(a1+a2+a3)/2.;
	    if((sqrt(s*(s-a1)*(s-a2)*(s-a3))<=(double)a/2.+1e-7)&&(sqrt(s*(s-a1)*(s-a2)*(s-a3))>=(double)a/2.-1e-7)){
	      x1=i;
	      y1=j;
	      x2=p;
	      y2=q;
	      f=1;
	      //printf("%lf\n",sqrt(s*(s-a1)*(s-a2)*(s-a3)));
	      goto label;
	    }
	  }
	}
      }
    }
  label:
    printf("Case #%d: ",k);
    if(f==1)printf("0 0 %d %d %d %d\n",x1,y1,x2,y2);
    else puts("IMPOSSIBLE");
  }
}
