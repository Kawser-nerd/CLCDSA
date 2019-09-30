#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define maxn 105

char t[maxn][maxn],s[maxn][maxn],n,k;
const int dx[]={0,1,1,1,0,-1,-1,-1};
const int dy[]={1,1,0,-1,-1,0,1,-1};

int main()
{
	freopen("A_large.in","r",stdin);
	freopen("A_large.out","w",stdout);
	
	int T,test=1;
	for (scanf("%d",&T);test<=T;++test)
	{
		scanf("%d%d",&n,&k);
		for (int i=0;i<n;++i)
			scanf("%s",s[i]);
		for (int i=0;i<n;++i)
			for (int j=0;j<n;++j)
				t[j][n-1-i]=s[i][j];
//		for (int i=0;i<n;++i)
//			puts(t[i]);
		for (int i=n-1;i>=0;--i)
			for (int j=0;j<n;++j)
			{
				int x=i,y=j;
				while (x<n && t[x+1][y]=='.')
				{
					swap(t[x+1][y],t[x][y]);
					++x;
				}
			}
		bool R=false,B=false;
		for (int i=0;i<n;++i)
			for (int j=0;j<n;++j)
			if (t[i][j]!='.')
				for (int dir=0;dir<8;++dir)
				{
					int x=i,y=j,cnt=0;
					while (x>=0 && y>=0 && x<n && y<n && t[x][y]==t[i][j])
					{
						++cnt;
						x+=dx[dir];
						y+=dy[dir];
					}
					if (cnt>=k)
					{
						if (t[i][j]=='R') R=true;
						else B=true;
					}
				}
		printf("Case #%d: ",test);
		if (!R && !B) puts("Neither");
		if (R && B) puts("Both");
		if (R && !B) puts("Red");
		if (!R && B) puts("Blue");
	}
	return 0;
}
