#include<stdio.h>
int main(){
	int t,n;
	scanf("%d",&t);
	int pp;
	for(pp=1;pp<=t;pp++){
		scanf("%d",&n);
		int min=2147483647,sum=0,xsum=0;
		int i;
		for(i=0;i<n;i++){
			int k;
			scanf("%d",&k);
			sum+=k;
			xsum^=k;
			if(k<min)min=k;
		}
		if(xsum!=0)
			printf("Case #%d: NO\n",pp);
		else
			printf("Case #%d: %d\n",pp,sum-min);
	}
	return 0;
}

