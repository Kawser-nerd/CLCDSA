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
typedef long long LL;
typedef vector<int> VI;
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
void solveCase();
int main() {
	int TESTES; scanf("%d", &TESTES);
	for(int TESTE = 1; TESTE <= TESTES; TESTE++) {
		printf("Case #%d: ", TESTE);
		solveCase();
	}
    return 0;
}
/*}}}*/

#define N 264
int n;
pair<double,int> s[N];
double sum;

int ok(int pos, double val) {
	double nota = s[pos].first + sum * val;
	double ja = val;

	FOR(i, n) {
		if(i == pos) continue;
		if(s[i].first >= nota) continue;
		double falta = nota - s[i].first;
		double precisa = falta / sum;
		if(precisa + ja > 1.0) return 1;
		ja += precisa;
	}

	if(ja < 1) return 0;
	return 1;

}

double busca(int pos) {
	double ini = 0, fim = 1, meio, ans = 0;
	FOR(i, 250) {
		meio = (ini+fim) / 2.0;
		if(ok(pos, meio)) {
			ans = fim = meio;
		} else {
			ini = meio;
		}
	}

	

	return 100.0 * ans;
}

void solveCase() {
	cin >> n;
	sum = 0;
	FOR(i, n) {
		cin >> s[i].first;
		sum += s[i].first;
		s[i].second = i;
	}
	
	sort( s, s+n );

	vector<double> ans(n);
	FOR(i, n) {
		ans[ s[i].second ] = busca(i);
	}
	
	FOR(i, n) {
		if(i) cout << " ";
		cout.precision(10);
		cout << fixed << ans[i];
	}
	cout << endl;

}

