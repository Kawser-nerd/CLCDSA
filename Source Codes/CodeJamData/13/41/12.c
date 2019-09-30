#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MOD 1000002013LL
typedef long long ll;

ll N,M;
typedef struct {
	ll a,b,c;
} from_t;
from_t from[10000000];

int compf(const void *A,const void *B) {
	const from_t *a=A,*b=B;
	if(a->a<b->a) return -1;
	if(a->a>b->a) return 1;
	if(a->b<b->b) return -1;
	if(a->b>b->b) return 1;
	return 0;
}

void unique() {
	int i,j;
	for(i=j=1;i<M;i++) if(from[i].a==from[i-1].a && from[i].b==from[i-1].b) from[j-1].c+=from[i].c;
	else from[j].a=from[i].a,from[j].b=from[i].b,from[j++].c=from[i].c;
	M=j;
}

void lolsort() {
	qsort(from,M,sizeof(from_t),compf);
	unique();
}

int calccost() {
	int i;
	ll d,r=0;
	for(i=0;i<M;i++) {
		d=(from[i].b-from[i].a);
		r=(r+(N*(ll)d-d*(d-1LL)/2)%MOD*from[i].c)%MOD;
	}
	return r;
}

int overlap(int ix,int iy) {
	return from[ix].a<from[iy].a && from[iy].a<=from[ix].b && from[ix].b<from[iy].b;
}

int calccost2() {
	int r=0,i,j,ch=0,oldM;
	ll num;
	do {
		ch=0;
		lolsort();
		oldM=M;
		for(i=0;i<oldM;i++) if(from[i].c>0) {
			/* find overlap */
			for(j=i+1;j<oldM;j++) if(from[j].c && overlap(i,j)) {
//				printf("%d (%I64d %I64d %I64d) and %d (%I64d %I64d %I64d) overlap)\n",i,from[i].a,from[i].b,from[i].c,j,from[j].a,from[j].b,from[j].c);
				num=from[i].c<from[j].c?from[i].c:from[j].c;
				from[i].c-=num;
				from[j].c-=num;
				from[M].a=from[i].a; from[M].b=from[j].b; from[M++].c=num;
				from[M].a=from[j].a; from[M].b=from[i].b; from[M++].c=num;
				ch=1;
			}
		}
	} while(ch);
	return r;
}

int main() {
	int T,no=1,i;
	int normalcost,optcost;
	scanf("%d",&T);
	while(T--) {
		scanf("%I64d %I64d",&N,&M);
		for(i=0;i<M;i++) scanf("%I64d %I64d %I64d",&from[i].a,&from[i].b,&from[i].c);
		lolsort();
		normalcost=calccost();
		calccost2();
		optcost=calccost();
		normalcost-=optcost;
		if(normalcost<0) normalcost+=MOD;
		printf("Case #%d: %d\n",no++,normalcost);
	}
	return 0;
}
