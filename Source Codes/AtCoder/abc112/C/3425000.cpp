#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);++i)

int N;

int x[102], y[102], h[102];

int main() {
	
	cin>>N;
	rep(i, N)cin>>x[i]>>y[i]>>h[i];
	
	int t;
	rep(i, N) {
		if(h[i]>0) {
			t = i;
			break;
		}
	}
	
	bool f;
	int H;
	rep(X, 101) {
		rep(Y, 101) {
			H = h[t] + abs(X-x[t]) + abs(Y-y[t]);
			f = true;
			rep(i, N) {
				if(max(H - abs(X-x[i]) - abs(Y-y[i]), 0) != h[i]) {
					f = false;
					break;
				}
			}
			if(f) {
				cout<<X<<' '<<Y<<' '<<H<<endl;
				return 0;
			}
		}
	}
	
	return 0;
}