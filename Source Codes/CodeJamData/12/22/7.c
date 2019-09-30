#include <stdio.h>
#include <string.h>
#define MAX(e,f) (((e)>(f))?(e):(f))
#define MIN(e,f) (((e)<(f))?(e):(f))
#define HOGE (-1000000000)
#define chk(e,f,s,t) if(MIN(f[e][f],f[s][t])<=c[s][t]-50){tmp.x=s;tmp.}
int c[108][108],f[108][108];
int r[108][108];

typedef struct pair{
	int x,y;
	int z;
}PAIR;

PAIR q[1000008];
int qn;

void push(PAIR x){
	int i=qn++,pr;
	while(i>0){
		pr=(i-1)/2;
		if(q[pr].z>=x.z)break;
		q[i]=q[pr];
		i=pr;
	}
	q[i]=x;
}
PAIR pop(){
	PAIR res,x;
	int i=0,pc;
	res=q[0];x=q[--qn];
	while(i*2+1<qn){
		pc=i*2+1;
		if(pc+1<qn&&q[pc+1].z>q[pc].z)pc++;
		if(q[pc].z<=x.z)break;
		q[i]=q[pc];
		i=pc;
	}
	q[i]=x;
	return res;
}

int main(){
	int t,n,m,h,k,i,j,tx,ty,tz;
	PAIR tmp;
	scanf("%d",&t);
	for(k=1;k<=t;k++){
		memset(c,0,sizeof(c));
		memset(f,0,sizeof(f));
		memset(r,0,sizeof(r));
		scanf("%d%d%d",&h,&n,&m);
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				scanf("%d",&c[i][j]);
				r[i][j]=HOGE;
			}
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				scanf("%d",&f[i][j]);
			}
		}
		qn=0;
		tmp.x=1;tmp.y=1;tmp.z=h;
		push(tmp);
		while(qn){
			tmp=pop();
			tx=tmp.x;ty=tmp.y;tz=tmp.z;
			if(r[tx][ty]!=HOGE)continue;
			r[tx][ty]=tz;
			if(tx==n&&ty==m)break;
			if(MAX(f[tx][ty],f[tx-1][ty])<=MIN(c[tx][ty],c[tx-1][ty])-50){
				tmp.x=tx-1;tmp.y=ty;
				tmp.z=MIN(tz,MIN(h,c[tx-1][ty]-50));
				if(h<=c[tx-1][ty]-50&&tz>=h){
					tmp.z=h;
				}else if(tmp.z>=f[tx][ty]+20){
					tmp.z-=10;
				}else{
					tmp.z-=100;
				}
				push(tmp);
			}
			if(MAX(f[tx][ty],f[tx+1][ty])<=MIN(c[tx][ty],c[tx+1][ty])-50){
				tmp.x=tx+1;tmp.y=ty;
				tmp.z=MIN(tz,MIN(h,c[tx+1][ty]-50));
				if(h<=c[tx+1][ty]-50&&tz>=h){
					tmp.z=h;
				}else if(tmp.z>=f[tx][ty]+20){
					tmp.z-=10;
				}else{
					tmp.z-=100;
				}
				push(tmp);
			}
			if(MAX(f[tx][ty],f[tx][ty-1])<=MIN(c[tx][ty],c[tx][ty-1])-50){
				tmp.x=tx;tmp.y=ty-1;
				tmp.z=MIN(tz,MIN(h,c[tx][ty-1]-50));
				if(h<=c[tx][ty-1]-50&&tz>=h){
					tmp.z=h;
				}else if(tmp.z>=f[tx][ty]+20){
					tmp.z-=10;
				}else{
					tmp.z-=100;
				}
				push(tmp);
			}
			if(MAX(f[tx][ty],f[tx][ty+1])<=MIN(c[tx][ty],c[tx][ty+1])-50){
				tmp.x=tx;tmp.y=ty+1;
				tmp.z=MIN(tz,MIN(h,c[tx][ty+1]-50));
				if(h<=c[tx][ty+1]-50&&tz>=h){
					tmp.z=h;
				}else if(tmp.z>=f[tx][ty]+20){
					tmp.z-=10;
				}else{
					tmp.z-=100;
				}
				push(tmp);
			}
		}
		printf("Case #%d: %.1f\n",k,(h-r[n][m])*1.0/10.0);
	}
	return 0;
}
