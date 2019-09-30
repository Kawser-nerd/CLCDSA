#include <stdio.h>

typedef struct _D{
	double r, c;
}D;

int comp(const void* a, const void* b){
	D* x = (D*)a;
	D* y = (D*)b;
	if(x->c<y->c) return -1;
	if(y->c<x->c) return 1;
	return 0;
}

int main(){
	int T,N;
	double V,X;
	int t,i,j;
	D d[2];
	scanf("%d",&T);
	for(t=1;t<=T;t++){
		scanf("%d %lf %lf",&N,&V,&X);
		for(i=0;i<N;i++){
			scanf("%lf %lf",&d[i].r,&d[i].c);
		}
		qsort(d,N,sizeof(D),comp);
		/*
		for(i=0;i<N;i++){
			printf(" : %lf %lf",d[i].r,d[i].c);
		}
		*/
		if(N==1){
			if(d[0].c != X) printf("Case #%d: IMPOSSIBLE\n",t);
			else  printf("Case #%d: %.7lf\n",t,V/d[0].r);
		}else{
			if(d[0].c >X || d[1].c < X) printf("Case #%d: IMPOSSIBLE\n",t);
			else{
				if(d[1].c == d[0].c){
					double r = d[0].r+d[1].r;
					printf("Case #%d: %.7lf\n",t,V/r);
				}else{
					double cdiff = d[1].c-d[0].c;
					double d1t = (V*(X-d[0].c)/cdiff)/d[1].r;
					double d2t = (V*(d[1].c-X)/cdiff)/d[0].r;
					double dt = (d1t>d2t)?d1t:d2t;
					printf("Case #%d: %.7lf\n",t,dt);
				}
			}
		}
	}
	return 0;
}
