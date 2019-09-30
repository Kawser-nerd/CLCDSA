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

struct Elem{
	ll a, sum, accLen;
	bool operator < (const Elem& e) const{
		return a < e.a;
	}
};

int main(){
	int n;
	cin >> n;
	vector<Elem> nums(n + 1);
	ll ans = 0;
	long vecEnd = 1;
	nums[0] = {0, 0, 0};
	for(int i=1;i<=n;i++){
		int a;
		cin >> a;
		long pos = lower_bound(nums.begin(), nums.begin() + vecEnd, Elem{a, 0, 0}) - nums.begin();
		nums[pos] = {a, nums[pos - 1].sum + a * (i - nums[pos - 1].accLen), i};
		vecEnd = pos + 1;
		ans += nums[pos].sum;
	}
	cout << ans << endl;
	return 0;
}