#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

static int par[200010];//?
static int rank[200010];

//n??????
void init(int n){
	int i;
	for(i=0;i<n;i++){
		par[i]=i;
		rank[i]=0;
	}
}

//???????
int find(int x){
	if(par[x]==x){
		return x;
	}else{
		par[x]=find(par[x]);
		return par[x];
	}
}

//x?y?????????
void unite(int x, int y){
	x=find(x);
	y=find(y);
	if(x==y) return;
	if(rank[x]<rank[y]){
		par[x]=y;
	}else{
		par[y]=x;
		if(rank[x]==rank[y])rank[x]++;
	}
}


int main(void)
{
	//?????
	int n,m;
	static int p[100010];
	static int x[100010];
	static int y[100010];
	
	
	//??????
	int i,j,k,l;
	int flag=0;
	int ans=0;
	int count=0;
	int temp,temp1,temp2;
	//????????
	scanf("%d %d",&n,&m);
	
	for(i=0;i<n;i++){
		scanf("%d",&p[i]);
	}
	
	for(i=0;i<m;i++){
		scanf("%d %d",&x[i],&y[i]);
	}
	
//	printf("n?%d??\n", n);
//	printf("??????????\n");
	//?????
	
	init(200000);
	for(i=0;i<n;i++){
		unite(p[i],i+100001);
	}
	for(i=0;i<m;i++){
		unite(p[x[i]-1],p[y[i]-1]);
//		printf("m=%d i=%d %d?%d???\n",m,i,p[x[i]-1],p[y[i]-1]);
//		for(j=1;j<=n;j++){
//			printf("%d->%d\n",j,find(j));
//			printf("%d->%d\n",j+100000,find(j+100000));
//		}
	}
	
	for(i=1;i<=n;i++){
		if(find(i)==find(i+100000)) ans++;
	}
	
//	for(i=1;i<=n;i++){
//		printf("%d->%d\n",i,find(i));
//		printf("%d->%d\n",i+100000,find(i+100000));
//	}
	
//	printf("??????\n");
	//??
	
	printf("%d",ans);
	
//	printf("???????\n");
	
	return 0;
	
} ./Main.c: In function ‘main’:
./Main.c:59:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&n,&m);
  ^
./Main.c:62:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&p[i]);
   ^
./Main.c:66:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&x[i],&y[i]);
   ^