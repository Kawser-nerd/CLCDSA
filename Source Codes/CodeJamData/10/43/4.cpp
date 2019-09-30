#include<cstdio>
#include<algorithm>
#define L 2000

using namespace std;

int T,n,I,i,ans,maxx,maxy,minxy;

class Block{
public:
	int x1,x2,y1,y2;
	void in(){scanf("%d%d%d%d",&x1,&y1,&x2,&y2);}
};

bool tou(int a,int b,int c,int d){
	return max(a,c)<=min(b,d)+1;
}

bool tou1(int a,int b,int c,int d){
	return max(a,c)<=min(b,d);
}

bool touch(int a,int b,int c,int d){
	return (a+1==c && b-1==d || a-1==c && b+1==d);
}

bool touch(Block &a,Block &b){
	return tou(a.x1,a.x2,b.x1,b.x2) && tou(a.y1,a.y2,b.y1,b.y2) &&
		(tou1(a.x1,a.x2,b.x1,b.x2) || tou1(a.y1,a.y2,b.y1,b.y2) ||
		touch(a.x2,a.y1,b.x1,b.y2) || touch(a.x1,a.y2,b.x2,b.y1));
}

bool bt[L];
Block block[L];

void dfs(int a){
	if (!bt[a]) return ;
	bt[a]=0;
	maxx=max(maxx,block[a].x2);
	maxy=max(maxy,block[a].y2);
	minxy=min(minxy,block[a].x1+block[a].y1);
	for (int i=0;i<n;++i)
	    if (touch(block[a],block[i])) dfs(i);
}

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		printf("Case #%d: ",++I);
		for (i=0;i<n;++i) block[i].in();
		for (i=0;i<n;++i) bt[i]=1;
		ans=0;
		for (i=0;i<n;++i)
		    if (bt[i]){
				maxx=0;maxy=0;
				minxy=100000000;
				dfs(i);
				ans=max(ans,maxx+maxy-minxy+1);
			}
		printf("%d\n",ans);
	}
}
