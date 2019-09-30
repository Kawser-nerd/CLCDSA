#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>

using namespace std;

const int pp[9] = {1,10,100,1000,10000,100000,1000000,10000000,100000000};
int T;
map <int ,int> hash;

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	scanf("%d",&T);
	for (int casenum=1; casenum<=T; casenum++)
	{
		int a,b,ans=0,len = 0,c1 = 0;
		scanf("%d%d",&a,&b);
		for (int i=a; i!=0; i=i/10) len++;
		for (int i=a; i<=b; i++)
		{
			hash.clear();
			for (int j=1; j<len; j++)
			{
				int c = i / pp[j] + (i % pp[j])*pp[len-j];
				if (i < c && c>=a && c<=b && hash[c]==0) 
				{
					ans++;
					hash[c] = 1;
				}
			}
		}
		printf("Case #%d: %d\n", casenum, ans);
	}
}
