#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
typedef struct data{
	double r,h;
}data;
int cmp(const data* a,const data* b){
	return a->r<b->r;
}
int cmp1(const data* a,const data* b){
	return a->h < b->h;
}
int main(){
	int num;
	scanf("%d",&num);
	for(int i=0;i<num;i++){
		int N,K;
		scanf("%d%d",&N,&K);
		data D[N],E[N];
		for(int j=0;j<N;j++){
			scanf("%lf%lf",&D[j].r,&D[j].h);
			E[j].r=D[j].r;
			D[j].h=(double)2*M_PI*D[j].r*D[j].h;
			E[j].h=D[j].h;

		}
		for(int j=0;j<N;j++) printf("%lf %lf\n",E[j].r,E[j].h);
		printf("\n");
		qsort(D,N,sizeof(data),cmp);
		qsort(E,N,sizeof(data),cmp1);
		double max=0,max_r=0;
		for(int j=0;j<N;j++) printf("%lf %lf\n",E[j].r,E[j].h);
		for(int j=0;j<K-1;j++){
			max=max+E[j].h;
			if(E[j].r>max_r) max_r=E[j].r;
		}
		max=max+(M_PI*max_r*max_r);
		double sur=0,hh=0;
		for(int j=K-1;j<N;j++){
				if(E[j].r > max_r){
					if(E[j].r*E[j].r*M_PI + E[j].h > sur) sur=E[j].r*E[j].r*M_PI + E[j].h;
				}
				else{
					if(E[j].h> hh) hh=E[j].h;
				}
			}
		if(sur>hh) printf("Case #%d: %.9lf\n",i+1,max-(M_PI*max_r*max_r)+sur);
		else printf("Case #%d: %.9lf\n",i+1,max+hh);
	}
	return 0;
}
