#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
using namespace std;
using ulong = unsigned long;
using ll = long long;

struct Obj{
	int x, r, h;
	double getValue(int a, int b){
		if(b < x || x + h < a){ return 0; }
		if(a <= x && x + h <= b){
			return 1.0 / 3 * M_PI * r * r * h;
		}
		if(x < a && x + h <= b){
			int h2 = x + h - a;
			return 1.0 / 3 * M_PI * r * r * h2 * h2 * h2 / h / h;
		}else if(a <= x && b < x + h){
			int h2 = x + h - b;
			return 1.0 / 3 * M_PI * r * r * (h - 1.0 * h2 * h2 * h2 / h / h);
		}else{
			int h2 = x + h - a,
				h3 = x + h - b;
			return 1.0 / 3 * M_PI * r * r * (h2 * h2 * h2 - h3 * h3 * h3) / h / h;
		}
	}
};

int main(){
	int n, q;
	cin >> n >> q;
	vector<Obj> objs(n);
	for(int i=0;i<n;i++){
		int x, r, h;
		cin >> x >> r >> h;
		objs[i] = {x, r, h};
	}
	for(int i=0;i<q;i++){
		int a, b;
		cin >> a >> b;
		double ret = 0;
		for(auto& o : objs){
			ret += o.getValue(a, b);
		}
		cout<<fixed<<setprecision(20)<<ret<<endl;
	}

	return 0;
}