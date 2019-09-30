#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int T, N, A;
double D, t[2000], x[2000], _a[250];

bool test(double a, double axl)
{
	for(int i=0;i<N;i++){
		double elapsed = t[i] - a;
		if(elapsed < 0) continue;
		double dist = 0.5 * elapsed * elapsed * axl;
		if(x[i] < dist) return false;
	}
	return true;
}

int main()
{
	scanf("%d", &T);
	for(int tt=0;tt<T;){
		scanf("%lf%d%d", &D, &N, &A);

		for(int i=0;i<N;i++) scanf("%lf%lf", t+i, x+i);
		for(int j=0;j<N-1;j++){
			if(x[j] < D && x[j+1] >= D){
				N = j+2;
				t[j+1] = t[j] + (t[j+1] - t[j]) * (D - x[j]) / (x[j+1] - x[j]);
				x[j+1] = D;
				break;
			}
		}

		for(int i=0;i<A;i++) scanf("%lf", _a+i);

		printf("Case #%d:\n", ++tt);
		for(int i=0;i<A;i++){

			double left=0, right=1e6;
			while(right-left>=2e-7){
				double mid = (left+right)/2;
				if(test(mid, _a[i])){
					right = mid;
				}else{
					left = mid;
				}
			}
			printf("%.7f\n", (left+right)/2 + sqrt(2 * D / _a[i]));
		}
	}
	return 0;
}
