#include<iostream>
#include<cstdio>
using namespace std;

int main(){

	int n,q;
	int x[105] ={}, r[105] = {}, h[105] = {};
	double s[105] = {};
	
	cin >> n >> q;

	for(int i= 0; i< n;i++){
		cin >> x[i] >> r[i] >> h[i];
		s[i] = ((double)r[i] * (double)r[i] * 3.1415926535 * (double)h[i])/3;

		//cout << s[i] << endl;
	}

	for(int i= 0; i< q;i++){
		int a,b;
		double ans = 0;
		
		cin >> a >> b;

		for(int j = 0; j < n; j++){
			if(a<= x[j] && x[j]+h[j] <= b){
				ans += s[j];

				//cout << "ok1" << endl;
			}else if(a <= x[j] && x[j] < b){
				ans += s[j];
				double rr,hh;

				hh = h[j]+x[j]-b;
				rr = (r[j]*hh)/h[j];
				
				ans -= (rr * rr * 3.1415926535 * hh)/3;

				//cout << "ok2" << endl;
			}else if(x[j] < a && x[j]+h[j] <= b && a < x[j]+h[j]){
				//ans -= s[j];
				double rr,hh;

				hh = h[j]+x[j]-a;
				rr = (r[j]*hh)/h[j];
				
				ans += (rr * rr * 3.1415926535 * hh)/3;

				//cout << "ok3" << endl;
			}else if(x[j] < a && b < x[j]+h[j] ){
				ans += s[j];
				double rr,hh;

				hh = h[j]+x[j]-b;
				rr = (r[j]*hh)/h[j];
				
				ans -= (rr * rr * 3.1415926535 * hh)/3;

				hh = h[j]+x[j]-a;
				rr = (r[j]*hh)/h[j];
				
				ans -= s[j] - (rr * rr * 3.1415926535 * hh)/3;
				

				//cout << "ok4" << endl;
			}else{
				//cout << "no" << endl;
			}
		
		}
		
		//cout << ans << endl;
		printf("%.6f\n",ans);
	}

	return 0;
}