#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include <functional>
#include <iomanip>
typedef long long int ll;
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define REP(i,n) for (int i=0;i<(n);i++)
#define EREP(i,n) for (int i=1;i<=(n);i++)
#define EVEL 1

#ifndef EVEL
#define DEB(X) cout << #X << ":" <<X<<" " ;
#define TF(f) f ? cout<<"true  " : cout<<"false ";
#define END cout<<"\n";
#else
#define DEB(X) {X;}
#define TF(f) {f;}
#define END {}
#endif
const int MOD = 1000000007;
const int INF = 1000000;
#define NMAX 50
#define MAX 10

int N, A, B;
priority_queue<ll> v;
vector<ll> mo;
ll temp = 0, id = 0, mem, yui = 1, sum = 0;
long double ans, av = 0;
int TR[1000] = { 0 }, bf;
ll C[200][200];
bool fir = true;

void Conb(int N) {
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i)C[i][j] = 1;
			else {
				C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
			}
		}
	}
}



int main() {
	ios_base::sync_with_stdio(false);
	cin >> N >> A >> B;
	REP(i, N) {
		cin >> temp;
		v.push(temp);
		mo.push_back(temp);
	}
	sort(mo.begin(), mo.end(), greater<ll>());
	ll bu = 0;
	for (int j = A; j>0; j--) {
		bu += v.top();
		v.pop();
	}
	av = (double)bu / (double)A;

	int count = 0;
	int lo = 0;
	Conb(N);
	yui = 0;
	REP(i, N) {
		if (mo[i] == mo[A - 1]) {
			count++;
			if (i <= A - 1)lo++;
		}
		DEB(count)DEB(lo)DEB(mo[i])DEB(mo[A - 1])END
	}
	if (mo[0] == mo[A - 1]) {
		for(int32_t num = A;num <= B;++num) {
			yui += C[count][num];
		}
	}
	else {
		yui = C[count][lo];
	}

	cout << fixed << av << setprecision(10) << endl << yui << endl;
}
//ABC057 Maximum Average Sets ./Main.cpp:81:7: warning: expression result unused [-Wunused-value]
                DEB(count)DEB(lo)DEB(mo[i])DEB(mo[A - 1])END
                    ^~~~~
./Main.cpp:25:17: note: expanded from macro 'DEB'
#define DEB(X) {X;}
                ^
./Main.cpp:81:17: warning: expression result unused [-Wunused-value]
                DEB(count)DEB(lo)DEB(mo[i])DEB(mo[A - 1])END
                              ^~
./Main.cpp:25:17: note: expanded from macro 'DEB'
#define DEB(X) {X;}
                ^
2 warnings generated.