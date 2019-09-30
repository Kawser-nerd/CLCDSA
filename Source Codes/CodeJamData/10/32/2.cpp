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
#include <ctime>

using namespace std;

int main()
{
	//freopen("B-small-attempt0.in","r",stdin);freopen("B-small-output.txt","w",stdout);
	//freopen("B-small-attempt1.in","r",stdin);freopen("B-small-output.txt","w",stdout);
	freopen("B-large.in","r",stdin);freopen("B-large-output.txt","w",stdout);

	int T;
	scanf("%d",&T);
	for(int Case=1;Case<=T;Case++)
	{
		int L,R,C;
		scanf("%d %d %d",&L,&R,&C);
		int times =0;
		while((__int64)L*C<R)
		{
			L*=C;
			times++;
		}
		int ret = 0;
		while(times)
		{
			ret++;
			times/=2;
		}
		printf("Case #%d: %d\n",Case,ret);
	}
}
