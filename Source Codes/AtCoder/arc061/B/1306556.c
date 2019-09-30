#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define swap(type,a,b) do{type t=a;a=b;b=t;}while(0);
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define ll long long
#define INF 100000000
#define FOR(i,a,n) for(i=a;i<n;i++)
typedef struct{
	int x,y;
}Pos;
int comp(const void* a,const void* b){
	Pos p=*(Pos*)a,q=*(Pos*)b;
	if(p.x!=q.x) return p.x-q.x;
	else return p.y-q.y;
	
}
void fill(int a[],int b,int c){
	int i;
	FOR(i,0,b) a[i]=c;
	return;
}
Pos pos[900000];
int cnt[10];
int s=0;
int main(void)
{
	int h,w,n,a,b,sum=0,i,j,k;
	Pos p;
	scanf("%d%d%d",&h,&w,&n);
	FOR(i,0,n){
		scanf("%d%d",&a,&b);
		FOR(j,0,3){
			FOR(k,0,3){
				int nx=b-j,ny=a-k;
				if(nx>=1&&ny>=1&&nx<=w-2&&ny<=h-2){
					pos[s].x=nx;
					pos[s++].y=ny;
				}
			}
		}
	}
	qsort(pos,s,sizeof(Pos),comp);
	/*FOR(i,0,s){
		printf("%d %d\n",pos[i].x,pos[i].y);
	}*/
	for(i=0;i<s;){
		j=0,p=pos[i];
		while(i<s&&p.x==pos[i].x&&p.y==pos[i].y) i++,j++;
		cnt[j]++;
		sum++;
	}
	printf("%lld\n",(ll)(w-2)*(h-2)-sum);
	FOR(i,1,10) printf("%d\n",cnt[i]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:32:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&h,&w,&n);
  ^
./Main.c:34:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&a,&b);
   ^