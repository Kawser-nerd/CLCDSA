#include<cstdio>
#include<algorithm>

using namespace std;

int T,I,i,j,n,k,c;
long long int opt[11][1<<11][12];

const long long inf=102400000000000LL;

int main(){
	scanf("%d",&T);
	while (T--){
		printf("Case #%d: ",++I);
		scanf("%d",&n);
		for (i=0;i<(1<<n);++i){
			scanf("%d",&k);
			for (j=0;j<=n;++j)
			    if (j<=k) opt[0][i][j]=0;
			    else opt[0][i][j]=inf;
		}
		for (i=1;i<=n;++i)
		    for (j=0;j<(1<<(n-i));++j){
				scanf("%d",&c);
				for (k=0;k<=n-i;++k){
					opt[i][j][k]=min(opt[i-1][j*2][k+1]+opt[i-1][j*2+1][k+1],opt[i-1][j*2][k]+opt[i-1][j*2+1][k]+c);
					if (opt[i][j][k]>inf) opt[i][j][k]=inf;
				}
			}
		printf("%I64d\n",opt[n][0][0]);
	}
}
