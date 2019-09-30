#include <stdio.h>
int a[1000];
int main(){
	int t, q;
	scanf("%d", &t);
	for(q=1;q<=t;q++) {
		int n;
		scanf("%d", &n);
		int i;
		for(i=0;i<n;i++)
			scanf("%d", a+i);
		int maxd = 0;
		int ans1 = 0;
		for (i=1;i<n;i++){
			int d = a[i-1]-a[i];
			if (d > maxd)
				maxd = d;
			if (a[i]<a[i-1])
				ans1 += a[i-1]-a[i];
		}
		int ans2=0;
		for (i=0;i<n-1;i++) {
			if (a[i] < maxd)
				ans2+=a[i];
			else
				ans2+=maxd;
		}
		printf("Case #%d: %d %d\n", q, ans1, ans2);
	}
}
