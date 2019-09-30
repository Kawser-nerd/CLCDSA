#include<cstdio>
#include<vector>
#include<algorithm>
#define L 10000
using namespace std;

const double eps=1e-10;

double x[L],y[L];
pair<int,int> r[L];
int pos;

void dfs(double lx,double ly,double rx,double ry){
	if (pos<0) return;
	if (min(rx-lx,ry-ly)<r[pos].first*2+eps){
		return;
	}
	if (rx-lx<ry-ly){
		double midy=(ry+ly)/2;
		if (midy-ly<r[pos].first*2+eps){
			x[r[pos].second]=(lx+rx)/2;
			y[r[pos].second]=(ly+ry)/2;
			pos--;
			return;
		}
		else{
			dfs(lx,ly,rx,midy);
			dfs(lx,midy,rx,ry);
		}
	}
	else{
		double midx=(rx+lx)/2;
		if (midx-lx<r[pos].first*2+eps){
			x[r[pos].second]=(lx+rx)/2;
			y[r[pos].second]=(ly+ry)/2;
			pos--;
			return;
		}
		else{
			dfs(lx,ly,midx,ry);
			dfs(midx,ly,rx,ry);
		}
	}

}

void solve(){
	int n,w,l;
	scanf("%d%d%d",&n,&w,&l);
	for (int i=0;i<n;++i){
		scanf("%d",&r[i].first);
		r[i].second=i;
	}
	x[0]=0;y[0]=0;
	for (int i=1;i<n;++i){
		if (w>l){
			x[i]=x[i-1]+r[i-1].first+r[i].first;
			y[i]=0;
		}
		else{
			y[i]=y[i-1]+r[i-1].first+r[i].first;
			x[i]=0;
		}
	}
	if (x[n-1]<=w+eps && y[n-1]<=l+eps){
		for (int i=0;i<n;++i)
			printf(" %.10lf %.10lf",x[i],y[i]);
		printf("\n");
		return;
	}
	sort(r,r+n);
	pos=n-1;
	dfs(0,0,w,l);
	if (pos>=0){
		printf("ERROR %d\n",pos);
		return;
	}
	for (int i=0;i<n;++i){
		printf(" %.10lf %.10lf",x[i],y[i]);
	}
	printf("\n");
}

int T,I=0;

int main(){
	scanf("%d",&T);
	while (T--){
		printf("Case #%d:",++I);
		solve();
	}
}
