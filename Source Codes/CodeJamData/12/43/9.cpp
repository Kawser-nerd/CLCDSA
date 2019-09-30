#include<cstdio>
#include<algorithm>
#define L 10000

using namespace std;

int x[L],h[L];

bool deal(int l,int r){
	if (l==r-1)
		return true;
	int last=l;
	for (int i=l+1;i<r;++i){
		if (x[i]>r)
			return false;
		else if (x[i]==r){
			for (int j=last+1;j<i;++j){
				int high=h[r]-(r-j)*(long long)(h[r]-h[i])/(long long)(r-i);
				while ((h[r]-high)*(long long)(r-i)<(r-j)*(long long)(h[r]-h[i]))
					--high;
				if (high<0){
					printf("ERROR ");
					return false;
				}
				h[j]=min(h[j],high);
			}
			for (int j=i+1;j<r;++j){
				int high=h[r]-(r-j)*(long long)(h[r]-h[i])/(long long)(r-i);
				while ((h[r]-high)*(long long)(r-i)<=(r-j)*(long long)(h[r]-h[i]))
					--high;
				if (high<0){
					printf("ERROR ");
					return false;
				}
				h[j]=min(h[j],high);
			}
			if (!deal(last,i))
				return false;
			last=i;
		}
	}
	return true;
}

bool solve(){
	int n;
	scanf("%d",&n);
	for (int i=1;i<n;++i)
		scanf("%d",&x[i]);
	for (int i=1;i<=n;++i)
		h[i]=1000000000;
	for (int i=1;i<n;i=x[i]){
		for (int j=i+1;j<x[i];++j)
			h[j]=h[j]-1;
		if (!deal(i,x[i]))
			return false;
	}
	for (int i=1;i<=n;++i)
		printf(" %d",h[i]);
	puts("");
	return true;
}

int T,I=0;

int main(){
	scanf("%d",&T);
	while (T--){
		printf("Case #%d:",++I);
		if (!solve())
			puts(" Impossible");
	}
}
