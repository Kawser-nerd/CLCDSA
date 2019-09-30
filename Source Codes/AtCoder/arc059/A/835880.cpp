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

int calc(int num, vector<int>& as){
	int ret = 0;
	for(int a : as){
		ret += (num - a) * (num - a);
	}
	return ret;
}

int main(){
	int n;
	cin >> n;
	vector<int> as(n);
	for(int i=0;i<n;i++){
		cin >> as[i];
	}

	int ans = 1e9;
	for(int i=-100;i<=100;i++){
		ans = min(ans, calc(i, as));
	}
	cout << ans << endl;
	return 0;
}