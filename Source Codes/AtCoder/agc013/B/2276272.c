#include<stdio.h>
#include<stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)

typedef struct edge{ll s,g;}E;
E e[200010];
int vnow[100010];
int epre[200010];

int check[100010];
int path1[100010],path2[100010];

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	rep(i,0,n)vnow[i]=-1;
	
	rep(i,0,m){
		int a,b;
		scanf("%d%d",&a,&b);
		a--;b--;
		e[2*i].s=a;
		e[2*i].g=b;
		epre[2*i]=vnow[a];
		vnow[a]=2*i;
		
		e[2*i+1].s=b;
		e[2*i+1].g=a;
		epre[2*i+1]=vnow[b];
		vnow[b]=2*i+1;
	}
	
	int p1cnt=1;
	path1[0]=0;
	check[0]=1;
	int flag=1;
	while(flag){
		flag=0;
		for(int t=vnow[path1[p1cnt-1]];t!=-1;t=epre[t])if(!check[e[t].g]){
			flag=1;
			path1[p1cnt++]=e[t].g;
			check[e[t].g]=1;
			break;
		}
	}

	int p2cnt=1;
	path2[0]=0;
	flag=1;
	while(flag){
		flag=0;
		for(int t=vnow[path2[p2cnt-1]];t!=-1;t=epre[t])if(!check[e[t].g]){
			flag=1;
			path2[p2cnt++]=e[t].g;
			check[e[t].g]=1;
			break;
		}
	}
	
	printf("%d\n",p1cnt+p2cnt-1);
	for(int i=p2cnt-1;i>=0;i--)printf("%d ",path2[i]+1);
	rep(i,1,p1cnt)printf("%d ",path1[i]+1);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&m);
  ^
./Main.c:21:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&a,&b);
   ^