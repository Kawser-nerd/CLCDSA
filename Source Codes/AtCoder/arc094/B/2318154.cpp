#include<iostream>
#include<algorithm>

using namespace std;
typedef long long Int;
#define INF (1LL<<30)

Int solve(Int x, Int y){
	if(x < y)swap(x, y);
	Int res = y-1;
	Int bottom = 0, top = x;
	while(top - bottom > 1){
		Int mid = (top + bottom) / 2;
		if(y*x >= (mid+y) * (mid+y+1))bottom = mid;
		else top = mid;
	}
	res += bottom;

	Int a = x*y / (y+bottom+1);
	if(x*y%(y+bottom+1) == 0)a--;
	res += a;
	return res;
}

int main(){
	Int q, x, y;
	cin >> q;
	while(q--){
		cin >> x >> y;
		cout << solve(x, y) << endl;
	}
	return 0;
}