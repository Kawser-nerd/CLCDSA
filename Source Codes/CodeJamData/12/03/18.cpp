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

int chk[11234567];

int main()
{
	int i,j,k,l,t,ten,len,ans,A,B;

	FIN
	FOUT

	scanf("%d",&t);
	f1(k,t)
	{
		fprintf(stderr,"%d\n",k);
		scanf("%d%d",&A,&B);
		ans=0;
		for(ten=len=1;ten*10<=A;ten*=10,++len);
		ff(i,A,B) chk[i]=0;
		ff(i,A,B)
		{
			l=i;
			f1(j,len)
			{
				if(l>i && l<=B && chk[l]!=i) ++ans,chk[l]=i;
				l=l/10+l%10*ten;
			}
			if(i==ten*10)
			{
				ten*=10;
				++len;
			}
		}
		printf("Case #%d: %d\n",k,ans);
	}

	return 0;
}
