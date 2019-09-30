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
template <uint64_t MOD> class mint_base;
//mint_base_base???????
template <uint64_t MOD> constexpr mint_base<MOD> m_pow(mint_base<MOD> x, uint64_t n)noexcept;
//mod???????????????????
template <uint64_t MOD_ = 1000000007>
class mint_base
{
public:
	static constexpr auto MOD = MOD_;
	static_assert(!(MOD <= 2), "MOD cannot be below 2.");
	static_assert(MOD <= (0xFFFFFFFFFFFFFFFF / 2), "MOD is too big");//??????????????
	static_assert(MOD <= 0xFFFFFFFF, "MOD is too big");//??????????????
	constexpr mint_base<MOD> operator+(const mint_base<MOD> &other)const noexcept
	{
		auto v = *this;
		return v += other;
	}
	constexpr mint_base<MOD> operator-(const mint_base<MOD> &other)const noexcept
	{
		auto v = *this;
		return v -= other;
	}
	constexpr mint_base<MOD> operator*(const mint_base<MOD> &other)const noexcept
	{
		auto v = *this;
		return v *= other;
	}
	constexpr auto operator/(const mint_base<MOD> &other)const noexcept
	{
		auto v = *this;
		return v /= other;
	}
	constexpr mint_base<MOD>& operator+=(const mint_base<MOD> &other) noexcept
	{
		a += other.a;
		if (MOD <= a) { a -= MOD; };
		return *this;
	}
	constexpr mint_base<MOD>& operator-=(const mint_base<MOD> &other) noexcept
	{
		if (a >= other.a) {
			a -= other.a;
		}
		else {
			a = (a + MOD) - other.a;
		}
		return *this;
	}
	constexpr mint_base<MOD>& operator*=(const mint_base<MOD> &other) noexcept
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
	constexpr mint_base<MOD>& operator/=(const mint_base<MOD> &other) noexcept
	{
		return *this *= ~other;
	}
	constexpr mint_base<MOD> operator+()const noexcept { return *this; }
	constexpr mint_base<MOD> operator-()const noexcept
	{
		return{ MOD - a, mod_value_tag{} };
	}
	constexpr mint_base<MOD>& operator++() noexcept
	{
		if (MOD <= ++a) { a = 0; };
		return *this;
	}
	constexpr mint_base<MOD>& operator--() noexcept
	{
		if (a <= 0) { a = MOD; };
		--a;
		return *this;
	}
	constexpr mint_base<MOD> operator++(int) noexcept
	{
		auto tmp = *this;
		++*this;
		return tmp;
	}
	constexpr mint_base<MOD> operator--(int) noexcept
	{
		auto tmp = *this;
		--*this;
		return tmp;
	}
	constexpr mint_base<MOD> operator~()const noexcept
	{
		return ipow(*this, e_phi - 1);
	}
	constexpr mint_base<MOD>& operator=(const mint_base<MOD> &other) noexcept
	{
		a = other.a;
		return *this;
	}
	constexpr explicit operator uint64_t()const noexcept
	{
		return a;
	}
	constexpr explicit operator unsigned()const noexcept
	{
		return (unsigned)a;
	}
	static constexpr uint64_t getmod() noexcept
	{
		return MOD;
	}
	constexpr mint_base(uint64_t a_) noexcept :a(a_ % MOD) {}
	constexpr mint_base()noexcept : a(0) {}
	struct mod_value_tag {};
	constexpr mint_base(uint64_t a_, mod_value_tag) :a(a_) {}
private:
	static constexpr uint64_t get_e_phi()noexcept {
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
	static constexpr uint64_t e_phi = get_e_phi();//?????
	uint64_t a;
};
//mint_base???????
template<uint64_t MOD>constexpr mint_base<MOD> m_pow(mint_base<MOD> x, uint64_t n)noexcept
{
	mint_base<MOD> res = 1;
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
template<uint64_t MOD>constexpr mint_base<MOD> fact(mint_base<MOD> x)noexcept
{
	mint_base<MOD> res(1);
	for (uint64_t i = 1; i <= (uint64_t)x; ++i)
	{
		res *= i;
	}
	return res;
}
//mint_base?????
//0??x????????
//O(x)?????
template<uint64_t MOD>std::vector<mint_base<MOD>> fact_set(mint_base<MOD> x = mint_base<MOD>(-1))
{
	mint_base<MOD> res(1);
	std::vector<mint_base<MOD>> set((uint64_t)(x)+1);
	set[0] = 1;
	for (uint64_t i = 1; i <= (uint64_t)x; ++i)
	{
		res *= i;
		set[i] = res;
	}
	return res;
}
//mint_base??stream????
template<uint64_t MOD> std::ostream& operator<<(std::ostream& os, mint_base<MOD> i)
{
	os << (uint64_t)i;
	return os;
}
//mint_base??stream?????
template<uint64_t MOD> std::istream& operator >> (std::istream& is, mint_base<MOD>& i)
{
	uint64_t tmp;
	is >> tmp;
	i = tmp;
	return is;
}
typedef mint_base<1000000007> mint;
namespace mint_literal {
	constexpr mint operator""_mi(unsigned long long x)noexcept {
		return mint(x);
	}
}
using namespace mint_literal;
//mint_base?????
//0??x????????
//O(N)
template<int32_t X, uint64_t MOD = mint::MOD>
/*constexpr*/ std::array<mint_base<MOD>, X + 1> fact_set_c()
{
	mint_base<MOD> res(1);
	std::array<mint_base<MOD>, X + 1> set;
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
#if 1
	//?????O(logMOD)
	static const auto fact_v = fact_set_c<100001>();
	return fact_v[all] / (fact_v[get] * fact_v[all - get]);
#elif 0
	//?????O(1)
	//??????????????O(N^2)
	constexpr int32_t ALL_MAX = 10'000;
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


constexpr int64_t MOD = 1000000007;
int32_t N;
std::vector<int32_t> child[200001];
int32_t parent[200001];
int32_t num[200001];

std::vector<std::array<int32_t, 3>> dfs(int32_t v, int32_t d)
{
	num[d]++;
	if (child[v].empty()) {
		return{{1,1,0}};//[0]=1;[1]=1
	}

	auto&& res = dfs(child[v][0], d + 1);

	size_t edited = 0;
	for (size_t child_i = 1; child_i < child[v].size(); child_i++)
	{
		//???????????
		auto&& res2 = dfs(child[v][child_i], d + 1);
		if (res.size() < res2.size()) { std::swap(res, res2); }
		for (size_t i = 0; i < res2.size(); i++)
		{
			auto& resv = res[res.size()-res2.size()+i];
			//??????
			resv[2] = (((int64_t)(resv[1])*(int64_t)(res2[i][1])) % MOD + ((int64_t)(resv[2])*(int64_t)(res2[i][0] + res2[i][1] + res2[i][2])) % MOD + ((int64_t)(resv[0] + resv[1])*(int64_t)(res2[i][2])) % MOD);
			resv[1] = (((int64_t)(resv[1])*(int64_t)(res2[i][0])) % MOD + ((int64_t)(resv[0])*(int64_t)(res2[i][1])) % MOD) % MOD;
			resv[0] =  ((int64_t)(resv[0])*(int64_t)(res2[i][0])) % MOD;
		}
		edited = std::max(edited, res2.size());
	}
	for (size_t i = 0; i < edited; i++)
	{
		auto& resv = res[res.size() - edited + i];
		resv[0] = ((int64_t)(resv[0]) + (int64_t)(resv[2]))%MOD;
		resv[2] = 0;
	}
	res.push_back({ 1,1,0 });

	return std::move(res);
}

int main()
{
	using std::endl;
	in.sync_with_stdio(false);
	out.sync_with_stdio(false);
	in.tie(nullptr);
	out.tie(nullptr);

	in >> N;
	for (int32_t i = 1; i <= N; i++) {
		in >> parent[i];
		child[parent[i]].push_back(i);
	}

	auto&& root = dfs(0, 0);

	mint res = 0;
	for (size_t i = 0; i < root.size(); i++)
	{
		res += mint(root[i][1]) * ipow(2_mi, (uint32_t)(N + 1 - num[root.size()-1 -i]));
	}

	out << res << endl;

	return 0;
}
#endif