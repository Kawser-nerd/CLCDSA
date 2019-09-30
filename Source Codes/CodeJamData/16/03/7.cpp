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
		cout << "Case #"<<tc<<":\n";
		ll n,j; cin >> n >> j;
		while(j--){
			cout << "11";
			for(ll i = 0; i < (n-4)/2; ++i){
				if(j&(1<<i))
					cout << "11";
				else
					cout << "00";
			}
			cout << "11";
			for(ll b = 2; b<=10; ++b){
				cout << " " << b+1;
			}
			cout << endl;
		}
	}
	return 0;
}


