#include<cstdio>

using namespace std;

double opt[1<<17][20];
int T,j,I;
int n,x,i,k;
double p;

main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d %lf %d",&n,&p,&x);
		for (j=0;j<=n;++j){
			for (i=0;i<(1<<n+1);++i){
                if (i>=(1<<n)) opt[i][j]=1;
                else if (j==0) opt[i][j]=0;
				else {
					opt[i][j]=0;
					for (k=0;k<(1<<n);++k)
						if (k<=i)
							opt[i][j]>?=opt[i+k][j-1]*p+opt[i-k][j-1]*(1-p);
				}
			}
		}
		j=(((long long)x)<<n)/1000000;
		printf("Case #%d: %.10lf\n",++I,opt[j][n]);
	}
}
