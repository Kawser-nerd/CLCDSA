
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <numeric>
#include <cassert>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)

ll gcd(ll a, ll b){
	if(b == 0)return a;
	return gcd(b, a % b);
}

void calc(){
	ll A, B;
	string in;
	cin >> in;
	FOR(i,0,sz(in)) if (in[i] == '/')in[i] = ' ';
	istringstream is(in);
	is >>  A >> B;
	ll G = gcd(A,B);
	A /= G;
	B /= G;
	if((B&(-B)) != B){
		cout << "impossible\n";
		return;
	}
	while(A >= 2){
		A /= 2;
		B /= 2;
	}
	ll num = 0;
	while(B > 1){
		++num;
		B/= 2;
	}
	cout << num <<  "\n";
}

int main() {
	int TC;
	cin >> TC;
	FOR(T,1,TC+1){
		cout << "Case #" << T << ": ";
		calc();
	}
	return 0;
}
