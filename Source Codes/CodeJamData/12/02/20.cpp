#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <assert.h>

#pragma warning(disable:4996)

#define TIME fprintf(stderr,"\n-----------\ntime : %.2f sec\n",double(clock())/CLOCKS_PER_SEC);
#define EXIT exit(0);
#define FIN freopen("input.txt","r",stdin);
#define FOUT freopen("output.txt","w",stdout);

#define M 0
#define MOD 0
#define ADD(_X,_Y) _X=(_X+_Y)%MOD;

#define abs(_Z) (((_Z)<0)?-(_Z):(_Z))
#define f0(_X,_Y) for(_X=0;_X<_Y;++_X)
#define f1(_X,_Y) for(_X=1;_X<=_Y;++_X)
#define ff(_X,_Y,_Z) for(_X=_Y;_X<=_Z;++_X)
#define fF(_X,_Y,_Z) for(_X=_Y;_X<_Z;++_X)
#define pb push_back
#define sz(_X) _X.size()
typedef long long ll;

int main()
{
	int i,k,t,surp,least,sum,ans,n;

	FIN
	FOUT

	scanf("%d",&t);
	f1(k,t)
	{
		ans=0;
		scanf("%d%d%d",&n,&surp,&least);
		f1(i,n)
		{
			scanf("%d",&sum);
			if(sum%3==0)
			{
				if(sum/3>=least) ++ans;
				else if(sum && sum/3+1>=least && surp) ++ans,--surp;
			}
			else if(sum%3==2)
			{
				if((sum+1)/3>=least) ++ans;
				else if((sum+1)/3+1>=least && surp) ++ans,--surp;
			}
			else if((sum+2)/3>=least) ++ans;
		}

		printf("Case #%d: %d\n",k,ans);
	}

	return 0;
}
