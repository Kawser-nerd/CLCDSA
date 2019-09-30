#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <limits.h>
#define swap(type,a,b) do{type t=a;a=b;b=t;}while(0);
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define ll long long
#define INF 1000000000
#define MOD 1000000007
#define SIZE 100005
#define FOR(i,a,n) for(i=(a);i<(n);i++)
int lower_bound(int a[],int n,int k){
	int left=-1; int right=n;
	while(right-left>1){
		int mid=(left+right)/2;
		if(a[mid]<k) left=mid;
		else right=mid;
	}
	return right;
}
typedef struct{
	int x,y;
}Pos;
int comp1(const void *a,const void *b){ //??
	Pos p=*(Pos*)a,q=*(Pos*)b;
	return p.x-q.x;
}
int comp2(const void *a,const void *b){ //??
	Pos p=*(Pos*)a,q=*(Pos*)b;
	return q.x-p.x;
}
Pos pos[200000];
int ary[200000];
int dp[200000];
int main(void)
{
	int n,size=0,X,Y,id,num,i;
	int min_x,max_x,min_y,max_y,dx,dy;
	double d1=5*M_PI-20,d2=10*M_PI-20;
	Pos s,g;
	
	scanf("%d%d%d%d",&s.x,&s.y,&g.x,&g.y);
	min_x=MIN(s.x,g.x); max_x=MAX(s.x,g.x);
	min_y=MIN(s.y,g.y); max_y=MAX(s.y,g.y);
	dx=max_x-min_x; dy=max_y-min_y;
	if(s.y>g.y) swap(Pos,s,g);
	
	scanf("%d",&n);
	FOR(i,0,n){
		scanf("%d%d",&X,&Y);
		if(X<min_x||X>max_x||Y<min_y||Y>max_y) continue;
		pos[size].x=X; pos[size++].y=Y;
	}
	
	if(s.x<=g.x) qsort(pos,size,sizeof(Pos),comp1);
	else qsort(pos,size,sizeof(Pos),comp2);
	//FOR(i,0,size) printf("%d %d\n",pos[i].x,pos[i].y);
	
	FOR(i,0,size){
		ary[i]=pos[i].y;
		dp[i]=INF;
	}
	FOR(i,0,size){
		id=lower_bound(dp,size,ary[i]);
		dp[id]=ary[i];
	}
	
	num=lower_bound(dp,size,INF);
	if(num==MIN(dx,dy)+1){
		printf("%.20lf\n",(double)(dx+dy)*100+d1*(num-1)+d2);
	}else{
		printf("%.20lf\n",(double)(dx+dy)*100+d1*num);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:45:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d%d",&s.x,&s.y,&g.x,&g.y);
  ^
./Main.c:51:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:53:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&X,&Y);
   ^