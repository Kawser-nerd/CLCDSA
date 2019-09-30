#include<cstdio>
#include<cmath>
#define L 2000

using namespace std;

int T,n;
double x[L],y[L],z[L],p[L],nx,ny,nz,q,ans,l,r,mid;
int i,j,k,I;

main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for (i=0;i<n;++i) scanf("%lf%lf%lf%lf",&x[i],&y[i],&z[i],&p[i]);
		l=0;r=1e10;
		while (r-l>1e-8){
			mid=(l+r)/2;
			bool bt=true;
			for (i=0;bt && i<n;++i)
			    for (j=i+1;bt && j<n;++j)
					if (fabs(x[i]-x[j])+fabs(y[i]-y[j])+fabs(z[i]-z[j])>(mid+1e-8)*(p[i]+p[j])+1e-8){
						bt=false;
						break;
					}
			if (bt) r=mid;
			else l=mid;
		}
		printf("Case #%d: %.10lf\n",++I,l);
	}
}
