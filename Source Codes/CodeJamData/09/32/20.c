#include <stdio.h>
#include <math.h>

int p[500][3];
int v[500][3];

int main(){
  int i,j,test,T,N;
  double A,B,C,dmin,tmin;
  double xa,xb,ya,yb,za,zb,w,D,a,b;
  scanf("%d",&T);
  for(test=1;test<=T;test++){
    scanf("%d",&N);
    for(i=0;i<N;i++){
      scanf("%d%d%d",&p[i][0],&p[i][1],&p[i][2]);
      scanf("%d%d%d",&v[i][0],&v[i][1],&v[i][2]);
    }
    xa=xb=ya=yb=za=zb=0.0;
    for(i=0;i<N;i++){
      xa+=p[i][0];xb+=v[i][0];
      ya+=p[i][1];yb+=v[i][1];
      za+=p[i][2];zb+=v[i][2];
    }
    w=N;
    xa=xa/w;xb=xb/w;
    ya=ya/w;yb=yb/w;
    za=za/w;zb=zb/w;
    A=xb*xb+yb*yb+zb*zb;
    B=2*(xb*xa+yb*ya+zb*za);
    C=xa*xa+ya*ya+za*za;
    
    dmin=C-(B*B)/(4.0*A);
    if(dmin>=0.0){
      tmin=(-1.0*B)/(2.0*A);
      dmin=sqrt(dmin);
      if(tmin<0.000001){
	xa=ya=za=0.0;
	for(i=0;i<N;i++){
	  xa+=p[i][0];
	  ya+=p[i][1];
	  za+=p[i][2];
	}
	w=N;
	xa=xa/w;
	ya=ya/w;
	za=za/w;
	tmin=0.0;
	dmin=xa*xa+ya*ya+za*za;
	dmin=sqrt(dmin);
	printf("Case #%d: %.8lf %.8lf\n",test,dmin,tmin);
      }else
	printf("Case #%d: %.8lf %.8lf\n",test,dmin,tmin);
    }else{
      D=B*B-4.0*A*C;
      D=sqrt(D);
      a=(-B-D)/(2.0*A);
      b=(-B+D)/(2.0*A);
      if(a>0.0){
	dmin=0.0;tmin=a;
	printf("Case #%d: %.8lf %.8lf\n",test,dmin,tmin);
      }else if(b>0.0){
	dmin=0.0;tmin=b;
	printf("Case #%d: %.8lf %.8lf\n",test,dmin,tmin);
      }else{
	xa=ya=za=0.0;
	for(i=0;i<N;i++){
	  xa+=p[i][0];
	  ya+=p[i][1];
	  za+=p[i][2];
	}
	w=N;
	xa=xa/w;
	ya=ya/w;
	za=za/w;
	tmin=0.0;
	dmin=xa*xa+ya*ya+za*za;
	dmin=sqrt(dmin);
	printf("Case #%d: %.8lf %.8lf\n",test,dmin,tmin);
      }
    }
  }
  return 0;
}
