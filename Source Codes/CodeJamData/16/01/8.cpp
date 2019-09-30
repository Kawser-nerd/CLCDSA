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
		ll n; cin >> n;
		seen.fill(false);

		if(n==0){
			cout << "INSOMNIA\n";
			continue;
		}

		ll i = 1;
		while(true){
			if(i > 1000000) break;
			if(update(i*n)) break;
			++i;
		}

		if(i > 1000000)
			cout << "INSOMNIA\n";
		else
			cout << i*n << endl;

	}
	return 0;
}


