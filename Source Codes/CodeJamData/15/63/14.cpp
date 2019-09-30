#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <stack>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;
typedef long long i64;
#define MOD @
#define ADD(X,Y) ((X) = ((X) + (Y)) % MOD)
#define DBG(...) (fprintf(stderr, "[line %d]: ", __LINE__), fprintf(stderr, __VA_ARGS__))

i64 gcd(i64 a, i64 b)
{
	return b == 0 ? a : gcd(b, a % b);
}

i64 lcm(i64 a, i64 b)
{
	return a / gcd(a, b) * b;
}

struct frac
{
	i64 a, b;
	
	frac() : a(0), b(0) {}
	frac(i64 a, i64 b) : a(a), b(b) {}
	
	frac canonize() { i64 g = gcd(a, b); return frac(a / g, b / g); }
	frac abs() { return frac(a < 0 ? -a : a, b < 0 ? -b : b); }
	
	bool isneg() { return (a < 0 ? 1 : 0) ^ (b < 0 ? 1 : 0); }
	
	void print() { printf("%lld %lld\n", a, b); }
};

inline frac operator+(const frac& a, const frac& b)
{
	i64 g = lcm(a.b, b.b);
	return frac(a.a * (g / a.b) + b.a * (g / b.b), g).canonize();
}

inline frac operator-(const frac& a, const frac& b)
{
	i64 g = lcm(a.b, b.b);
	return frac(a.a * (g / a.b) - b.a * (g / b.b), g).canonize();
}


int N, Fm;
char in[505050];

int main()
{
	int n_testcase;
	scanf("%d", &n_testcase);
	
	for (int testcase_id = 0; testcase_id++ < n_testcase; ) {
		// input and solve the problem
		double Fbas;
		scanf("%d%lf%s", &N, &Fbas, in);
		Fm = (int)(Fbas * 1000000 + 1e-6);
		
		int bp = -1; frac bsol(10, 1);
		frac target(Fm, 1000000);
		for (int i = 0; i < N; ++i) {
			int len = 0, ones = 0;
			for (int j = i; j < N; ++j) {
				++len;
				if (in[j] == '1') ++ones;
				
				frac diff = target - frac(ones, len);
				diff = diff.abs();
				if ((diff - bsol).a == 0) bp = min(bp, i);
				if ((diff - bsol).isneg()) {
					bp = i;
					bsol = diff;
				}
			}
		}
		
		printf("Case #%d: %d\n", testcase_id, bp);
		// print answer here
	}
	return 0;
}

