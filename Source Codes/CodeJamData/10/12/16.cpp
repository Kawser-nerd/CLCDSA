#include<cstdio>
#include<algorithm>

using namespace std;

int T,d,e,m,n;
int i,t,j,I=0;
int v[1000],opt[1000],nopt[1000];

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d%d%d",&d,&e,&m,&n);
		for (i=0;i<n;++i) scanf("%d",&v[i]);
		for (i=0;i<256;++i) opt[i]=0;
		for (t=0;t<n;++t){
			for (i=0;i<256;++i) nopt[i]=opt[i]+d;
			for (i=0;i<256;++i)
			    for (j=max(0,i-m);j<=min(255,i+m);++j)
			    	nopt[i]=min(nopt[i],opt[j]+abs(v[t]-i));
			for (i=0;i<256;++i)
				for (j=i;j<=i+m && j<256;++j)
				    nopt[j]=min(nopt[j],nopt[i]+e);
			for (i=255;i>=0;--i)
				for (j=i;j>=i-m && j>=0;--j)
				    nopt[j]=min(nopt[j],nopt[i]+e);
			for (i=0;i<256;++i) opt[i]=nopt[i];
		}
		int ret=opt[0];
		for (i=0;i<256;++i)
		    ret=min(ret,opt[i]);
		printf("Case #%d: %d\n",++I,ret);
	}
}
