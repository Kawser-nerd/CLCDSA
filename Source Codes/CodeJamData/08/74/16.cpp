#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <cctype>
using namespace std;

struct CMP_STRING {
	bool operator()(const char* a, const char* b) const {
		return strcmp(a,b)<0;
	}
};

#define two(n) (1<<(n))
#define foreach(a,it) for(typeof(a.begin()) it=a.begin();it!=a.end();++it)

int TT,N,M;

char grid[16][16];

int PD[two(16)][16];

#define fogo(n) (grid[(n)/M][(n)%M]=='#')


int dx[]={0,1,1,1,0,-1,-1,-1};
int dy[]={-1,-1,0,1,1,1,0,-1};
int voodoo(int bit ,int pos) {
	int &ans=PD[bit][pos];
	if(ans!=-1)
		return ans;
	ans=0;
	for(int i=0;i<8;i++) {
		int py=pos/M;
		int px=pos%M;
		int x=px+dx[i];
		int y=py+dy[i];
		if(x>=0 and x<M and y>=0 and y<N and grid[y][x]!='#' and grid[y][x]!='K') {
			grid[y][x]='K';
			ans=max(ans,(int)(voodoo(bit|(two(y*M+x)),y*M+x)==0));
			grid[y][x]='.';
		}
	}
	return ans;
}

int main(void) {
	scanf("%d",&TT);
	for(int T=1;T<=TT;T++) {
		memset(PD,-1,sizeof(PD));
		printf("Case #%d: ",T);
		scanf("%d %d",&N,&M);
		for(int i=0;i<N;i++)
			scanf("%s",grid[i]);
		
		int bit=0,pos;
		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++)
				if(grid[i][j]=='K') {
					pos=i*M+j;
					bit=two(pos);
				}
		if(voodoo(bit,pos)==1)
			printf("A\n");
		else
			printf("B\n");
	}
	return 0;
}
