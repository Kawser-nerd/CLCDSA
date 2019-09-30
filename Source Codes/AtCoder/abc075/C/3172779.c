#include<stdio.h>
int N,M;
int a[50];
int l[50];
int r[50];
int ans=0;

void init();
int root(int x);
void unite(int x,int y);
int query(int x,int y);
int judge();

int main(){
	scanf("%d%d",&N,&M);
	
	int i;
	for(i=0;i<M;i++){
		scanf("%d%d",&l[i],&r[i]);
		l[i]--;
		r[i]--;
	}
	
	for(i=0;i<M;i++){
		init();
		
		int j;
		for(j=0;j<M;j++){
			if(j==i)continue;
			unite(l[j],r[j]);
		}
		
		if(judge()==0)ans++;
	}
	
	printf("%d\n",ans);
	return 0;
}

void init(){
	for(int i=0;i<N;i++)a[i]=i;
}

int root(int x){
	if(a[x]==x)return x;
	else return a[x]=root(a[x]);
}

void unite(int x,int y){
	x=root(x);
	y=root(y);
	if(x==y)return;
	a[x]=y;
}

int query(int x,int y){
	if(root(x)==root(y))return 1;
	return 0;
}

int judge(){
	for(int i=0;i<N;i++){
		for(int j=i+1;j<N;j++){
			if(query(i,j)==0)return 0;
		}
	}
	return 1;
} ./Main.c: In function ‘main’:
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&N,&M);
  ^
./Main.c:19:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&l[i],&r[i]);
   ^