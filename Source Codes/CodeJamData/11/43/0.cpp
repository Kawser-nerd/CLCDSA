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
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define SIZE(X) ((int)(X.size()))
typedef long long int64;

#define ASSERT(X) {if (!(X)) {printf("\n assertion failed at line %d\n",__LINE__);exit(0);}}

const int maxsize=1<<20;
bool prime[maxsize];
vector<int64> a;

void init()
{
	a.clear();
	memset(prime,true,sizeof(prime));
	for (int i=2;i<maxsize;i++) if (prime[i])
	{
		int64 t=(int64)i*i;
		for (;t<=1000000LL*1000000LL;t*=i) a.push_back(t);
		for (int j=i+i;j<maxsize;j+=i) prime[j]=false;
	}
	sort(a.begin(),a.end());
}
int main()
{
//	freopen("C.in","r",stdin);
	freopen("C-small-attempt0.in","r",stdin);freopen("C-small-attempt0.out","w",stdout);
//	freopen("C-small-attempt1.in","r",stdin);freopen("C-small-attempt1.out","w",stdout);
//	freopen("C-small-attempt2.in","r",stdin);freopen("C-small-attempt2.out","w",stdout);
//	freopen("C-large.in","r",stdin);freopen("C-large.out","w",stdout);
	int testcase;
	cin>>testcase;
	init();
	for (int case_id=1;case_id<=testcase;case_id++)
	{
		printf("Case #%d: ",case_id);
		int64 n;
		cin>>n;
		if (n==1)
		{
			printf("0\n");
			continue;
		}
		int H=-1,T=SIZE(a);
		for (;H+1<T;)
		{
			int64 M=H+(T-H)/2;
			if (a[M]<=n) H=M;
			else T=M;
		}
		cout<<T+1<<endl;
		fflush(stdout);
	}
	return 0;
}
