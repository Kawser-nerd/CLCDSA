#include<iostream>
#include<map>
#include<vector>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<algorithm>
#include<deque>

#define ssync ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define F first
#define S second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef vector<ll> vll;
typedef vector<vll> vvl;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<ll,ll> pll;
const ll MOD = 1e9+7;
const ld PI = 3.14159265;

ll powerWithMod(ll base, ll exponent, ll modulus = LLONG_MAX)
{
	ll result = 1;
	base %= modulus;
	while(exponent > 0)
	{
		if(exponent % 2 == 1)
			result = (result * base) % modulus;
		exponent >>= 1;
		base = (base * base) % modulus;
	}
	return result;
}

ll modInverse(ll a, ll m = MOD)
{
	return powerWithMod(a, m-2, m);
}

int n;
ll a[123456], A, B;

bool check(ll k)
{
	ll tot=0;
	for(int i=1; i<=n; i++)
	{
		if(a[i] <= k*B)
			continue;
		tot += ((a[i] - k*B) + A - B - 1) / (A - B);
	}
	return tot <= k;
}

int main()
{
	ssync;
	cin >> n >> A >> B;
	for(int i=1; i<=n; i++)
		cin >> a[i];
	ll l=1, h=(ll)1e10;
	while(l+1 < h)
	{
		ll mid = (l + h)/2;
		if(check(mid))
			h=mid;
		else
			l=mid;
	}
	if(check(l-1))
		cout << l-1 << "\n";
	else if(check(l))
		cout << l << "\n";
	else
		cout << l+1 << "\n";
	return 0;
}