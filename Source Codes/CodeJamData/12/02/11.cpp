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

int T,n,s,p;

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	scanf("%d", &T);
	for (int casenum=0; casenum<T; casenum++)
	{
		scanf("%d%d%d", &n,&s,&p);
		int ans = 0, temp,q1=p-1,q2=p-2;
		while (q1<0) q1++;
		while (q2<0) q2++;
		for (int i=0; i<n; i++)
		{
			scanf("%d",&temp);
			if (temp >= p+q1+q1) ans++;
			else
			if ((temp >= p+q2+q2)&&(s>0)) {ans++; s--;}
		}
		printf("Case #%d: %d\n", casenum+1, ans);
	}
}
