#include <iostream>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <map>
#include <functional>
#include <queue>
#include <bitset>
#include <sstream>
#include <vector>
using namespace std;

#define	sz(v)	(int)v.size()
#define	rep(i,n)	for((i)=0;(i) < (n); (i)++)
#define	rab(i,a,b)	for((i)=(a);(i) <= (b); (i)++)
#define	Fi(N)		rep(i,N)
#define	Fj(N)		rep(j,N)
#define	Fk(N)		rep(k,N)

vector <string>	v;

bool	possible[15][26];

int main()
{
	int	L,D,N;
	char	s[1000];
	int	i,j;
	int	cs;
	bool	b;

	while(scanf("%d %d %d",&L, &D, &N) == 3)
	{
		v.clear();

		while(D--)
		{
			scanf("%s",s);
			v.push_back(s);
		}

		rab(cs,1,N)
		{
			scanf("%s",s);

			memset(possible,0,sizeof(possible));

			j = 0;
			b = false;

			for(i = 0; s[i]; i++)
			{
				if(s[i] == '(')
					b = true;
				else if(s[i] == ')')
				{
					b = false;
					j++;
				}
				else
				{
					possible[j][s[i] - 'a'] = true;
					if(!b) j++;
				}
			}

			int c = 0;
	
			Fi(sz(v))
			{
				Fj(L)
				{
					if(!possible[j][v[i][j] - 'a'])
						break;
				}

				if(j >= L) c++;
			}

			printf("Case #%d: %d\n",cs,c);
		}
	}
	return 0;
}
