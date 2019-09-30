#include <iostream>
#include <vector>
#include <deque>
#include <bitset>

using namespace std;
#define rep(i,n) for(int i = 0 ; i < (int)(n) ; i++)
typedef long long ll;
typedef long double Double;

bool ok(deque<int> v,ll x){
	bitset<32000> cur;
	cur[16000] = 1;
	for(int i = 0 ; i < v.size() ; i++){
		cur = (cur << v[i]) | (cur >> v[i]);
	}
	return cur[16000 + x];
}
void solve(string s, ll x, ll y){
	s += "T";
	deque<int> v[2];
	int c = 0;
	int t = 0;
	for(int i = 0 ; i < s.size() ; i++){
		if( s[i] == 'T' ) v[t].push_back(c), c = 0, t ^= 1;
		else if( s[i] == 'F' ) c++;
	}
	x -= v[0][0];
	v[0].pop_front();

	cout << (ok(v[0], x) && ok(v[1], y) ? "Yes" : "No") << endl;
}

int main(){	
	ll y;
	string s;
	ll x;
	cin >> s;
	scanf("%lld",&x);
	scanf("%lld",&y);
	solve(s, x, y);
	return 0;
}