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

int K;
int N;
vector<int> start, type;
vector< vector<int> > chest;
int required[205] = {0};
bool possible(vector<int> &v, bool flag[]) {
	bool local[205];
	for(int i = 0; i < N; i++) local[i] = flag[i];
	int found[205] = {0};

	bool keys[205] = {false};
	for(int i = 0; i < v.size(); i++) {
		keys[ v[i] ]= true;
		found[ v[i] ]++;
	}

	queue<int> Q;
	for(int i = 1; i <= 200; i++)
		if( keys[i] ) Q.push(i);

	while(!Q.empty()) {
		int A = Q.front();
		Q.pop();

		for(int i = 0; i < N; i++) {
			if( local[i] == false && type[i] == A ) {
				local[i] = true;
				int j;
				for(j = 0; j < chest[i].size();j++) {
					found[ chest[i][j] ]++;
					if( keys[ chest[i][j] ] == false ) {
						keys[ chest[i][j] ] = true;
						Q.push(chest[i][j]);
					}
				}
			}
		}
	}

	for(int i = 0; i < N; i++) if( local[i] == false ) return false;
	for(int i = 1; i <= 200; i++) if( required[i] > found[i] ) return false;
	return true;


}

int present(vector<int> &v, int x) {
	for(int i = 0; i < v.size(); i++)
		if( v[i] == x ) return i;
	return -1;
}

int main() {
	int test, cases = 1;
	cin >> test;
	for(cases = 1; cases <= test; cases++) {
		cin >> K >> N;
		start = takeInput<int>(K);
		type.clear();
		chest.clear();
		for(int i = 0; i < N; i++) {
			int a; cin >> a; type.push_back(a);
			int b; cin >> b;
			vector<int> v;
			v = takeInput<int>(b);
			chest.push_back(v);
		}

		vector<int> res; res.clear();
		bool flag[205] = {false};
		for(int i = 0; i <  205; i++) required[i] = 0;
		int cnt = N;
		for(int i = 0; i < N; i++)
			required[ type[i] ]++;
		while(cnt--) {
			int i;
			for(i = 0; i < N; i++) {
				if( flag[i] == true ) continue;
				int index = present(start, type[i]);
				if( index == -1 ) continue;
				vector<int> bu = start;
				bu.erase(bu.begin() + index);
				for(int j = 0; j < chest[i].size(); j++)
					bu.push_back(chest[i][j]);


				flag[i] = true;
				required[ type[i] ]--;
				if( possible(bu, flag) ) {
					start = bu;
					break;
				}
				flag[i] = false;
				required[ type[i] ]++;
			}
			if( i < N ) {
				res.push_back(i+1);
			}
		}
		if( res.size() != N ) {
			printf("Case #%d: IMPOSSIBLE\n", cases);
		}
		else {
			printf("Case #%d:", cases);
			for(int i = 0; i < res.size(); i++) cout << " " << res[i];
			cout << endl;
		}
	}
	return 0;
}
