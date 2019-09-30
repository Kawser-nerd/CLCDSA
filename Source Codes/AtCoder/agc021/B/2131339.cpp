#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;

#define PI 3.141592653589793238462643383279
#define abs(x) ((x)<0?(-(x)):(x))
typedef long long Int;
double x[108000], y[108000];
bool ok[1080000];
double ans[1080000];
Int n;
double hoge(Int a, Int b, Int c){
	double ax = x[b] - x[a], ay = y[b] - y[a];
	double bx = x[c] - x[a], by = y[c] - y[a];
	return acos(
							(ax*bx+ay*by)/sqrt(ax*ax+ay*ay)/sqrt(bx*bx+by*by)
							);
}
Int area(Int a, Int b, Int c){
	Int ax = x[b] - x[a], ay = y[b] - y[a];
	Int bx = x[c] - x[a], by = y[c] - y[a];
	return abs(ax * by-  ay * bx);
}

bool inner(Int x, Int a, Int b, Int c){
	if(x ==  a || x == b || x == c)return false;
	if(area(a,b,c) == 0)return 0;
	return area(x, a, b) + area(x, b, c) + area(x, c, a) == area(a, b, c);
}

int main(){
	cin >> n;
	for(Int i = 0;i < n;i++){
		cin >> x[i] >> y[i];
	}

	for(Int i = 0;i < n;i++){
		ok[i] = true;
		for(Int j = 0;j < n;j++){
			for(Int k = 0;k < n;k++){
				for(Int l = 0;l < n;l++){
					if(inner(i,j,k,l))ok[i] = false;
				}
			}
		}
	}

	for(Int i = 0;i < n;i++){
		for(Int j = 0;j < n;j++){
			for(Int k = 0;k < n;k++){
				if(i == j || i == k)continue;
				ans[i] = max(ans[i], hoge(i, j, k));
			}
		}
	}
	for(Int i = 0;i < n;i++){
		if(!ok[i])cout << 0 << endl;
		else printf("%.10lf\n", (PI - ans[i]) / PI / 2);
	}
	return 0;
}