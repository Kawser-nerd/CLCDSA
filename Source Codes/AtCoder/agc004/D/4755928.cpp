#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <set>
#include <numeric>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <cfloat>
#include <ctime>
#include <complex>
#include <cassert>
#include <array>
#include <bitset> 
#include <unordered_map>

using namespace std;
typedef long long LL;
typedef pair<int,int> P;

int N,K;
const int L=1e5+10;
vector<int> p[L];
int ret=0;

int f(int r,int a)
{
	int d=0;
	for(auto s:p[r])
	{
		d=max(d,1+f(s,r));
	}
	if(a&&d==K-1)
	{
		//cerr << r << ", " << a << endl;
		ret++;
		return -1;
	}
	return d;
}
int main() {
	cin >> N >> K;
	int a0;
	cin >> a0;
	if(a0!=1){
		ret++;
	}

	for(int i=1;i<N;i++){
		int a;
		cin >> a;
		a--;
		p[a].push_back(i);
	}
	f(0,0);
	cout << ret << endl;


	return 0;
}