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

set<int> st[30],ss[30];
int Mix(char x){
	return x - 'a';
}
int main()
{
	string s,t;
	cin >> s >> t;
	int len = s.length();
	for(int i = 0 ; i < len ;i++){
		ss[Mix(s[i])].insert(Mix(t[i]));
		st[Mix(t[i])].insert(Mix(s[i]));
	}
	bool flag = false;
	for(int i = 0 ; i < 26 ; i++){
		if(st[i].size() > 1 || ss[i].size() > 1)flag = true;
	}
	if(!flag)cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}