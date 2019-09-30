//Input 2
#include <cstdio>
#include <cstdlib>

int T,N,K;
double P;
double list[58];
double list_backup[58];
int cmp(const void *ka,const void *kb) {
	double a=*(double *)ka;
	double b=*(double *)kb;
	if(a<b) return -1;
	if(a>b) return 1;
	return 0;
}
double EPS=0.00000000001;
double dp[58];
int main() {
	scanf("%d",&T);
	for(int cases=1;cases<=T;cases++) {
		scanf("%d%d",&N,&K);
		scanf("%lf",&P);
		for(int i=0;i<N;i++) scanf("%lf",&list[i]);
		qsort(list,N,sizeof(double),cmp);
		list[N]=1;
		for(int i=0;i<=N;i++) list_backup[i]=list[i];
		double sol=0;
		double P_backup=P;
		for(int begin=0;begin<N;begin++) {
			P=P_backup;
			for(int i=0;i<=N;i++) list[i]=list_backup[i];
			for(int i=begin+1;i<=N;i++) {
				if(P+EPS<(list[i]-list[i-1])*(i-begin)) {
					for(int j=begin;j<i;j++) list[j]+=P/(i-begin);
					break;
				}
				P-=(list[i]-list[i-1])*(i-begin);
				for(int j=begin;j<i;j++) list[j]=list[i];
			}
			for(int i=0;i<=N;i++) dp[i]=0;
			dp[0]=1;
			for(int i=0;i<N;i++) {
				for(int j=N-1;j>=0;j--) {
					dp[j+1]+=dp[j]*list[i];
					dp[j]=dp[j]*(1.0-list[i]);
				}
			}
			double ksol=0;
			for(int i=K;i<=N;i++) ksol+=dp[i];
			if(sol<ksol) sol=ksol;
		}
		P=P_backup;
		for(int i=0;i<=N;i++) list[i]=list_backup[i];
		for(int i=N-1;i>=0;i--) {
			if(P>1.0-list[i]) {
				P-=1.0-list[i];
				list[i]=1;
			} else {
				list[i]+=P;
				break;
			}
		}
		for(int i=0;i<=N;i++) dp[i]=0;
		dp[0]=1;
		for(int i=0;i<N;i++) {
			for(int j=N-1;j>=0;j--) {
				dp[j+1]+=dp[j]*list[i];
				dp[j]=dp[j]*(1.0-list[i]);
			}
		}
		double ksol=0;
		for(int i=K;i<=N;i++) ksol+=dp[i];
		if(sol<ksol) sol=ksol;
		printf("Case #%d: %.12lf\n",cases,sol);
	}
	return 0;
}
