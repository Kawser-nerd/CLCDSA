#include <stdio.h>
#include <limits.h>

int N;
int a[1000];

int main(void) {
	int i,j;
	int res=INT_MAX;
	int min=INT_MAX,max=INT_MIN;
	if(scanf("%d",&N)!=1)return 1;
	for(i=0;i<N;i++) {
		if(scanf("%d",&a[i])!=1)return 1;
		if(a[i]>max)max=a[i];
		if(a[i]<min)min=a[i];
	}
	for(i=min;i<=max;i++) {
		int evaluate=0;
		for(j=0;j<N;j++) {
			evaluate+=(a[j]-i)*(a[j]-i);
		}
		if(evaluate<res)res=evaluate;
	}
	printf("%d\n",res);
	return 0;
}