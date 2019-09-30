#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
const LL MOD = 1000000007;

#define PrintLn(X) cout << X << endl
#define Rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define For(i, a, b) for(int i = a; i < (int)(b); ++i)

LL pow_mod(LL a, LL b){
	LL res = 1;
	while(b > 0){
		if(b & 1) res = (res * a) % MOD;
		b >>= 1;
		a = (a * a) % MOD;
	}
	return res;
}

int main(void)
{
	int N;
	LL A, B;
	cin >> N >> A >> B;
	LL arr[50];
	Rep(i, N) cin >> arr[i];
	sort(arr, arr + N);
	if(A == 1){
		Rep(i, N) PrintLn((arr[i] % MOD));
		return 0;
	}
	LL count = 0;
	Rep(i, B){
		if(arr[0] * A > arr[N - 1]) break;
		count++;
		arr[0] *= A;
		sort(arr, arr + N);
	}
	B -= count;
	Rep(i, B % N) arr[i] *= A;
	sort(arr, arr + N);
	Rep(i, N) arr[i] %= MOD;
	Rep(i, N) arr[i] *= pow_mod(A % MOD, B / N);
	Rep(i, N) PrintLn((arr[i] % MOD));
	return 0;
}