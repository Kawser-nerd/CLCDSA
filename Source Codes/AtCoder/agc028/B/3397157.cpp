#include <iostream>
#define llint long long 
#define mod 1000000007

using namespace std;

llint fact[100005], fact_inv[100005];

llint pow(llint a, llint n)
{
	if(n == 0) return 1;
	if(n % 2){
		return ((a%mod) * (pow(a, n-1)%mod)) % mod;
	}
	else{
		return pow((a*a)%mod, n/2) % mod;
	}
}

void make_fact()
{
	llint val = 1;
	fact[0] = 1;
	for(int i = 1; i < 100005; i++){
		val *= i;
		val %= mod;
		fact[i] = val;
	}
	for(int i = 0; i < 100005; i++){
		fact_inv[i] = pow(fact[i], mod-2);
	}
}

llint N;
llint A[100005];
llint sum[100005], sumk[100005];
llint ek[100005], sumek[100005];

int main(void)
{
	make_fact();
	cin >> N;
	for(int i = 1; i <= N; i++) cin >> A[i];
	for(int i = 1; i <= N; i++){
		sum[i] = sum[i-1] + A[i];
		sum[i] %= mod;
	}
	for(int i = 1; i <= N-2; i++){
		llint tmp = fact[N] * 2;
		tmp *= pow(i+1, mod-2), tmp %= mod;
		tmp *= pow(i+2, mod-2), tmp %= mod;
		sumk[i] = sumk[i-1] + tmp, sumk[i] %= mod;
	}
	for(int i = 1; i <= N-1; i++){
		ek[i] = fact[N] * pow(i+1, mod-2) % mod;
		sumek[i] = sumek[i-1] + ek[i];
		sumek[i] %= mod;
	}
	
	llint ans = 0;
	for(int i = 1; i <= N; i++){
		if(i < N){
			ans += sum[i] * sumk[i-1] % mod, ans %= mod;
			ans += sum[i] * ek[i] % mod, ans %= mod;
		}
		if(i > 1){
			ans += mod - sum[i-1] * sumk[N-i] % mod, ans %= mod;
			ans += mod - sum[i-1] * ek[N-i+1] % mod, ans %= mod;
			//cout << ans << endl;
		}
		if(i == N){
			ans += sum[N] * sumek[N-1] % mod, ans %= mod;
			ans += sum[N] * fact[N] % mod, ans %= mod;
		}
		//cout << ans << endl;
	}
	cout << ans << endl;
	return 0;
}