#include<math.h>
int X[]={0,1,0,-1};
int Y[]={1,0,-1,0};
int h,w,M=1e9,rr,t,a,c[510][510],sy,gy,sx,gx,nx,ny,y[300000],x[300000],i,j;
int main(){
	char s[510][510]={};
	double l=-1,r=10,m,eps=1e-9;
	scanf("%d %d",&h,&w);
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			scanf(" %c",&s[i+1][j+1]);
			if(s[i+1][j+1]=='s')s[sy=i+1][sx=j+1]='#';
			if(s[i+1][j+1]=='g')s[gy=i+1][gx=j+1]='#';
		}
	}//printf("%d %d %d %d\n",sx,sy,gx,gy);
	while(r-l>eps){
		for(i=0;i<h*w;i++)c[i/w+1][i%w+1]=M;
		c[y[0]=sy][x[0]=sx]=t=0;
		m=(l+r)/2;//printf("%lf %lf %lf\n",l,r,m);
		for(rr=1;rr-t;t++){//printf("%d %d\n",y[t],x[t]);
			a=c[y[t]][x[t]];
			for(i=0;i<4;i++){
				ny=y[t]+Y[i];
				nx=x[t]+X[i];
				if(ny==gy&&nx==gx)goto NEXT;
				if(s[ny][nx]<'0'||'9'<s[ny][nx])continue;//printf("!b\n");
				if(c[ny][nx]<=a+1)continue;//printf("!a\n");
				//printf("!%lf %d\n",(s[ny][nx]-'0')*pow(0.99,a+1),a);
				if((s[ny][nx]-'0')*pow(0.99,a+1)<m)continue;
				c[y[rr]=ny][x[rr]=nx]=a+1;
				rr++;
			}
		}
		r=m;
		continue;
		NEXT:
		l=m;
	}
	//if(l<0)l=-1;
	printf("%.10lf\n",l);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
  scanf("%d %d",&h,&w);
  ^
./Main.c:8:2: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:8:2: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:40:2: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
  printf("%.10lf\n",l);
  ^
./Main.c:40:2: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:40:2: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’