#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <sstream>
#include <string>
#include <cassert>
#include <iostream>
using namespace std;

#define MAX_N 100000
#define MAX_D 4
int D, N, K, roll[MAX_N][MAX_D];

#define x first
#define y second.first
#define z second.second
#define mp(a, b, c) make_pair(a, make_pair(b, c))
typedef pair<int, pair<int, int> > triple;

#define debug(x) cerr<<#x<<" = "<<(x)<<endl

bool sat(const int *r, const triple& t)
{
	for(int i=0; i<D; i++)
	{
		if(r[i]==-1)
			return false;
		if(t.x==r[i] || t.y==r[i] || t.z==r[i])
			return true;
	}
	return false;
}

int main()
{
	int _T;
	string line;
	getline(cin, line);
	istringstream(line)>>_T;
	for(int t=1; t<=_T; t++)
	{
		fprintf(stderr, "t=%d\n", t);
		scanf("%d%d%d", &N, &D, &K);
		for(int i=0; i<N; i++){
			for(int j=0; j<D; j++){
				scanf("%d", &roll[i][j]);
			}
			int back=D-1;
			TOP:
			for(int j=0; j<=back; j++)
			for(int k=j+1; k<=back; k++)
				if(roll[i][j]==roll[i][k]){
					roll[i][k]=roll[i][back];
					roll[i][back]=-1;
					back--;
					goto TOP;
				}
		}
		int bestlen=0;
		int beststart=0;
		int maxsize=0;
		for(int start=0; start<N; start++)
		{
			triple space[2][64];
			triple *cur=space[0], *next=space[1];
			int curlen=0, nextlen=0;
			for(int d=0; d<D; d++)
			{
				if(roll[start][d]==-1)
					continue;
				cur[curlen++]=mp(roll[start][d], -1, -1);
			}
			for(int stop=start; stop<N && curlen; stop++)
			{
				nextlen=0;
				for(triple *it=cur; it!=cur+curlen; it++){
					if(start>0 && sat(roll[start-1], *it))
						continue;
					bool good=sat(roll[stop], *it);
					#define npush(x) next[nextlen++]=x
					if(good)
						npush(*it);
					else
					{
						for(int d=0; d<D; d++)
						{
							if(roll[stop][d]==-1)
								continue;
							if(it->y==-1)
								npush(mp(it->x, roll[stop][d], -1));
							else if(K==3 && it->z==-1)
								npush(mp(it->x, it->y, roll[stop][d]));
						}
					}
				}
				swap(cur, next);
				swap(curlen, nextlen);
				assert(curlen<=64);
				assert(curlen<=16 || K==3);
				if(curlen){
					int len=stop-start+1;
					if(len>bestlen){
						bestlen=len;
						beststart=start;
					}
				}
			}
		}
		printf("Case #%d: %d %d\n", t, beststart, beststart+bestlen-1);
	}
}
