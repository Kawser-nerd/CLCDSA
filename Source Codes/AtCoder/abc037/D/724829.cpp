#include<cstdio>
#define F for(p=0;p<h*w;++p)
using namespace std;int M=1e9+7,h,w,a[1<<20],c[1<<20],r=0,p;int f(int x,int y){int u[]={1,0,-1,0},v[]={0,1,0,-1},&z=c[y*w+x],d,s,t;if(!~z){z=1;for(d=0;d<4;++d){s=x+u[d];t=y+v[d];0<=s&&s<w&&0<=t&&t<h&&a[t*w+s]>a[y*w+x]?z=(z+f(s,t))%M:0;}}return z;}int main(){scanf("%d%d",&h,&w);F c[p]=-1;F scanf("%d",&a[p]);F r=(r+f(p%w,p/w))%M;printf("%d\n",r);}