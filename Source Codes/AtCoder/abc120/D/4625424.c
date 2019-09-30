#include <stdio.h>
#define NUM 100000
int pare[NUM];
int rank[NUM];
int size[NUM];


void init(int n){
	for(int i=0;i<n;i++){
		pare[i]=i;
		rank[i]=0;
		size[i]=1;
	}
}

int find(int x){
	if(pare[x]==x)return x;
	return pare[x] = find(pare[x]);
}

void unite(int x,int y){
	x = find(x);
	y = find(y);
	int cx = size[x];
	int cy = size[y];
	if(x==y)return;
	size[x] = size[y] = cx+cy;
	if(rank[x] < rank[y]){
		pare[x]=y;
	}else{
		pare[y] = x;
		if(rank[x] == rank[y])rank[x]++;
	}
}

int same(int x,int y){
	return find(x)==find(y)?1:0;
}

int count(int x){
	return size[find(x)];
}


int main(void){
	int n,m,i;
	scanf("%d%d",&n,&m);
	int a[m],b[m];
	long long ans[NUM]={0};
	for(i=0;i<m;i++){
		scanf("%d%d",&a[i],&b[i]);
		a[i]--,b[i]--;
	}
	ans[m-1] = (long long)n*(n-1)/2;
	init(n);


	for(i=m-2;i>=0;i--){
		if(same(a[i+1],b[i+1])){
			ans[i] = ans[i+1];
		}else{
			ans[i] = ans[i+1] - (long long)count(a[i+1])*count(b[i+1]);
			unite(a[i+1],b[i+1]);
		}
	}
	for(i=0;i<m;i++)printf("%lld\n",ans[i]);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:47:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&m);
  ^
./Main.c:51:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&a[i],&b[i]);
   ^