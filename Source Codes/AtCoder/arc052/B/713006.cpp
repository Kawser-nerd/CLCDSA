#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double pi = acos(-1);

int main() {
	int n, q;
	cin >> n >> q;
	
	vector<double> sum(20005);
	for(int i = 0; i < n; ++i) {
		int x, h;
		double r;
		cin >> x >> r >> h;
		
		double v = pi * r * r * h / 3.0;
		
		for(int j = 1; j <= h; ++j) {
			double rj = r * (h - j) / h;
			auto vj = (pi * rj * rj * (h - j)) / 3.0;
			sum[x + j] +=  v - vj;
			v -= v - vj;
		}
	}
	
	
	for(int i = 0; i < 20000; ++i) {
		sum[i + 1] += sum[i]; 
	}
	
	cout << fixed;
	
	for(int i = 0; i < q; ++i) {
		int a, b;
		cin >> a >> b;
		cout << sum[b] - sum[a] << endl;
	}
	
	return 0;
}