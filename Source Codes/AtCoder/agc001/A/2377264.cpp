#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[2001],sum=0;

inline void init() {
	scanf("%d",&n);
	n*=2;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
}

inline void work() {
	for (int i=1;i<=n;i++) 
		if (i%2==1) 
			sum+=a[i]; 
}

int main() {
	init();
	work();
	printf("%d\n",sum);
	return 0;
}