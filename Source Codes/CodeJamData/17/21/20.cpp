#include<stdio.h>
#include<assert.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<double, int> pdi;

const double EPS = 1e-8;
const double PI = acos(-1);

int a, b, c, d;

void solve()
{
	int N, D;
	scanf("%d%d", &D, &N);
	double ans = 0;
	for(int i = 1; i <= N; i++){
		scanf("%d%d", &a, &b);
		ans = max(ans, (D-a)/(double)b);
	}
	printf("%.10lf\n", D / ans);
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
