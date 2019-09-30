#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <fstream>
#include <queue>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <sstream>
#include <math.h>

#define For(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  For(i,0,n)

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))
#define SORT(c) sort((c).begin(),(c).end())
#define vi(m,a) vector<int> m(a)
#define vti(m,a,i) vector<vector<int>> m(a,vector<int>(i))
#define ALL(it,a) for(auto it = a.begin(); it!=a.end(); it++)
#define Fe(it,a) for(auto &it : a)
#define all(a) begin(a),end(a)

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define WARU 1000000007;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
void printhoge(set<int> v) {
	ALL(it, v) {
		cout << *it << " ";
	}
	cout << endl;

}

int main() {
	int m, n;
	cin >> n >> m;
	ll res = 1;
	int mm = m;

	if (n == 1) {
		cout << m << endl;
		return 0;
	}
	while (mm > n) {
		int tmp = mm / n;
		int yakusu = 1;
		for (int i = tmp; i >= 2;i--) {
			if (mm % i == 0) {
				yakusu = i;
				break;
			}
		}
		if (yakusu == 1)
			break;
		res *= yakusu;
		mm /= tmp;
	}
	cout << res << endl;

}