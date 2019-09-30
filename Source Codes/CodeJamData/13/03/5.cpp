#include<cstdio>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<sstream>
#include<cmath>
#include<cctype>
#include<cassert>
#include<cstring>
#include<cstdlib>

using namespace std;

// ------------- PRE-WRITTEN CODES ---------------------------------

// defines and const
#define DEBUG(x) cout<<">> "<<#x<<':'<<(x)<<endl
const int inf = 1000000000;

// input reading
template<class T>
vector<T> takeInput(int n) {
	vector<T> list;
	T a; int i;
	for(i = 0; i < n; i++) { cin >> a; list.push_back(a); }
	return list;
}

// math
long long ncr[305][305] = {0};
void gen_ncr(int n) {
	int i, j;
	for(i = 0; i <= n; i++) ncr[i][0] = 1;
	for(i=1; i<=n; i++) for(j=1;j<=n;j++)  ncr[i][j] = ncr[i-1][j] + ncr[i-1][j-1];
}

double dis(double x1, double y1, double x2, double y2) {
	return sqrt( (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

// --------------- END of PRE-WRITTEN CODES --------------------------

vector<long long> v;

bool palin(long long x) {
	char str[50];
	sprintf(str, "%lld", x);
	string s = str;
	string r = s;
	reverse(r.begin(), r.end());
	return s == r;
}

void gen() {
	v.clear();
	long long i;
	long long MAX = 10000000;
	MAX *= MAX;
	for(i = 1; i * i <= MAX; i++) {
		if( palin(i) && palin(i*i) ) {
			v.push_back(i*i);
			//cout << i << " " << v.back() << "\n";
		}
	}

}

int main() {
	int test, cases = 1;
	gen();
	cin >> test;
	for(cases  = 1; cases <= test; cases++) {
		long long a, b;
		cin >> a >> b;
		int res = 0;
		for(int i = 0; i < v.size(); i++)
			if( v[i] >= a && v[i] <= b ) res++;
		printf("Case #%d: %d\n", cases, res);
	}
	return 0;
}
