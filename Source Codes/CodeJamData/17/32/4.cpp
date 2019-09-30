#include <cstdio>
#include <cstdlib>

int T,AC,AJ;
int L=1440;
int schedule[1999];
typedef struct {
	int len;
	int type;
}space_st;
space_st spaces[2008];
int cmp(const void *ka,const void *kb) {
	space_st *a=(space_st *)ka;
	space_st *b=(space_st *)kb;
	if(a->type!=b->type) return a->type-b->type;
	if(a->type==2) return b->len-a->len;
	return a->len-b->len;
}
int main() {
	scanf("%d",&T);
	for(int cases=1;cases<=T;cases++) {
		scanf("%d%d",&AC,&AJ);
		int rem1=L/2;
		for(int i=0;i<L;i++) schedule[i]=0;
		for(int i=0;i<AC;i++) {
			int va,vb;
			scanf("%d%d",&va,&vb);
			for(int j=va;j<vb;j++) schedule[j]=1;
		}
		for(int i=0;i<AJ;i++) {
			int va,vb;
			scanf("%d%d",&va,&vb);
			for(int j=va;j<vb;j++) schedule[j]=2;
		}
		int M=0;
		int sol=0;
		for(int i=0;i<L;i++) if(schedule[i]==1) rem1--;
		for(int i=0;i<L;i++) if(schedule[i]==1&&schedule[(i+L-1)%L]!=1) sol++;
		for(int i=0;i<L;i++) if(schedule[i]==0&&schedule[(i+L-1)%L]!=0) {
			int left=i;
			int right=i;
			while(schedule[right]==0) {
				right++;
				if(right==L) right=0;
			}
			spaces[M].len=(right+L-left)%L;
			spaces[M].type=0;
			if(schedule[(i+L-1)%L]==2) spaces[M].type++;
			if(schedule[right]==2) spaces[M].type++;
			M++;
		}
		qsort(spaces,M,sizeof(space_st),cmp);
		for(int i=0;i<M;i++) {
			if(rem1==0) break;
			if(rem1<spaces[i].len) {
				rem1=0;
				if(spaces[i].type==2) sol++;
			} else {
				rem1-=spaces[i].len;
				if(spaces[i].type==0) sol--;
				if(spaces[i].type==2) sol++;
			}
		}
		printf("Case #%d: %d\n",cases,sol*2);
	}
	return 0;
}
