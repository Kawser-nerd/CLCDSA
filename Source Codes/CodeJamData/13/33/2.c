#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#if 0
#define DEBUG
#endif

int zaatu_size;
long long zaatu_table_raw[2000000];
long long zaatu_table[2000000];
int zaatu_dupe[2000000];

int zaatu_getid(long long x) {
	int left,right,mid;
	left=0;right=zaatu_size-1;
	while(left<=right) {
		mid=(left+right)/2;
		if(x==zaatu_table[mid])return mid;
		else if(x<zaatu_table[mid])right=mid-1; else left=mid+1;
	}
	return 0;
}

typedef struct {
	int day;
	long long start,end,height;
	int startid,endid;
} attack_t;

attack_t attack_list[1000000];

int qsort_comp(const void* x,const void* y) {
	const attack_t* a=(const attack_t*)x;
	const attack_t* b=(const attack_t*)y;
	if((a->day)>(b->day))return 1;
	if((a->day)<(b->day))return -1;
	return 0;
}

int qsort_comp_ll(const void* x,const void* y) {
	const long long* a=(const long long*)x;
	const long long* b=(const long long*)y;
	if(*a>*b)return 1;
	if(*a<*b)return -1;
	return 0;
}

#define SEGTREE_MAX 4194304

typedef struct {
	long long maxheight;
	long long minheight;
	int isall;
} segtree_t;

segtree_t segtree[SEGTREE_MAX*2-1];

void segtree_init(void) {
	int i;
	for(i=0;i<SEGTREE_MAX*2-1;i++) {
		segtree[i].minheight=segtree[i].maxheight=0;
		segtree[i].isall=1;
	}
}

long long segtree_getminmax_internal(int node,int kstart,int kend,int start,int end,int ismin) {
	long long candidate1,candidate2;
	if(kend<=start || end<=kstart) {
		return ismin?LLONG_MAX:LLONG_MIN;
	}
	if(start<=kstart && kend<=end) {
		return ismin?segtree[node].minheight:segtree[node].maxheight;
	}
	if(segtree[node].isall) {
		segtree[node*2+1].maxheight=segtree[node*2+2].maxheight=segtree[node].maxheight;
		segtree[node*2+1].minheight=segtree[node*2+2].minheight=segtree[node].minheight;
		segtree[node*2+1].isall=segtree[node*2+2].isall=1;
	}
	candidate1=segtree_getminmax_internal(node*2+1,kstart,(kstart+kend)/2,start,end,ismin);
	candidate2=segtree_getminmax_internal(node*2+2,(kstart+kend)/2,kend,start,end,ismin);
	if(ismin)return candidate1<candidate2?candidate1:candidate2;
	else return candidate1>candidate2?candidate1:candidate2;
}

long long segtree_getminmax(int start,int end,int ismin) {
	return segtree_getminmax_internal(0,0,SEGTREE_MAX,start,end,ismin);
}

void segtree_build_internal(int node,int kstart,int kend,int start,int end,long long height) {
	if(kend<=start || end<=kstart)return;
	if(start<=kstart && kend<=end) {
		if(segtree[node].maxheight<=height) {
			segtree[node].minheight=segtree[node].maxheight=height;
			segtree[node].isall=1;
		} else if(kend>kstart+1 && segtree[node].minheight<height) {
			if(segtree[node].isall) {
				segtree[node*2+1].maxheight=segtree[node*2+2].maxheight=segtree[node].maxheight;
				segtree[node*2+1].minheight=segtree[node*2+2].minheight=segtree[node].minheight;
				segtree[node*2+1].isall=segtree[node*2+2].isall=1;
			}
			segtree_build_internal(node*2+1,kstart,(kstart+kend)/2,start,end,height);
			segtree_build_internal(node*2+2,(kstart+kend)/2,kend,start,end,height);
			segtree[node].isall=0;
			segtree[node].maxheight=segtree[node*2+1].maxheight;
			if(segtree[node*2+2].maxheight>segtree[node].maxheight) {
				segtree[node].maxheight=segtree[node*2+2].maxheight;
			}
			segtree[node].minheight=segtree[node*2+1].minheight;
			if(segtree[node*2+2].minheight<segtree[node].minheight) {
				segtree[node].minheight=segtree[node*2+2].minheight;
			}
		}
	} else {
		if(segtree[node].isall) {
			segtree[node*2+1].maxheight=segtree[node*2+2].maxheight=segtree[node].maxheight;
			segtree[node*2+1].minheight=segtree[node*2+2].minheight=segtree[node].minheight;
			segtree[node*2+1].isall=segtree[node*2+2].isall=1;
		}
		segtree_build_internal(node*2+1,kstart,(kstart+kend)/2,start,end,height);
		segtree_build_internal(node*2+2,(kstart+kend)/2,kend,start,end,height);
		segtree[node].isall=0;
		segtree[node].maxheight=segtree[node*2+1].maxheight;
		if(segtree[node*2+2].maxheight>segtree[node].maxheight) {
			segtree[node].maxheight=segtree[node*2+2].maxheight;
		}
		segtree[node].minheight=segtree[node*2+1].minheight;
		if(segtree[node*2+2].minheight<segtree[node].minheight) {
			segtree[node].minheight=segtree[node*2+2].minheight;
		}
	}
}

void segtree_build(int start,int end,long long height) {
	segtree_build_internal(0,0,SEGTREE_MAX,start,end,height);
}

int main(void) {
	int caseNum,caseCount;
	scanf("%d",&caseNum);
	for(caseCount=1;caseCount<=caseNum;caseCount++) {
		int d,n,w,e,s,delta_d,delta_p,delta_s;
		int N,i,j;
		int attack_count=0;
		int success_count=0;
		scanf("%d",&N);
		for(i=0;i<N;i++) {
			scanf("%d%d%d%d%d%d%d%d",
				&d,&n,&w,&e,&s,&delta_d,&delta_p,&delta_s);
			for(j=0;j<n;j++) {
				attack_list[attack_count].day=d+delta_d*j;
				attack_list[attack_count].start=w+(long long)delta_p*j;
				attack_list[attack_count].end=e+(long long)delta_p*j;
				attack_list[attack_count].height=s+(long long)delta_s*j;
				attack_count++;
			}
		}
		qsort(attack_list,attack_count,sizeof(attack_t),qsort_comp);

		for(i=0;i<attack_count;i++) {
			zaatu_table_raw[i*2]=attack_list[i].start;
			zaatu_table_raw[i*2+1]=attack_list[i].end;
		}
		qsort(zaatu_table_raw,attack_count*2,sizeof(long long),qsort_comp_ll);
		zaatu_dupe[0]=0;
		for(i=1;i<attack_count*2;i++) {
			if(zaatu_table_raw[i]==zaatu_table_raw[i-1])zaatu_dupe[i]=1;
			else zaatu_dupe[i]=0;
		}
		for(i=1;i<attack_count*2;i++)zaatu_dupe[i]+=zaatu_dupe[i-1];
		for(i=0;i<attack_count*2;i++)zaatu_table[i-zaatu_dupe[i]]=zaatu_table_raw[i];
		zaatu_size=attack_count*2-zaatu_dupe[attack_count*2-1];

#ifdef DEBUG
		for(i=0;i<zaatu_size;i++)printf("%lld ",zaatu_table[i]);
		putchar('\n');
#endif

		for(i=0;i<attack_count;i++) {
			attack_list[i].startid=zaatu_getid(attack_list[i].start)*2;
			attack_list[i].endid=zaatu_getid(attack_list[i].end)*2;
			
		}

		segtree_init();
		for(i=0;i<attack_count;i=j) {
			for(j=i;j<attack_count && attack_list[j].day==attack_list[i].day;j++) {
#ifdef DEBUG
				printf("attack %d [%lld,%lld] [%d,%d] %d\n",
					attack_list[j].day,
					attack_list[j].start,attack_list[j].end,
					attack_list[j].startid,attack_list[j].endid,
					attack_list[j].height);
#endif
				if(segtree_getminmax(attack_list[j].startid,attack_list[j].endid+1,1)<attack_list[j].height) {
					success_count++;
#ifdef DEBUG
					printf("hit %d [%lld,%lld] [%d,%d] %d\n",
						attack_list[j].day,
						attack_list[j].start,attack_list[j].end,
						attack_list[j].startid,attack_list[j].endid,
						attack_list[j].height);
#endif
				}
			}
			for(j=i;j<attack_count && attack_list[j].day==attack_list[i].day;j++) {
				segtree_build(attack_list[j].startid,attack_list[j].endid+1,attack_list[j].height);
			}
#ifdef DEBUG
			{
				int k;
				for(k=0;k<zaatu_size*2;k++)printf("%lld ",segtree_getminmax(k,k+1,1));
				putchar('\n');
			}
#endif
		}

		printf("Case #%d: %d\n",caseCount,success_count);
	}
	return 0;
}
