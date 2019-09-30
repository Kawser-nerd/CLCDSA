#include <iostream>
#include <cstring>
using namespace std;

const int MAXN=110;
const int MAXM=22000;
const long long INF=101000000000LL;
struct Edge {
	int to;
	long long flow;
	Edge *next, *pair;
}g[MAXM],*head[MAXN];
int eptr=0;
Edge* _addedge(int a, int b, long long f) {
	g[eptr].to = b;
	g[eptr].flow = f;
	g[eptr].next = head[a];
	head[a] = &g[eptr];
	return &g[eptr++];
}
void addEdge (int a, int b, long long f) {
	Edge* t1=_addedge(a,b,f);
	Edge* t2=_addedge(b,a,0);
	t1->pair=t2; t2->pair=t1;
}

int S,T,maxsap;
int h[MAXN],nh[MAXN];
long long sap(int p, long long low) {
	if (p==T)
		return low;
	long long left=low;
	int hmin=maxsap;
	for (Edge *e=head[p]; e; e=e->next) {
		if (e->flow>0 && h[p]==h[e->to]+1) {
			long long tt=sap(e->to, min(e->flow,left));
			e->flow-=tt; e->pair->flow+=tt;
			left-=tt;
			if (!left || h[S]==maxsap)
				return low-left;
		}
		if (e->flow>0 && hmin>h[e->to]+1)
			hmin = h[e->to]+1;
	}
	if (low==left) {
		if (! --nh[h[p]])
			h[S]=maxsap;
		else
			++nh[ h[p]=hmin ];
	}
	return low-left;
}
int main() {
	memset(head, 0, sizeof(head));
	memset(h,0,sizeof(h));
	memset(nh,0,sizeof(nh));
	int n;
	cin>>n;
	S=0; T=n+1; maxsap=T+1; nh[0]=maxsap;
	long long ans1=0;
	for (int i=1; i<=n; i++) {
		int tt; cin>>tt;
		if (tt>0) {
			ans1 += tt;
			addEdge(i, T, tt);
		}
		else
			addEdge(S, i, -tt);
	}
	for (int i=1; i<=n; i++)
		for (int k=2; i*k<=n; k++)
			addEdge(i, i*k, INF);
	long long ans2=0;
	while (h[S]<maxsap)
		ans2 += sap(S,INF);
	cout<<ans1-ans2<<endl;
	return 0;
}