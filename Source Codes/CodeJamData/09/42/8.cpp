#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>

using namespace std;

const int INF = 100000000;

int memo[55][55][1<<8][1<<8];
char look[55][55][1<<8][1<<8];
int R,C;
int F;
vector<string> vs;
int initmask[55];

int dp(int r,int c,int currmask,int lowmask)
{
	if(r+1>=R){return 0;}
	if((lowmask & (1<<c))==0)
	{
		//check falling
		int Q = 1,qr=r+1;
		while(qr+1<R && vs[qr+1][c]=='.'){++Q;++qr;}
		if(Q>F){return INF;}
		if(Q==1)
		{
			currmask = lowmask;
		}
		else
		{currmask = initmask[qr];}
		r = qr;
		lowmask = initmask[r+1];
	}
	if(r+1>=R){return 0;}
	int &ret = memo[r][c][currmask][lowmask];
	if(ret != -1){return ret;}
	char &qq = look[r][c][currmask][lowmask];
	if(qq){return INF;}
	/*cerr << r << " " << c << " ";
	for(int i=0;i<C;++i)
	{
		cerr << ((currmask & (1<<i))?(1):(0));
	}
	cerr << " ";
	for(int i=0;i<C;++i)
	{
		cerr << ((lowmask & (1<<i))?(1):(0));
	}
	cerr << "\n";*/
	qq = 1;
	ret = INF;
	//left/right
	if(c && ((currmask & (1<<(c-1)))==0)){
		ret <?= dp(r,c-1,currmask,lowmask);
		if(((lowmask & (1<<(c-1)))!=0))
		{
			ret <?= 1+dp(r,c,currmask,lowmask & (~(1<<(c-1))));
		}
	}
	if(c+1 != C && ((currmask & (1<<(c+1)))==0)){
		ret <?= dp(r,c+1,currmask,lowmask);
		if((lowmask & (1<<(c+1)))!=0)
		{
			ret <?= 1+dp(r,c,currmask,lowmask & (~(1<<(c+1))));
		}
	}
	qq = 0;
	return ret;
}

int main(int argc,char **argv)
{
	int CASES;
	cin >> CASES;
	for(int cn=1;cn<=CASES;++cn)
	{
		cin >> R >> C >> F;
		vs.clear();
		string s;
		memset(memo,-1,sizeof(memo));
		memset(look,0,sizeof(look));
		for(int i=0;i<R;++i)
		{
			cin >> s;
			vs.push_back(s);
		}
		memset(initmask,0,sizeof(initmask));
		for(int i=0;i<R;++i)
		{
			for(int j=0;j<C;++j)
			{
				if(vs[i][j] =='#')
				{
					initmask[i] |= (1<<j);
				}
			}
		}
		int ret = dp(0,0,initmask[0],initmask[1]);
		if(ret < INF/2)
		{
			printf("Case #%d: Yes %d\n",cn,ret);
		}
		else
		{
			printf("Case #%d: No\n",cn);//dp(0,0,initmask[0],initmask[1]));
		}
	}
	return 0;
};
