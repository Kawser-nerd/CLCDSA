#include<stdio.h>
#include<queue>
using namespace std;

int a[1024][3];
int n,S,R,X;
double T;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;

int main() {
	int N,cs=0;
	for(scanf("%d",&N);N--;) {
		scanf("%d %d %d %lf %d",&X,&S,&R,&T,&n);
		int s=0;
		double ret=0.0;
		for(int i=0;i<n;i++) {
			scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
			if (a[i][0]>s) pq.push(make_pair(S,a[i][0]-s));
			pq.push(make_pair(S+a[i][2],a[i][1]-a[i][0]));
			s=a[i][1];
		}
		if (s<X) pq.push(make_pair(S,X-s));
		for(;!pq.empty();pq.pop()) {
			int v=pq.top().first,len=pq.top().second;
			double tt=len/(double)(v+R-S);
			if (T>tt) {
				ret+=tt;
				T-=tt;
			} else {
				ret+=T;
				ret+=(len-(v+R-S)*T)/v;
				T=0;
			}
		}
		printf("Case #%d: %.10lf\n",++cs,ret);
	}
	return 0;
}
