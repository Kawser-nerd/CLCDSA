#include<stdio.h>
#include<stdlib.h>

#define max(a,b) ((a)>(b)?(a):(b))

int compare_int(const void *a,const void *b){
	if( *(long long*)b>*(long long*)a)return 1;
	if( *(long long*)b==*(long long*)a)return 0;
	if( *(long long*)b<*(long long*)a)return -1;
}

struct sushi{
	long long d;
	int t;
};

long long heap[100000],sz=0;

void prio_push(long long x){
	int i=sz++;
	while(i>0){
		int p=(i-1)/2;
		if(heap[p]<=x)break;
		heap[i]=heap[p];
		i=p;
	}
	heap[i]=x;
}

long long prio_pop(){
	long long ret=heap[0];
	long long x=heap[--sz];
	int i=0;
	while(i*2+1<sz){
		int a=i*2+1,b=i*2+2;
		if(b<sz&&heap[b]<heap[a])a=b;
		if(heap[a]==x)break;
		heap[i]=heap[a];
		i=a;
	}
	heap[i]=x;
	return ret;
}

long long prio_r(){
	return heap[0];
}

int main(){
	int n,k;long long i;
	struct sushi td[100000];
	long long ans=0,v=0,anss[100000]={0};
	int va[100001]={0};
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++)scanf("%d%lld",&td[i].t,&td[i].d);
	qsort(td,n,sizeof(struct sushi),compare_int);
	for(i=0;i<k;i++){
		ans+=td[i].d;
		if(va[td[i].t]>0)prio_push(td[i].d);
		va[td[i].t]++;
	}
	for(i=0;i<=n;i++)v+=(va[i]>0?1:0);
	int vv=v;
	for(i=0;i<=n;i++)anss[i]=ans;
	for(i=k;i<n;i++){
		if(va[td[i].t]==0&&sz>0&&v<=k){
			long long tmp=prio_pop();
			v++;
			anss[v]=anss[v-1]-tmp+td[i].d;
			va[td[i].t]++;
//			anss[v]+=v*v;
		}
	}
	for(i=vv;i<=v;i++)ans=max(ans,anss[i]+i*i);
	printf("%lld\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:54:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&k);
  ^
./Main.c:55:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<n;i++)scanf("%d%lld",&td[i].t,&td[i].d);
                  ^