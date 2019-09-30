#include <stdio.h>
#include <string.h>

#define MAX 10000
int good[MAX][6][6];
int gn;
int cur[6][6];
int r,c;

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

void btr(int x,int y) {
	int i,j,k,rot,d,x2,y2,eq,fr;
	/* inefficient pruning */
//	printf("at %d %d\n",x,y);
//	for(j=0;j<r;j++) {for(i=0;i<c;i++) printf(" %d",cur[i][j]);printf("\n");}
	for(i=0;i<c;i++) for(j=0;j<r;j++) if(cur[i][j]>0) {
		for(fr=eq=d=0;d<4;d++) {
			x2=(c+i+dx[d])%c; y2=j+dy[d];
			if(x2>=0 && y2>=0 && x2<c && y2<r) {
				if(cur[i][j]==cur[x2][y2]) eq++;
				if(cur[x2][y2]<0) fr++;
			}
		}
		if(eq>cur[i][j]) return;
		if(eq+fr<cur[i][j]) return;
	}
	if(x==c) {
		x=0; y++;
		if(y==r) {
			for(k=0;k<gn;k++) {
				for(rot=0;rot<c;rot++) {
					for(i=0;i<c;i++) for(j=0;j<r;j++) if(cur[i][j]!=good[k][(i+rot)%c][j]) goto diff;
					return;
				diff:;
				}
			}
			for(i=0;i<c;i++) for(j=0;j<r;j++) good[gn][i][j]=cur[i][j];
			gn++;
			return;
		}
	}
	for(i=1;i<4;i++) {
		cur[x][y]=i;
		btr(x+1,y);
		cur[x][y]=-1;
	}
}

void solve() {
	scanf("%d %d",&r,&c);
	gn=0;
	memset(cur,-1,sizeof(cur));
	btr(0,0);
	printf("%d\n",gn);
}

int main() {
	int T,caseno=1;
	scanf("%d",&T);
	while(T--) printf("Case #%d: ",caseno++),solve();
	return 0;
}
