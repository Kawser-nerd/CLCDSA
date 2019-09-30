#include <iostream>
#include <iomanip>
#include <string>
#include <stack>
#include <math.h>
#include <vector>

using namespace std;

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,j) for(int i=0;i<j;i++)
#define PI acos(-1)


typedef long long ll;
typedef pair<int,int> P;


double f(double H, double R){
	return R * R * PI * H;
}

int main(){

	int N,Q;
	cin >> N >> Q;

	vector<int> X(N), R(N), H(N);
	rep(i, N) cin >> X[i] >> R[i] >> H[i];


	rep(i,Q){

		double a, b;
		cin >> a >> b;

		double sum = 0;

		rep(j, N){
			double x = X[j], r = R[j], h = H[j];

			if(a <= x && x + h <= b) {
				sum += f(h, r);
			} else if(x <= a && a <= x + h && x + h <= b) {
				double h2 = x + h - a;
				double r2 = (r * h2) / h;
				sum += f(h2, r2);
			} else if(a <= x && x <= b && b <= x + h) {
				double h2 = x + h - b;
				double r2 = (r * h2) / h;
				sum += f(h, r) - f(h2, r2);
			} else if(x <= a && b <= x + h) {
				double h1 = x + h - a;
				double r1 = (r * h1) / h;
 
				double h2 = x + h - b;
				double r2 = (r * h2) / h;
				sum += f(h1, r1) - f(h2, r2);
			}
		}

		cout << fixed;
		cout.precision(20);
		cout << sum / 3.0 << endl;

	}



	return 0;
}