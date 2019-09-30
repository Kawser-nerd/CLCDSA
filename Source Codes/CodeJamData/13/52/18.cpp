#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int t,tt,a[22],x[22],y[22],n,s;
bool u[22],q;
vector<int> g[22];
int sol() {
  int s=0,i,j,k;
  for (i=0; i<n; i++) for (j=i+1; j<n; j++) {
    int A=y[j]-y[i];
	int B=x[i]-x[j];
	int C=-A*x[i]-B*y[i];
	bool fi=true,neg;
	int mx=max(x[i],x[j]),nx=min(x[i],x[j]);
	int my=max(y[i],y[j]),ny=min(y[i],y[j]);
	for (k=0; k<n; k++) if (k!=i && k!=j) {
	  int D=A*x[k]+B*y[k]+C;
	  if (D==0) {
	    if (x[k]>=nx && x[k]<=mx && y[k]>=ny && y[k]<=my) break;
	  } else {
	    if (fi) neg=(D<0); else {
		  if (D>0 && neg) break;
		  if (D<0 && (!neg)) break;
		}
	    fi=false;
	  }
	}
	if (k>=n) { g[i].push_back(j); g[j].push_back(i); }
  }
  for (i=0; i<n; i++) if (g[i].size()!=2 && g[i].size()!=0) puts("!!!!!!!");
  for (i=0; i<n; i++) if (g[i].size()==2) {
    j=g[i][0];
    s=(x[j]+x[i])*(y[j]-y[i]);
//	printf("%d-->%d %d\n",i,j,s);
    for (int pr=i; j!=i; ) {
	  int pj=j;
	  j=g[j][0]+g[j][1]-pr;
	  s+=(x[j]+x[pj])*(y[j]-y[pj]);
//	  printf("%d->%d %d\n",pj,j,s);
	  pr=pj;
	}
	break;
  }
  return abs(s);
}
bool inters(int i, int j, int ii, int jj) {
//printf("int %d %d %d %d\n",i,j,ii,jj);
  int A1=y[j]-y[i],B1=x[i]-x[j],C1=-A1*x[i]-B1*y[i];
  int A2=y[jj]-y[ii],B2=x[ii]-x[jj],C2=-A2*x[ii]-B2*y[ii];
  long long z1=A1*x[ii]+B1*y[ii]+C1;
  long long z2=A1*x[jj]+B1*y[jj]+C1;
  long long z3=A2*x[i]+B2*y[i]+C2;
  long long z4=A2*x[j]+B2*y[j]+C2;
  if (z1*z2==0 && z3*z4==0) {
    int la=min(x[i],x[j]),ra=max(x[i],x[j]);
	int lb=min(x[ii],x[jj]),rb=max(x[ii],x[jj]);
	if (max(la,lb)<=min(ra,rb)) {
	  la=min(y[i],y[j]); ra=max(y[i],y[j]);
	  lb=min(y[ii],y[jj]); rb=max(y[ii],y[jj]);
	  return max(la,lb)<=min(ra,rb);
	} else return false;
  }
  return (z1*z2<=0 && z3*z4<=0);
}
void rec(int l, int cur) {
//printf("rec %d %d\n",l,a[l-1]);
  if (l==n) {
    for (int j=2; j<n-1; j++) if (inters(a[j-1],a[j],a[0],a[n-1])) return;
	cur+=(x[a[0]]+x[a[n-1]])*(y[a[0]]-y[a[n-1]]);
	if (abs(cur)*2>s) q=true;
	//printf("==== %d\n",cur);
	return;
  }
  for (int i=0; i<n; i++) if (!u[i]) {
    int j;
    for (j=1; j<l-1; j++) if (inters(a[j-1],a[j],a[l-1],i)) break;
	if (j<l-1) continue;
    u[i]=true;	
	a[l]=i;
	rec(l+1,cur+(x[a[l]]+x[a[l-1]])*(y[a[l]]-y[a[l-1]]));
	u[i]=false;
	if (q) return;
  }
}
int main() {
  freopen("Bs.in","r",stdin);
  freopen("Bs.out","w",stdout);
  scanf("%d",&tt);
  for (t=1; t<=tt; t++) {
    scanf("%d",&n);
	for (int i=0; i<n; i++) {
	  scanf("%d%d",&x[i],&y[i]);
	  g[i].clear();
	}
	s=sol();
	//printf("%d\n",s);
	u[0]=true;
	q=false;
	rec(1,0);
    printf("Case #%d:",t);
	for (int i=0; i<n; i++) printf(" %d",a[i]);
	puts("");
  }
  return 0;
}
