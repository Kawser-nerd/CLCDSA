#include<cstdio>
#include<cstring>
#include<algorithm>
#define L 52
using namespace std;

class P{
public:
	int x,y,l,r;
	P(){}
	P(int x,int y,int left,int right):x(x),y(y),l(left),r(right){}
};

int opt[L][L][L][L];
bool bt[L][L][L][L];
char map[L][L];
int n,m,f,ans;
int T,i,l,r;
const int maxn=L*L*L*L;
P Q[maxn];

bool ok(int x,int y,int p,int left=-1,int right=-1){
	if (y<0 || y>=m) return false;
	if (map[x][y]=='.' || y>=left && y<=right) return p==0;
	return p==1;
}

void update(int x,int y,int left,int right,int cost){
	if (ans!=-1 && cost>=ans) return ;
	if (y<0 || y>=m) return;
	int tot=1;
	while (x<n-1 && ok(x+1,y,0)){
		if (++tot>f) return;
		++x;left=right=y;
	}
	if (x==n-1) {
		if (ans==-1 || ans>cost) ans=cost;
		return;
	}
	int &ret=opt[x][y][left][right];
	if (ret==-1 || ret>cost){
		ret=cost;
		if (!bt[x][y][left][right]){
			bt[x][y][left][right]=1;
			Q[r++%maxn]=P(x,y,left,right);
		}
	}
}

int x,y,left,right,cost,I;

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d%d",&n,&m,&f);
		for (i=0;i<n;++i)
			scanf("%s",map[i]);
		memset(opt,-1,sizeof opt);
		l=r=0;
		ans=-1;
		update(0,0,0,0,0);
		while (l<r){
			x=Q[l%maxn].x;
			y=Q[l%maxn].y;
			left=Q[l%maxn].l;
			right=Q[l%maxn].r;
			cost=opt[x][y][left][right];
			bt[x][y][left][right]=0;
			l++;
			if (ok(x,y-1,0,left,right))
				if (ok(x+1,y-1,1)){
					update(x,y-1,left,right,cost);
					for (i=0;ok(x,y+i,0,left,right) && ok(x+1,y+i,1);++i)
						update(x+1,y+i-1,y-1,y+i-1,cost+i+1);
				}
				else update(x+1,y-1,y-1,y-1,cost);
			if (ok(x,y+1,0,left,right))
				if (ok(x+1,y+1,1)){
					update(x,y+1,left,right,cost);
					for (i=0;ok(x,y-i,0,left,right) && ok(x+1,y-i,1);++i)
						update(x+1,y-i+1,y-i+1,y+1,cost+i+1);
				}
				else update(x+1,y+1,y+1,y+1,cost);
		}
		if (ans==-1) {
			printf("Case #%d: No\n",++I);
			fprintf(stderr,"Case #%d: No %d\n",I,r);
		}
		else {
			printf("Case #%d: Yes %d\n",++I,ans);
			fprintf(stderr,"Case #%d: Yes %d %d\n",I,ans,r);
		}
	}
}
