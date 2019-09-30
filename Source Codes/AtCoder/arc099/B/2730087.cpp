#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long Int;
typedef pair<Int, Int> P;
vector<Int> ans;
Int sum(Int x){
	if(x==0)return x;
	return x % 10 + sum(x/10);
}

double calc(Int hoge){
	return hoge*1.0 / sum(hoge);
}

double  best = 1LL<<62;

vector<Int> nums;

void hoge(Int b){
	for(Int i = 1;i * b < 1000000000000020LL;i*=10){
		nums.push_back(b*i-1);
	}
}
	

int main(){
	for(Int i = 1;i < 10000;i++){
		hoge(i);
	}
	sort(nums.begin(), nums.end());
	nums.erase(unique(nums.begin(),nums.end()), nums.end());
	
	for(int i = nums.size() - 1;i >= 0;i--){
		double tmp = calc(nums[i]);
		if(tmp <= best){
			ans.push_back(nums[i]);
			best = tmp;
		}
	}
	sort(ans.begin(), ans.end());
	//	cout << ans.size();
	Int k;
	cin >> k;
	for(Int i = 0;i < k;i++)cout << ans[i] << endl;
}