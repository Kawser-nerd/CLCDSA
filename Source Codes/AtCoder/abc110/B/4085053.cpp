#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <queue>
#include <map>
#include <vector>
#include <set>
#include <cstdlib>
#include <stack>
#include <climits>
#include <ctime>
#include <iomanip>
 
using namespace std;
 
typedef long long LL;
typedef double db;
#define lowbit(x) (x)&(-x)
#define gcd(a,b) __gcd(a,b)
#define sqre(x) (x)*(x)
#define mem(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
const int MaxN = 1e6 + 1005;
const int inf = 1e8;
const double PI = acos(-1.0);
const LL mod = 100000007;

priority_queue<int,vector<int> ,greater<int> > que;
vector<int> t[MaxN];

int main()
{
	int n,m,x,y;cin >> n >> m >> x >> y;
	int Min = y;
	int Max = x;
	for(int i = 1 ;i <= n;i++){
		int x ; cin >> x;
		Max = max(Max,x);
	}
	for(int i = 1; i <= m ;i++){
		int x ; cin >> x;
		Min = min(Min,x);
	}
	if(Min <= Max)cout << "War" << endl;
	else cout << "No War" << endl;
	return 0;
}