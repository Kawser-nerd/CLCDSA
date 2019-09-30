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

int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	ll TC; cin >> TC;
	for(ll tc = 1; tc<=TC; ++tc){
		cout << "Case #"<<tc<<":";

		ll k,c,s; cin >> k >> c >> s;

		if(s*c < k){
			cout << " IMPOSSIBLE\n";
			continue;
		}

		// query bits c*i ... c*(i+1)-1
		ll i = 0;
		for(ll q = 0; q < (k+c-1)/c; ++q){
			ll query = 0;
			ll pow = 1;
			for(ll l = 0; l < c && i < k; ++l){
				query += i*pow;
				pow *= k;
				++i;
			}

			cout << " " << query+1;
		}
		cout << endl;
		
	}
	return 0;
}


