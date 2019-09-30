#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define two(X) (1<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define SIZE(A) ((int)A.size())
#define MP(A,B) make_pair(A,B)
typedef pair<int,int> ipair;

const int maxn=60+5;

int size_x,size_y;
char a[maxn][maxn];
bool r[maxn][maxn];

int main()
{
//	freopen("D.in","r",stdin);
//	freopen("D-small-attempt0.in","r",stdin);freopen("D-small-attempt0.out","w",stdout);
	freopen("D-small-attempt1.in","r",stdin);freopen("D-small-attempt1.out","w",stdout);
//	freopen("D-small-attempt2.in","r",stdin);freopen("D-small-attempt2.out","w",stdout);
//	freopen("D-large.in","r",stdin);freopen("D-large.out","w",stdout);
	int testcase;
	scanf("%d",&testcase);
	for (int case_id=1;case_id<=testcase;case_id++)
	{
		printf("Case #%d:\n",case_id);
		scanf("%d%d",&size_x,&size_y);
		for (int i=0;i<size_x;i++) scanf("%s",a[i]);
		for (char c='0';c<='9';c++)
		{
			int x0=-1,y0=-1;
			for (int x=0;x<size_x;x++) for (int y=0;y<size_y;y++) if (a[x][y]==c) x0=x,y0=y;
			if (x0<0) continue;
			memset(r,false,sizeof(r));
			r[x0][y0]=true;
			for (int x=x0;x>=0;x--) 
			{
				for (int y=0;y<size_y;y++) if (r[x][y] && a[x][y+1]!='#') r[x][y+1]=true;
				for (int y=size_y-1;y>=0;y--) if (r[x][y] && a[x][y-1]!='#') r[x][y-1]=true;
				for (int y=0;y<size_y;y++) if (r[x][y] && a[x-1][y]!='#') r[x-1][y]=true;
			}
			int cnt=0;
			set<int> target;
			for (int x=0;x<size_x;x++) for (int y=0;y<size_y;y++) if (r[x][y]) cnt++;
			bool is_lucky=false;
			//for (int is_to_left=0;is_to_left<2;is_to_left++)
			for (int mask=0;!is_lucky && mask<two(15);mask++)
			{
				bool ok=true;
				set<ipair> S;
				for (int x=0;x<size_x;x++) for (int y=0;y<size_y;y++) if (r[x][y]) S.insert(MP(x,y));
				for (int step=0;SIZE(S)>1 && step<15;step++)
				{
					while (1)
					{
						set<ipair> newS;
						for (set<ipair>::iterator it=S.begin();it!=S.end();++it)
						{
							int x=it->first;
							int y=it->second;
							if ( contain(mask,step) && a[x][y-1]!='#') y--;
							if (!contain(mask,step) && a[x][y+1]!='#') y++;
							newS.insert(MP(x,y));
						}
						if (newS==S) break;
						S=newS;
					}
					if (SIZE(S)<=1) break;
					bool more=false;
					for (int dir=0;!more && dir<2;dir++) 
					{
						set<ipair> S2=S;
						for (int p=0;!more && p<size_y;p++)
						{
							bool can_down=true,found_some=false;
							for (set<ipair>::iterator it=S2.begin();it!=S2.end();++it)
							{
								int x=it->first;
								int y=it->second;
								if (a[x+1][y]!='#' && !r[x+1][y]) can_down=false;
								if (a[x+1][y]!='#') found_some=true;
							}
							if (can_down && found_some) 
							{
								more=true; 
								S.clear();
								for (set<ipair>::iterator it=S2.begin();it!=S2.end();++it)
								{
									int x=it->first;
									int y=it->second;
									if (a[x+1][y]!='#') x++;
									S.insert(MP(x,y));
								}
								break; 
							}
							set<ipair> newS2;
							for (set<ipair>::iterator it=S2.begin();it!=S2.end();++it)
							{
								int x=it->first;
								int y=it->second;
								if (dir==0 && a[x][y-1]!='#') y--;
								if (dir==1 && a[x][y+1]!='#') y++;
								newS2.insert(MP(x,y));								
							}
							if (newS2==S2) break;
							S2=newS2;
						}
					}
					if (!more) break;
				}
				if (SIZE(S)==1) { is_lucky=true; break; }
			}
			printf("%c: %d ",c,cnt);
			if (is_lucky)
				printf("Lucky\n");
			else
				printf("Unlucky\n");
			fflush(stdout);
		}
	}
	return 0;
}