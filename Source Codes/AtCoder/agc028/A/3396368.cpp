#include <iostream>
#include <algorithm>
#include <string>
#include <numeric>

#define REP(i,n) for(int i=0; i<n; i++)
#define debug(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl;
 
#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9

using namespace std;
typedef long long ll;

ll gcd(ll m, ll n){
	while (m!=n){
		if (m>n) m = m-n;
		else n = n-m;
	}
	return m;
}

ll lcm(ll m, ll n){
	return ((m/gcd(m,n)) * n);
}

int main(){
	ll n1, m1, l, n, m;
	string s1, t1, s, t;
	
	cin >> n1 >> m1 >> s1 >> t1;
	
	n = n1>=m1 ? n1 : m1;
	m = n1>=m1 ? m1 : n1;
	s = n1>=m1 ? s1 : t1;
	t = n1>=m1 ? t1 : s1;
	
	l = lcm(n, m);
	
	for (int i=0; i<gcd(n, m); i++){
		if (s[i*l/m]!=t[i*l/n]){
			cout << -1 << endl;
			return 0;
		}
	}
	
	cout << l << endl;
	
	return 0;
}