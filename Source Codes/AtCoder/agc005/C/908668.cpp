#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<numeric>
#include<cmath>
#include<queue>
#include<set>
#include<map>
using namespace std;
using ulong = unsigned long;
using ll = long long;
const int M = 1e9 + 7;
#pragma unused(M)

int n;
vector<int> as;
bool solve(){
	if((as.back() % 2 == 1 && as.size() > 2 && as[0] == as[2]) ||
			(as.back() % 2 == 0 && as.size() > 1 && as[0] == as[1])){
		return false;
	}
	int idx = 0;
	while(idx < as.size() && as[0] == as[idx]) idx++;
	if(idx == as.size()){
		return true;
	}
	int num = as[idx], cnt = 1;
	for(int i=idx + 1;i<n;i++){
		if(as[i] == num){
			cnt++;
		}else if(cnt == 1){
			return false;
		}else if(num != as[i] - 1){
			return false;
		}else{
			num = as[i];
			cnt = 1;
		}
	}
	if(cnt == 1){
		return false;
	}
	return true;
}

int main(){
	cin >> n;
	as.resize(n);
	for(int i=0;i<n;i++){
		cin >> as[i];
	}
	sort(as.begin(), as.end());
	if(solve()){
		cout << "Possible" << endl;
	}else{
		cout << "Impossible" << endl;
	}
	return 0;
}