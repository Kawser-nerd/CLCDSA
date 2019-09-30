#include<stdio.h>
#include<string.h>
#include<math.h>

int a[64][3];
int n;
int b[64],b1[64];

struct point {
	double x,y;
};

point cross(double x1,double y1,double r1,double x2,double y2,double r2) {
	double d=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	double s=sqrt((r1+r2+d)*(r1+r2-d)*(r1-r2+d)*(r2-r1+d))/4;
	double h=s*2/d;
	double s1=sqrt(r1*r1-h*h);
	double x=(x2-x1)/d*s1+x1,y=(y2-y1)/d*s1+y1;
	x+=(y2-y1)/d*h,y-=(x2-x1)/d*h;
	point ret;
	ret.x=x,ret.y=y;
	return ret;
}

double cal() {
	int i,j,k,ll,m,flag,c;
	double l=0,r=5000,R;
	point p1,p2;
	if (n==1) return a[0][2];
	if (n==2) {
		if (a[0][2]<a[1][2]) return a[1][2]; else return a[0][2];
	}
	for(i=0;i<n;i++) if (a[i][2]>l) l=a[i][2];
	while(r-l>1e-8) {
		R=(l+r)*.5;
		flag=0;
		for(i=0;i<n && !flag;i++) for(j=0;j<n && !flag;j++) if (i!=j) {
			if ((a[i][0]-a[j][0])*(a[i][0]-a[j][0])+(a[i][1]-a[j][1])>(R+R-a[i][2]-a[j][2])*(R+R-a[i][2]-a[j][2])+1e-9) continue;
			p1=cross(a[i][0],a[i][1],R-a[i][2],a[j][0],a[j][1],R-a[j][2]);
			memset(b,0,sizeof(b));
			for(c=m=0;m<n;m++) if ((p1.x-a[m][0])*(p1.x-a[m][0])+(p1.y-a[m][1])*(p1.y-a[m][1])<(R-a[m][2])*(R-a[m][2])+1e-9) b[m]=1,c++;
			if (c>=n-1) flag=1;
			for(k=0;k<n && !flag;k++) for(ll=0;ll<n && !flag;ll++) if (!b[k] && !b[ll] && k!=ll) {
				if ((a[k][0]-a[ll][0])*(a[k][0]-a[ll][0])+(a[k][1]-a[ll][1])*(a[k][1]-a[ll][1])>(R+R-a[k][2]-a[ll][2])*(R+R-a[k][2]-a[ll][2])+1e-9) continue;
				p2=cross(a[k][0],a[k][1],R-a[k][2],a[ll][0],a[ll][1],R-a[ll][2]);
				for(m=0;m<n;m++)
					if (!((p1.x-a[m][0])*(p1.x-a[m][0])+(p1.y-a[m][1])*(p1.y-a[m][1])<(R-a[m][2])*(R-a[m][2])+1e-9 ||
						(p2.x-a[m][0])*(p2.x-a[m][0])+(p2.y-a[m][1])*(p2.y-a[m][1])<(R-a[m][2])*(R-a[m][2])+1e-9)) break;
//printf("%lf %lf %lf %lf %lf %d\n",p1.x,p1.y,p2.x,p2.y,R,m);
				if (m>=n) flag=1;
			}
		}
		if (flag) r=R; else l=R;
	}
	return (l+r)/2;
}

int main() {
	int N,cs=0,i;

	for(scanf("%d",&N);N--;) {
		scanf("%d",&n);
		for(i=0;i<n;i++) scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
		printf("Case #%d: %.6lf\n",++cs,cal());
	}
	return 0;
}
