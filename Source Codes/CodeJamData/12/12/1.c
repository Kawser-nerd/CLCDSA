#include <stdio.h>
#include <string.h>

int n;
int a[1000],b[1000];
int clear[1000];

/*
	greedy:
	- if there is a level with <2 stars which we can do now with 2-star rating: pick it
	- otherwise, clear something at 1 stars
*/

int main() {
	int T,caseno=1,i,ans,stars,ok,high,ix;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		for(i=0;i<n;i++) scanf("%d %d",&a[i],&b[i]);
		memset(clear,0,n*sizeof(int));
		ans=0;
		stars=0;
		while(stars<2*n) {
			ok=0;
			for(i=0;i<n;i++) if(clear[i]<2 && b[i]<=stars) {
				stars+=2-clear[i];
				clear[i]=2;
				ok=1;
				ans++;
			}
			if(ok) continue;
			high=0;
			ix=-1;
			for(i=0;i<n;i++) if(!clear[i] && a[i]<=stars) {
				if(high<b[i]) high=b[i],ix=i;
			}
			if(ix>-1) {
				ans++;
				stars++;
				clear[ix]=1;
				goto again;
			}
			printf("Case #%d: Too Bad\n",caseno++);
			goto done;
		again:;
		}
		printf("Case #%d: %d\n",caseno++,ans);
	done:;
	}
	return 0;
}
