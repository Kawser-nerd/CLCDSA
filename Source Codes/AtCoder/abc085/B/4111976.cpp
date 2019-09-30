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

set<int> st;
int main()
{
	int n;cin >> n;
	while(n--){
		int x;
		cin >> x;
		st.insert(x);
	}
	cout << st.size() << endl;
	return 0;
}