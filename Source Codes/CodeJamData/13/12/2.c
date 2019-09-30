#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

typedef struct {
	int v,ix;
} thing_t;
thing_t v[10001];
int E,R,N;

int compt(const void *A,const void *B) {
	const thing_t *a=A,*b=B;
	if(a->v>b->v) return -1;
	if(a->v<b->v) return 1;
	return 0;
}

int spent[10001];
int left[10001];
ll ans;

void process(int ix) {
	int pos=v[ix].ix;
	int i,energy=left[pos],can=left[pos],reduce=0;
	for(energy=0,i=pos;i<N;i++) {
		energy-=spent[i];
		if(reduce>energy) reduce=energy;
		energy+=R;
		if(energy>E) energy=E;
	}
	can+=reduce;
	ans+=(ll)can*v[ix].v;
	spent[pos]=can; left[pos]-=can; energy=left[pos]+R; 
	for(i=pos+1;i<N;i++) {
		energy-=spent[i];
		left[i]=energy;
		energy+=R;
		if(energy>E) energy=E;
	}
}

int main() {
	int T,no=1,i;
	scanf("%d",&T);
	while(T--) {
		scanf("%d %d %d",&E,&R,&N);
		for(i=0;i<N;i++) scanf("%d",&v[i].v),v[i].ix=i;
		if(R>E) R=E;
		ans=0;
		qsort(v,N,sizeof(thing_t),compt);
		for(i=0;i<N;i++) left[i]=E,spent[i]=0;
		for(i=0;i<N;i++) process(i);
		printf("Case #%d: %I64d\n",no++,ans);
	}
	return 0;
}
