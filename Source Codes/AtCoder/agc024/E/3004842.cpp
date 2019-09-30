#if 1
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <array>
#include <deque>
#include <algorithm>
#include <utility>
#include <cstdint>
#include <functional>
#include <iomanip>
#include <numeric>
#include <assert.h>
#include <bitset>
#include <list>

auto& in = std::cin;
auto& out = std::cout;
#define all_range(C) std::begin(C), std::end(C)
const double PI = 3.141592653589793238462643383279502884197169399375105820974944;

template<typename Arithmetic, typename Integral>
std::enable_if_t< std::is_unsigned<Integral>::value, Arithmetic>
ipow(Arithmetic bace, Integral n)
{
	//???????
	auto res = (Arithmetic)(1);
	while (n > 0) {
		if (n & 1) res *= bace;
		bace *= bace;
		n >>= 1;
	}
	return res;
}
constexpr bool is_prime(uint32_t N)
{
	if (N <= 1) {
		return false;
	}
	for (size_t i = 2; i*i <= N; ++i)
	{
		if (N%i == 0) {
			return false;
		}
	}
	return true;
}
uint64_t MOD;
class mint_base;
//mint_base_base???????
mint_base m_pow(mint_base x, uint64_t n)noexcept;
//mod???????????????????
class mint_base
{
public:
	//static_assert(!(MOD <= 2), "MOD cannot be below 2.");
	//static_assert(MOD <= (0xFFFFFFFFFFFFFFFF / 2), "MOD is too big");//??????????????
	//static_assert(MOD <= 0xFFFFFFFF, "MOD is too big");//??????????????
	mint_base operator+(const mint_base &other)const noexcept
	{
		auto v = *this;
		return v += other;
	}
	mint_base operator-(const mint_base &other)const noexcept
	{
		auto v = *this;
		return v -= other;
	}
	mint_base operator*(const mint_base &other)const noexcept
	{
		auto v = *this;
		return v *= other;
	}
	auto operator/(const mint_base &other)const noexcept
	{
		auto v = *this;
		return v /= other;
	}
	mint_base& operator+=(const mint_base &other) noexcept
	{
		a += other.a;
		if (MOD <= a) { a -= MOD; };
		return *this;
	}
	mint_base& operator-=(const mint_base &other) noexcept
	{
		if (a >= other.a) {
			a -= other.a;
		}
		else {
			a = (a + MOD) - other.a;
		}
		return *this;
	}
	mint_base& operator*=(const mint_base &other) noexcept
	{
#if 1
		a *= other.a;
		a %= MOD;
#else
		//MOD <= (MAXUINT64 / 2)???
		uint64_t b = other.a, v = 0;
		while (b > 0) {
			if (b & 1) {
				v += a;
				if (v >= MOD)v -= MOD;
			}
			a += a;
			if (MOD <= a)a -= MOD;
			b >>= 1;
		}
		a = v;
#endif
		return *this;
	}
	mint_base& operator/=(const mint_base &other) noexcept
	{
		return *this *= ~other;
	}
	mint_base operator+()const noexcept { return *this; }
	mint_base operator-()const noexcept
	{
		return{ MOD - a, mod_value_tag{} };
	}
	mint_base& operator++() noexcept
	{
		if (MOD <= ++a) { a = 0; };
		return *this;
	}
	mint_base& operator--() noexcept
	{
		if (a <= 0) { a = MOD; };
		--a;
		return *this;
	}
	mint_base operator++(int) noexcept
	{
		auto tmp = *this;
		++*this;
		return tmp;
	}
	mint_base operator--(int) noexcept
	{
		auto tmp = *this;
		--*this;
		return tmp;
	}
	mint_base operator~()const noexcept
	{
		return ipow(*this, e_phi - 1);
	}
	mint_base& operator=(const mint_base &other) noexcept
	{
		a = other.a;
		return *this;
	}
	explicit operator uint64_t()const noexcept
	{
		return a;
	}
	explicit operator unsigned()const noexcept
	{
		return (unsigned)a;
	}
	static  uint64_t getmod() noexcept
	{
		return MOD;
	}
	mint_base(uint64_t a_) noexcept :a(a_ % MOD) {}
	mint_base()noexcept : a(0) {}
	struct mod_value_tag {};
	mint_base(uint64_t a_, mod_value_tag) :a(a_) {}

	static void set_e_phi() {
		e_phi = get_e_phi();
	}
private:
	static uint64_t get_e_phi()noexcept {
		//????????
		uint64_t temp = MOD;
		uint64_t m_ = MOD;
		for (uint64_t i = 2; i * i <= m_; ++i)
		{
			if (m_ % i == 0)
			{
				temp = temp / i * (i - 1);
				for (; m_ % i == 0; m_ /= i);
			}
		}
		if (m_ != 1)temp = temp / m_ * (m_ - 1);
		return temp;
	}
	static uint64_t e_phi;//?????
	uint64_t a;
};
uint64_t mint_base::e_phi = 0;
//mint_base???????
mint_base m_pow(mint_base x, uint64_t n)noexcept
{
	mint_base res = 1;
	while (n > 0)
	{
		if (n & 1)res *= x;
		x *= x;
		n >>= 1;
	}
	return res;
}
//mint_base?????
//O(x)?????????fact_set????????
mint_base fact(const mint_base& x)noexcept
{
	mint_base res(1);
	for (uint64_t i = 1; i <= (uint64_t)x; ++i)
	{
		res *= i;
	}
	return res;
}
//mint_base?????
//0??x????????
//O(x)?????
std::vector<mint_base> fact_set(mint_base x = mint_base(-1))
{
	mint_base res(1);
	std::vector<mint_base> set((uint64_t)(x)+1);
	set[0] = 1;
	for (uint64_t i = 1; i <= (uint64_t)x; ++i)
	{
		res *= i;
		set[i] = res;
	}
	return set;
}
//mint_base??stream????
std::ostream& operator<<(std::ostream& os, mint_base i)
{
	os << (uint64_t)i;
	return os;
}
//mint_base??stream?????
std::istream& operator >> (std::istream& is, mint_base& i)
{
	uint64_t tmp;
	is >> tmp;
	i = tmp;
	return is;
}
typedef mint_base mint;
namespace mint_literal {
	mint operator""_mi(unsigned long long x)noexcept {
		return mint(x);
	}
}
using namespace mint_literal;
//mint_base?????
//0??x????????
//O(N)
template<int32_t X>
/*constexpr*/ std::array<mint_base, X + 1> fact_set_c()
{
	mint_base res(1);
	std::array<mint_base, X + 1> set;
	set[0] = 1;
	for (int32_t i = 1; i <= X; ++i)
	{
		res *= i;
		set[i] = res;
	}
	return set;
}
template<typename RET = mint, typename Integral>
RET combination(Integral all, Integral get)
{
	assert(all >= get);
	get = std::min(all - get, get);
#if 0
	//?????O(1)+???O(NlogMOD)
	//static_assert(false, "");
	static const auto fact_v = fact_set_c<300*300+600 + 1>();
	static const auto fact_div_v = [&]() {
		auto tmp = fact_v;
		for (auto& i : tmp) { i = ~i; }
		return tmp;
	}();
	//return fact_v[all] / (fact_v[get] * fact_v[all - get]);
	return fact_v[all] * fact_div_v[get] * fact_div_v[all - get];
#elif 1
	//?????O(1)
	//??????????????O(N^2)
	constexpr int32_t ALL_MAX = 333;// 10'000;
	static std::vector<RET> DP_comb[ALL_MAX + 1];
	if (!DP_comb[all].empty())
	{
		return DP_comb[all][get];
	}

	if (DP_comb[0].empty())
	{
		DP_comb[0].resize(1);
		DP_comb[0][0] = (RET)1;
		DP_comb[1].resize(1);
		DP_comb[1][0] = (RET)1;
	}
	for (int32_t i = 2; i <= all; i++)
	{
		if (DP_comb[i].empty())
		{
			int32_t size = i / 2 + 1;
			DP_comb[i].resize(size);
			DP_comb[i][0] = (RET)1;
			for (int32_t j = 1; j < size - 1; j++)
			{
				DP_comb[i][j] = DP_comb[i - 1][j - 1] + DP_comb[i - 1][j];
			}
			DP_comb[i][size - 1] = DP_comb[i - 1][size - 2] + DP_comb[i - 1][(i & 1) ? (size - 1) : (size - 2)];
		}
	}
	return DP_comb[all][get];
#else
	//?????O(get * logMOD)
	RET ret = (RET)1;
	for (Integral i = 1; i <= get; ++i)
	{
		ret *= all + 1 - i;
		ret /= i;
	}
	return ret;
#endif
}

int32_t N,K;

bool used3[301][300 + 1];
mint dp3[301][300 + 1];
mint m_pow_memo(int32_t base, int32_t n)
{
	if (used3[base][n]) {
		return dp3[base][n];
	}
	used3[base][n] = true;
	return dp3[base][n] = m_pow(base,n);
}

bool used2[301][300 + 1];
mint dp2[301][300 + 1];
mint func(int t, int l)
{
	if (t == 0) {
		return 1_mi;
	}
	if (l == 0) {
		return 1_mi;
	}
	auto& res = dp2[t][l];
	if(used2[t][l]){
		return res;
	}
	used2[t][l] = true;

	res = 0_mi;
	for (int32_t  i = 0; i <= l; i++)
	{
		res += m_pow_memo(t+1,i)*func(t - 1, l - i);
	}
	return res;
}


mint dp[301][300 + 1];

int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);
	in.tie(nullptr);
	out.tie(nullptr);

	in >> N>>K>>MOD;
	mint::set_e_phi();

	for (int32_t k = 1; k <= K; k++)
	{
		for (int32_t t = 0; t <= N; t++)
		{
			if (t == 0) { dp[k][t] = 1_mi; continue; }
			if (k == 1) { dp[k][t] = 1_mi; continue; }
			dp[k][t] = 0;
			for (int32_t l = 0; l <= t; l++)//l?k???
			{
				dp[k][t] +=
					func(t-l,l)* //k???
					dp[k - 1][t - l];
			}
		}
	}
	out << dp[K][N] << endl;

	return 0;
}
#endif