#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

int tt;
int n,s;
int p[30],q[30];
double ans;
bool used[30];

void solve(int dep,double res,double posi) {
	if (dep==n) {
		ans=min(ans,res);
		return;
	}
	double tl=1e7,tr=1e7;
	tl*=1e7; tr*=1e7;
	int tli=-1,tri=-1;
	for (int i=0;i<n;++i)
		if (!used[i]) {
			double dist=fabs(posi-(res*q[i]+p[i]));
			double t=dist/(double)(s-abs(q[i]));
			if (p[i]>0) {
				if (t<tl) tl=t,tli=i;
			} else {
				if (t<tr) tr=t,tri=i;
			}
		}
	if (tli!=-1) {
		res+=tl;
		used[tli]=true;
		solve(dep+1,res,res*q[tli]+p[tli]);
		res-=tl;
		used[tli]=false;
	}
	if (tri!=-1){
		res+=tr;
		used[tri]=true;
		solve(dep+1,res,res*q[tri]+p[tri]);
		res-=tr;
		used[tri]=false;
	}
}

int main() {
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);

	scanf("%d",&tt);
	for (int ii=1;ii<=tt;++ii) {
		scanf("%d%d",&s,&n);
		for (int i=0;i<n;++i)
			scanf("%d",&p[i]);
		for (int i=0;i<n;++i) {
			scanf("%d",&q[i]);
			if (p[i]<0) q[i]*=-1;
		}

		ans=1e7;
		ans*=1e7;
		memset(used,false,sizeof(used));
		solve(0,0.0,0.0);

		printf("Case #%d: %.10f\n",ii,ans);
	}

}
