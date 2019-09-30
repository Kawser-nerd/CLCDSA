#include <stdio.h>
int f[100001];
int d[100001];
int I[100001];
#define min(a,b) ((a)<(b)?(a):(b))
int main(){
	int t,p;
	scanf("%d", &t);
	for(p=1;p<=t;p++){
		printf("Case #%d: ", p);
		int n;
		scanf("%d", &n);
		int i;
		for(i=0;i<n;i++){
			scanf("%d%d", d+i, I+i);
		}
		int D;
		scanf("%d", &D);
		memset(f,-1,sizeof(f));
		f[0]=d[0];
		for(i=0;i<n;i++){
			int j;
			for(j=i+1;j<n;j++){
				if(d[j]-d[i]>f[i])break;
				if(f[j]==-1)
					f[j]=min(I[j],d[j]-d[i]);
			}
		}
		for(i=0;i<n;i++)
			if(f[i]>=D-d[i])
				break;
		if(i<n)
			printf("YES\n");
		else
			printf("NO\n");
	}
}
