#include<stdio.h>
#include <math.h>
#define abs(x) ((x)>0?(x):(-(x)))
#define pi (3.1415926)
#define e (2.718281828)
long double g[1100][1100];
void calc(int n){
	g[0][0]=1;
	g[1][0]=0.5;
	g[1][1]=0.5;
	int i;
	for(i=1;i<n;i++){
		int j;
		g[i][0]=g[i-1][0]*(long double)0.5;
		for(j=1;j<i;j++)
			g[i][j]=(g[i-1][j]+g[i-1][j-1])*(long double)0.5;
		g[i][i]=g[i][0];
	}
}
long double pcalc(int k, int y){
	long double ans=0;
	int i;
	for(i=y;i<=k;i++){
		ans+=g[k][i];
	}
	return ans;
}
int main(){
	calc(1100);
	int cases;
	scanf("%d", &cases);
	int cc;
	for(cc=1; cc<=cases; cc++){
		int x,y,n;
		scanf("%d%d%d", &n, &x, &y);
		/* first we find how many diamond should be piled first */
		unsigned long long t = (y+abs(x))/2;
		unsigned long long m = (2*t-1)*t;
		unsigned long long m2 = m+4*t+1;
		if(n>=m2){
			printf("Case #%d: 1.0\n",cc);
		}else{
			if(n<=m){
				printf("Case #%d: 0.0\n", cc);
			}else{
				if(x == 0){
					printf("Case #%d: 0.0\n",cc);
				}else{
					unsigned long long k=n-m;
					unsigned long long top=2*t;
					if(k>=top+y+1){
						printf("Case #%d: 1.0\n",cc);
					}else{
						printf("Case #%d: %.06Lf\n", cc, pcalc(k, y+1));
					}
				}
			}
		}
	}
	return 0;
}

