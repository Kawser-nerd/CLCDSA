/*{{{*/
/*includes e defines*/
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <sstream>
using namespace std;
typedef long long ll;
typedef vector< long long > vi;
typedef vector<string> VS;
typedef pair<int,int> PII;
#define sz(A) (int)(A).size()
#define FOR(A,B) for(int A=0; A < (int) (B);A++)
#define FOREACH(A,B) for((__typeof (B).begin) A = (B).begin(); A != (B).end(); A++)
#define pb push_back
#define all(x) x.begin() , x.end()
#define mp make_pair
/*}}}*/
/*{{{*/
/*main*/
void solveCase(int x);
int main() {
	int TESTES; scanf("%d", &TESTES);
	for(int TESTE = 1; TESTE <= TESTES; TESTE++) {
		printf("Case #%d: ", TESTE);
		solveCase(TESTE);
	}
    return 0;
}
/*}}}*/

long long v[510];

void solveCase(int TESTE) {
	int n;
	cin >> n;
	FOR(i, n) cin >> v[i];

	sort(v, v+n);

	if(n == 20) {
		map<long long, vi> ja;
		FOR(i, (1<<20)) {
			if(!i) continue;
			vi at;
			long long sum = 0;
			FOR(j, 20) {
				if(i & (1<<j)) {
					sum += v[j];
					at.pb( v[j] );
				}
			}
			if(!ja.count(sum)) {
				ja[sum] = at;
			} else {
				cout << endl;
				FOR(i, sz(at)) {
					if(i) cout << " ";
					cout << at[i];
				}
				cout << endl;
				at = ja[sum];
				FOR(i, sz(at)) {
					if(i) cout << " ";
					cout << at[i];
				}
				cout << endl;
				return;
			}
		}
		cout << "Impossible" << endl;
	} else {
		n = 44;
		map<long long, vi> ja;
		vector<ll> a1, a2;
		FOR(i, n) {
			if(i & 1) a1.pb( v[i] );
			else a2.pb( v[i] );
		}
		n = 0;
		FOR(i, sz(a1)) v[n++] = a1[i];
		FOR(i, sz(a2)) v[n++] = a2[i];

		FOR(kk, 4) {
			FOR(i, (1<<22)) {
				if(!i) continue;
				vi at;
				long long sum = 0;
				FOR(j, 22) {
					if(i & (1<<j)) {
						sum += v[j];
						at.pb( v[j] );
					}
				}
				if(!ja.count(sum)) {
					ja[sum] = at;
				} else if(ja[sum] != at){
					cout << endl;
					FOR(i, sz(at)) {
						if(i) cout << " ";
						cout << at[i];
					}
					cout << endl;
					at = ja[sum];
					FOR(i, sz(at)) {
						if(i) cout << " ";
						cout << at[i];
					}
					cout << endl;
					return;
				}
			}
			if(kk == 0) {
				reverse(v, v+n);
			} else {
				random_shuffle(v, v+n);
			}
		}
		cout << "Impossible" << endl;
	}


}

