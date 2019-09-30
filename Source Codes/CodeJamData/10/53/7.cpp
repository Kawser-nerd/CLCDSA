#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;

map<int,int> hash;
map<int,int>::iterator it;

const int maxn = 200000 + 10;
int sl[maxn],sr[maxn],top;

inline void tkmerge()
{
	if(top==0) return;

	int tmp = top;top = max(1,top-5);
	for(int i=top+1;i<=tmp;i++) if( sr[top]==sl[i]-1 )
	sr[top] = sr[i];else
	{
		top++;sl[top] = sl[i];sr[top] = sr[i];
	}
}
inline long long sum( long long a,long long b )
{
	return (b+a)*(b-a+1) /2;
}
int main()
{
	int TT;
	scanf("%d",&TT);
	int T = 0;

	int x,y,C;
	long long ans;
	while(TT--)
	{
		printf("Case #%d: ",++T);
		scanf("%d",&C);
		hash.clear();
		while(C--)
		{
			scanf("%d%d",&x,&y);
			hash[x]+=y;
		}

		ans = 0;
		int cur = -1000001;
		int tot;
		top = 0;
		for(;;)
		{
			it = hash.lower_bound(cur);if(it==hash.end()) break;
			cur = it->first;
			tot = it->second;
			tkmerge();

			if(tot==0) cur++;else
			if(tot==1)
			{
				top++;sl[top] = cur;sr[top] = cur;
				cur++;
			}else
			{
				if( top==0 || sr[top]<cur-1 )
				{
					top++;sl[top] = cur-1;sr[top] = cur-1;
					hash[cur+1]++;
					hash[cur]-=2;
					ans++;
				}else
				{
					int L = sr[top]-sl[top]+1;
					if( tot<=L+1 )
					{
						//modify sl,sr
						hash[cur+1]+=tot-1;
						sl[top+1] = sl[top] + tot-1;
						sr[top+1] = cur;
						sl[top]--;
						sr[top] = sl[top+1]-2;
						top++;

						cur++;
						//modify ans
						ans+=sum(L-tot+3,L+1);
					}else
					{
						hash[cur]-=(L+2);
						sl[top]--;
						hash[cur+1]+=(L+1);
						ans+=sum(1,L+1);
					}
				}
			}
		}



		printf("%I64d\n",ans);
	}
	return 0;
}
