#include <cstdio>
#include <cstdlib>

int N,T,K;
typedef struct {
	int rs;
	int hs;
}cake_st;
cake_st cakes[1008];
int cmp(const void *ka,const void *kb) {
	cake_st *a=(cake_st *)ka;
	cake_st *b=(cake_st *)kb;
	if(a->rs!=b->rs) return a->rs-b->rs;
	return a->hs-b->hs;
}
double PI=3.14159265358979;
double list[1008];
int main() {
	scanf("%d",&T);
	for(int cases=1;cases<=T;cases++) {
		scanf("%d%d",&N,&K);
		for(int i=0;i<N;i++) scanf("%d%d",&cakes[i].rs,&cakes[i].hs);
		qsort(cakes,N,sizeof(cake_st),cmp);
		for(int i=0;i<K;i++) list[i]=0;
		double sol=0;
		for(int i=0;i<N;i++) {
			double ksol=PI*cakes[i].rs*cakes[i].rs+PI*2*cakes[i].hs*cakes[i].rs;
			for(int j=0;j<K-1;j++) ksol+=PI*2*list[j];
			if(sol<ksol) sol=ksol;
			double cur=(double)cakes[i].hs*cakes[i].rs;
			for(int j=0;j<K;j++) if(list[j]<cur) {
				double temp=list[j];
				list[j]=cur;
				cur=temp;
			}
		}
		printf("Case #%d: %.12lf\n",cases,sol);
	}
	return 0;
}
