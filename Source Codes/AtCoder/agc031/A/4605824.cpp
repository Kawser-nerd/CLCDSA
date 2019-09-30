#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <set>
using namespace std;
#define mp make_pair
#define pb push_back
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vll vector<ll>
#define maxn 100010
#define mod 1000000007
#define int long long

template<typename T>
void trace(                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               T a){
	cout << a << "\n";
}

template<typename T, typename... Args>
void trace(T a, Args... args){
	cout << a << " ";
	trace(args...);
}

int f[257];
int last[257];
// int soms[257];
int s[maxn];

ll fp(ll x, ll y){
	if(!y) return 1;
	if(y&1) return x * fp(x,y-1) % mod;
	return fp(x*x%mod, y>>1);
}

int32_t main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	for(int i = 0; i < 26; i++) f['a'+i] = 0;
	for(int i = 0; i < n; i++){
		f[s[i]]++;
		// trace(s[i], f[s[i]]);
	}
	ll ans = 1;
	for(char i = 0; i < 26; i++) ans = ans * (f['a'+i]+1) % mod;
	ans = (ans -1 + mod) % mod;
	cout << ans << '\n';

	return 0;
}