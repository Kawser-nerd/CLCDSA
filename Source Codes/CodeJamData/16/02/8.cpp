#define HEADER_H
//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i,n)	for(auto i=decltype(n)(0); i<(n); ++i)
#define all(v)		begin(v), end(v)
using namespace std;		using ull= unsigned long long;
using ll = long long;		using ld = long double;
using vi = vector<ll>;		using vvi= vector<vi>;
using vb = vector<bool>;	using ii = pair<ll,ll>;
constexpr bool LOG = true;
void Log() { if(LOG) cerr << "\n"; }
template<class T, class... S> void Log(T t, S... s){
	if(LOG) cerr << t << "\t", Log(s...);
} /* ============== END OF HEADER ============== */


array<bool, 10> seen;

bool update(ll x){
	while(x)
		seen[x%10] = true, x/=10;
	return all_of(all(seen), [](bool x){return x;});
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	ll TC; cin >> TC;
	for(ll tc = 1; tc<=TC; ++tc){
		cout << "Case #"<<tc<<": ";
		
		string s; cin >> s;
		while(!s.empty() && s.back()=='+') s.pop_back();
		if(s.empty()){
			cout << 0 << endl;
			continue;
		}
		// count the number of + - swaps
		char last = '.';
		ll moves = 0;
		for(auto c : s){
			if(c != last) ++moves;
			last = c;
		}

		cout << moves << endl;
	}
	return 0;
}


