#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int N; double d, x;
	while(cin >> N >> d >> x){
		double res = 0.0;
		while(N){
			res += 0.5*(2*d+(2*N-1)*x);
			double ns = ((2*N-2)*d + 4*d + 5*x)/(2*N);
			double ne = ((2*N-2)*(d+(2*N-1)*x) + 4*d + (8*N-9)*x)/(2*N);
			--N;
			d = ns;
			x = (ne-ns)/(2*N-1);
		}
		printf("%.10lf\n", res);
	}
}