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

const char	*welcome = {"welcome to code jam"}; 

char	text[1000];
int	length;
int	ways[20][1000];

int main()
{
	int	T,cs;
	int	i,j;

	scanf("%d",&T);
	while(getchar() != '\n');

	rab(cs,1,T)
	{
		gets(text);
		length = strlen(text);

		rab(i,0,length) ways[strlen(welcome)][i] = 1;

		for(i = strlen(welcome) - 1; i >= 0; i--)
		{
			ways[i][length] = 0;

			for(j = length - 1; j >= 0; j--)
			{
				ways[i][j] = ways[i][j+1];
				if(welcome[i] == text[j]) ways[i][j] += ways[i+1][j+1];
				ways[i][j] %= 10000;
			}
		}

		printf("Case #%d: %04d\n",cs,ways[0][0]);
	}
	return 0;
}
