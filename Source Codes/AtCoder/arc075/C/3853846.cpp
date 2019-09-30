#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <iomanip>
#include <cstdio>
#include <stack>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)


#define MAX_BIT 64
	
struct BitRank {
	// block: bit ????, count: block ???????? 1 ?????
	vector<unsigned long long> block;
	vector<int> count;
	BitRank(){}
	void resize(int num) {
		block.resize((num + 1) / MAX_BIT + 1, 0);
		count.resize((int)block.size(), 0);
	}
	// i ????? val(0,1) ????
	inline void set(int i, unsigned long long val) {
		block[i / MAX_BIT] |= (val << (i % MAX_BIT));
	}
	void build() {
		for(int i = 1; i < (int)block.size(); i++){
			count[i] = count[i-1] + __builtin_popcountll(block[i-1]);
		}
	}
	// [0, i) ???? 1 ??
	inline int rank1(int i) {
		int j = i / MAX_BIT, k = i % MAX_BIT;
		return count[j] + (k ? __builtin_popcountll(block[j] << (MAX_BIT - k)) : 0);
	}
	// [j, i) ???? 1 ??
	inline int rank1(int i, int j) {
		return rank1(j) - rank1(i);
	}
	// [0, i) ???? 0 ??
	inline int rank0(int i) {
		return i - rank1(i);
	}
	// [j, i) ???? 0 ??
	inline int rank0(int i, int j) {
		return rank0(j) - rank0(i);
	}
};
	
class WaveletMatrix
{
private:
	int height;
	vector<BitRank> B;
	vector<int> pos;
	int rangefreq(int i, int j, int a, int b, int l, int r, int x) {
		if(r <= a || b <= l) return 0;
		int mid = (l + r) >> 1;
		if(a <= l && r <= b){
			return j - i;
		}else{
			int left = rangefreq(B[x].rank0(i),B[x].rank0(j),a,b,l,mid,x+1);
			int right = rangefreq(pos[x]+B[x].rank1(i),pos[x]+B[x].rank1(j),a,b,mid,r,x+1);
			return left + right;
		}
	}
public:
	WaveletMatrix(){}
	WaveletMatrix(vector<int>& vec) :
		WaveletMatrix(vec, *max_element(vec.begin(), vec.end()) + 1) {}
	// sigma:??????
	WaveletMatrix(vector<int>& vec, int sigma){
		init(vec, sigma);
	}
	void init(vector<int>& vec, int sigma){
		height = (sigma == 1) ? 1 : (MAX_BIT - __builtin_clzll(sigma-1));
		B.resize(height), pos.resize(height);
		for(int i = 0; i < height; i++){
			B[i].resize((int)vec.size());
			for(int j = 0; j < (int)vec.size(); j++) {
				B[i].set(j, get(vec[j], height - i - 1));
			}
			B[i].build();
			auto it = stable_partition(vec.begin(), vec.end(), [&](int c) {
				return !get(c, height - i - 1);
			});
			pos[i] = it - vec.begin();
		}
	}
	// val ? i ?????????(0,1)
	inline int get(int val, int i) {
		return val >> i & 1;
	}
	// [l, r) ??????? val ??
	int rank(int val, int l, int r) {
		return rank(val, r) - rank(val, l);
	}
	// [0, i) ??????? val ??
	int rank(int val, int i) {
		int p = 0;
		for(int j = 0; j < height; j++){
			if(get(val, height - j - 1)){
				p = pos[j] + B[j].rank1(p);
				i = pos[j] + B[j].rank1(i);
			}else{
				p = B[j].rank0(p);
				i = B[j].rank0(i);
			}
		}
		return i - p;
	}
	// [l, r) ? k(1,2,3...) ??????????
	int quantile(int k, int l, int r) {
		int res = 0;
		for(int i = 0; i < height; i++){
			int j = B[i].rank0(l, r);
			if(j >= k){
				l = B[i].rank0(l);
				r = B[i].rank0(r);
			}else{
				l = pos[i] + B[i].rank1(l);
				r = pos[i] + B[i].rank1(r);
				k -= j;
				res |= (1 << (height - i - 1));
			}
		}
		return res;
	}
	// [l,r) ??? [a,b) ??????????
	int rangefreq(int l, int r, int a, int b) {
		return rangefreq(l, r, a, b, 0, 1 << height, 0);
	}
};
	
template<typename T> class OrthogonalRangeCount
{
private:
	using ptt = pair<T, T>;
	int sz;
	vector<T> X, Y;
	WaveletMatrix wm;
public:
	OrthogonalRangeCount(vector<ptt> candidate) : sz((int)candidate.size()), X(sz), Y(sz){
		vector<T> vec(sz);
		sort(candidate.begin(), candidate.end());
		for(int i = 0; i < sz; i++){
			X[i] = candidate[i].first, Y[i] = candidate[i].second;
		}
		sort(Y.begin(), Y.end());
		Y.erase(unique(Y.begin(), Y.end()), Y.end());
		for(int i = 0; i < sz; i++){
			vec[i] = lower_bound(Y.begin(), Y.end(), candidate[i].second) - Y.begin();
		}
		wm.init(vec, (int)Y.size());
	}
	// [lx,rx)×[ly,ry)??????????????????
	int query(T lx, T rx, T ly, T ry) {
		int lxid = lower_bound(X.begin(), X.end(), lx) - X.begin();
		int rxid = lower_bound(X.begin(), X.end(), rx) - X.begin();
		int lyid = lower_bound(Y.begin(), Y.end(), ly) - Y.begin();
		int ryid = lower_bound(Y.begin(), Y.end(), ry) - Y.begin();
		if(lxid >= rxid || lyid >= ryid) return 0;
		return wm.rangefreq(lxid, rxid, lyid, ryid);
	}
};


int main(){
	ll n,k;
	cin >> n >> k;
	vector<ll>a(n);
	rep(i,n)cin >> a[i];
	rep(i,n)a[i]-=k;
	vector<ll>s(n);
	s[0]= a[0];
	ll tmp = 0;
	if(s[0]>=0)tmp++;
	for(int i=1;i<n;i++){
		s[i] = s[i-1]+a[i];
		if(s[i]>=0)tmp++;
	}
	vector<ll> sa = s;
    sort(sa.begin(), sa.end());
    vector<int> ns(n);
    sa.erase(unique(sa.begin(),sa.end()),sa.end());
    map<ll,int> mp;
	for(int i = 0; i < sa.size(); i++){
        mp[sa[i]] = i;
    }
	rep(i,n){
		ns[i] = mp[s[i]];
	}
	vector<pair<int,int> > v;
	rep(i,n){
		v.PB(MP(i,ns[i]));
		
	}
	OrthogonalRangeCount<int> orc(v);
	ll ans = 0;
	rep(i,n){
		ans += (ll)orc.query(0,i+1,0,ns[i]+1);
		ans--;
	}
	//cerr << ans << " " << tmp << endl;
	cout << ans+tmp << endl;
	return 0;
}