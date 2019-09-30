#include<stdio.h>
#include<assert.h>
#include<math.h>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<cmath>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<double, int> pdi;

const double EPS = 1e-8;
const double PI = acos(-1);

int a, b, c, d;
char* DB = "=ROYGBV";

int solve()
{
	int N;
	int D[10];
	scanf("%d", &N);
	for(int i = 1; i <= 6; i++) scanf("%d", D+i);
	int X[3][2] = {2, 5, 4, 1, 6, 3};
	for(int i = 0; i < 3; i++){
		int a = X[i][0], b = X[i][1];
		if( D[a] + D[b] == N && D[a] == D[b]){
			for(int i = 0; i < D[a]; i++){
				printf("%c", DB[a]);
				printf("%c", DB[b]);
			}
			return !printf("\n");
		}
	}
	if( D[2] && D[2] >= D[5] ) return !printf("IMPOSSIBLE\n");
	if( D[4] && D[4] >= D[1] ) return !printf("IMPOSSIBLE\n");
	if( D[6] && D[6] >= D[3] ) return !printf("IMPOSSIBLE\n");
	D[1] -= D[4], D[3] -= D[6], D[5] -= D[2];
	int mx = 1;
	if( D[mx] < D[3]) mx = 3;
	if( D[mx] < D[5]) mx = 5;
	
	if( D[mx] > (D[1] + D[3] + D[5] - D[mx]) ) return !printf("IMPOSSIBLE\n");

	int a, b;
	if( mx == 1 ) a = 3, b = 5;
	if( mx == 3 ) a = 1, b = 5;
	if( mx == 5 ) a = 1, b = 3;
	
	string E = "", F = "";
	if( D[a] < D[b] ) for(int i = 1; i <= D[b] - D[a]; i++) E += DB[b];
	if( D[b] < D[a] ) for(int i = 1; i <= D[a] - D[b]; i++) E += DB[a];
	for(int i = 1; i <= min(D[a], D[b]); i++){
		E += DB[a];
		E += DB[b];
	}
	reverse(E.begin(), E.end());
	for(int i = 1; i <= D[mx]; i++){
		F += DB[mx];
		F += E.back(); E.pop_back();
	}
	while(E.size()) F += E.back(), E.pop_back();

	string ans = "";
	for(int i = 0; i < F.size(); i++){
		ans += F[i];
		if( F[i] == 'R' ){
			for(int i = 0; i < D[4]; i++) ans += "GR";
			D[4] = 0;
		}
		if( F[i] == 'B' ){
			for(int i = 0; i < D[2]; i++) ans += "OB";
			D[2] = 0;
		}
		if( F[i] == 'Y' ){
			for(int i = 0; i < D[6]; i++) ans += "VY";
			D[6] = 0;
		}
	}
	cout << ans << "\n";
	ans += ans[0];
	for(int i = 0; i < N; i++){
		if( ans[i+1] == ans[i] ||
				ans[i] == 'O' && ans[i+1] != 'B' ||
				ans[i] == 'G' && ans[i+1] != 'R' ||
				ans[i] == 'V' && ans[i+1] != 'Y')
			return !printf("WAWAWAWAWAWA\n");
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++){
		printf("Case #%d: ", t);
		solve();
	}
}
