#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
#include<map>
using namespace std;
using ulong = unsigned long;
using ll = long long;
const int M = 1e9 + 7;

template <class T>
struct SegNode{
	SegNode *left, *right;
	int start, last;
	int value;
	SegNode(int l, int r, const vector<T>& data) :start(l), last(r){
		if(l != r){
			left = new SegNode<T>(l, (l + r)/2, data);
			right = new SegNode<T>((l + r)/2 + 1, r, data);
			value = min(left -> value , right -> value);
		}else{
			value = data[l];
		}
	}
	int getMin(int l, int r){
		if(last < l || r < start){
			return 1e9;
		}
		if(l <= start && last <= r){
			return value;
		}
		return min(left -> getMin(l, r), right -> getMin(l, r));
	}
};

int main(){
	int n, x;
	cin >> n >> x;
	vector<int> as(n);
	for(int i=0;i<n;i++){
		cin >> as[i];
	}
	auto root = new SegNode<int>(0, n - 1, as);
	ll ans = 1e18;
	for(int i=0;i<n;i++){
		ll tmp = x * i;
		for(int j=0;j<n;j++){
			if(j - i >= 0){
				tmp += root -> getMin(j - i, j);
			}else{
				tmp += min(root -> getMin(0, j), root -> getMin(n - (i - j), n - 1));
			}
		}
		ans = min(ans, tmp);
	}
	cout << ans << endl;
	return 0;
}