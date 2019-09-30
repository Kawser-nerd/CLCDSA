#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define NEAR(Z,Y) ((Z)<(Y)&&(Z)>-(Y))
#define ABSOL(A) ((A)>=0?(A):-(A))

int gcd(int a,int b){
	int c;
	if(a<0)a=-a;
	if(b<0)b=-b;
	while(b!=0){
		c=a%b;
		a=b;
		b=c;
	}
	return a;
}

char room[32][32];

int raytrace(const int a,const int b,int x,int y,const int dist){
	int path[128][2],npath,ix,iy,c,d,refx,refy;
	double len,px,py;

	if(b==0){
		int c;
		for(c=0;room[x+c*a][y]!='#';c++);
		return c*2-1<=dist;
	}
	if(a==0){
		int c;
		for(c=0;room[x][y+c*b]!='#';c++);
		return c*2-1<=dist;
	}

	len=sqrt(a*a+b*b);
	npath=ABSOL(a)+ABSOL(b);
	if(a%2!=0&&b%2!=0)npath--;
	px=py=0.5;
	ix=iy=0;
	for(c=0;c<npath;c++){
		double t1,t2;
		int iscorner;
		t1=((ix+(a>0))-px)/a;
		t2=((iy+(b>0))-py)/b;

		path[c][0]=0;
		path[c][1]=0;
		if(NEAR(t1-t2,1e-8))iscorner=1;
		else iscorner=0;
if(iscorner==1&&c*2+1!=npath)fprintf(stderr,"corner\n");
		if(iscorner||t1<t2){
			path[c][0]=(a>0?1:-1);
			if(iscorner==0)py+=((ix+(a>0)-px)/a)*b;
			px=ix+(a>0);
		}
		if(iscorner||t1>t2){
			path[c][1]=(b>0?1:-1);
			if(iscorner==0)px+=((iy+(b>0)-py)/b)*a;
			py=iy+(b>0);
		}
		if(path[c][0]==0&&path[c][1]==0)fprintf(stderr,"t1t2error\n");

		ix+=path[c][0];
		iy+=path[c][1];
	}

	refx=refy=1;
	for(d=1;dist+1e-5>=len*d;d++){
		for(c=0;c<npath;c++){
			int dx,dy;
			dx=path[c][0]*refx;
			dy=path[c][1]*refy;
			if(dx!=0&&dy!=0){/*corner*/
				if(room[x+dx][y+dy]!='#')goto loopfinish;/*through*/
				if(room[x+dx][y]!='#'&&room[x][y+dy]!='#')return 0;/*destroy*/
			}
			if(dx!=0&&room[x+dx][y]=='#'){/*x reflect*/
				dx=0;
				refx=-refx;
			}
			if(dy!=0&&room[x][y+dy]=='#'){/*y reflect*/
				dy=0;
				refy=-refy;
			}
			loopfinish:
			x+=dx;
			y+=dy;
		}
		if(room[x][y]=='X')return 1;
	}
	return 0;
}

int main(int argc,char*argv[]){
	int a,b,d,e,dist,h,w,x,y,count;
	scanf("%d",&e);
	for(d=1;d<=e;d++){
		scanf("%d%d%d",&h,&w,&dist);
		x=y=-1;
		for(a=0;a<h;a++){
			scanf("%s",room[a]);
			for(b=0;x==-1&&b<w;b++){
				if(room[a][b]!='X')continue;
				x=a;
				y=b;
			}
		}
		count=0;
		for(a=-dist;a<=dist;a++){
			for(b=-dist;b<=dist;b++){
				if(a==0&&b==0)continue;
				if(a*a+b*b>dist*dist)continue;
				if(gcd(a,b)!=1)continue;
				count+=raytrace(a,b,x,y,dist);
			}
		}
		printf("Case #%d: %d\n",d,count);
	}
	return 0;
}
