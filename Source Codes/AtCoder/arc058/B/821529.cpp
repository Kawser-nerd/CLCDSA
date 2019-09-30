#include <type_traits>
#include <utility>
#include <iostream>
#include <array>
#include <vector>

constexpr int64_t mod = 1000000000 + 7;//??

//????????????mod??
inline int64_t imod(int64_t a, int64_t b)
{
	return (a >= 0) ? (a % b) : (a % b + b);
}

class mint;
//mint????????2??
mint pow(mint x, int64_t n);

//mod??????
class mint
{
public:
	//static void set_mod(int64_t m_)
	//{
	//	//???????
	//	if (m_ < 2)return;
	//	//mod?????
	//	mod = m_;
	//	//???????(mod)?????
	//	e_phi = m_;
	//	for (int i = 2; i * i <= m_; ++i)
	//	{
	//		if (m_ % i == 0)
	//		{
	//			e_phi = e_phi / i * (i - 1);
	//			for (; m_ % i == 0; m_ /= i);
	//		}
	//	}
	//	if (m_ != 1)e_phi = e_phi / m_ * (m_ - 1);
	//}
	mint operator+(const mint &other)const
	{
		return mint(imod(value + other.value, mod));
	}
	mint operator-(const mint &other)const
	{
		return mint(imod(value - other.value, mod));
	}
	mint operator*(const mint &other)const
	{
		return mint(imod(value * other.value, mod));
	}
	mint& operator+=(const mint &other)
	{
		value = imod(value + other.value, mod);
		return *this;
	}
	mint& operator-=(const mint &other)
	{
		value = imod(value - other.value, mod);
		return *this;
	}
	mint& operator*=(const mint &other)
	{
		value = imod(value * other.value, mod);
		return *this;
	}
	const mint& operator+()const { return *this; }
	mint& operator+() { return *this; }
	mint operator-()const
	{
		return mint(-value);
	}
	mint& operator++()
	{
		*this += 1;
		return *this;
	}
	mint operator++(int)
	{
		auto tmp = *this;
		*this += 1;
		return tmp;
	}
	mint& operator--()
	{
		*this -= 1;
		return *this;
	}
	mint operator--(int)
	{
		auto tmp = *this;
		*this -= 1;
		return tmp;
	}
	mint operator~()const
	{
		return pow(*this, e_phi - 1);
	}
	mint& operator=(const mint &other)
	{
		value = other.value;
		return *this;
	}
	template<typename T, std::enable_if_t<std::is_integral<T>::value, std::nullptr_t> =nullptr>
	explicit operator T()const
	{
		return value;
	}
	int64_t get()const
	{
		return value;
	}
	static int64_t getmod()
	{
		return mod;
	}
	mint(int64_t a_) :value(imod(a_, mod)) {}
	mint() :value(0) {}
private:
	static constexpr int64_t e_phi = mod - 1;
	int64_t value;
};

//mint???
//x^n??????
mint pow(mint x, int64_t n)
{
	mint res = 1;
	while (n > 0)
	{
		if (n & 1)res *= x;
		x *= x;
		n >>= 1;
	}
	return res;
}

//mint??stream???????
std::ostream& operator<<(std::ostream& os, mint i)
{
	os << (int64_t)i;
	return os;
}

std::istream& operator >> (std::istream& is, mint& i)
{
	int64_t tmp;
	is >> tmp;
	i = tmp;
	return is;
}

//mint?????
//O(x)???????????
//X?????
mint fact(mint x)
{
	static std::vector<mint> facts({ 1,1 });//[i] == !i(i???) ???0????1

	if ((size_t)(x) < facts.size()) {
		return facts[(size_t)(x)];
	}
	facts.reserve((size_t)(x)+1);
	mint res(facts.back());
	for (size_t i = facts.size(); i <= (size_t)x; ++i)
	{
		res *= i;
		facts.push_back(res);
	}
	return res;
}

//mint?????????
//facts?0?x?????????????
//O(x)???????????
inline void fact_set(mint x = mint(-1))
{
	fact(x);
}
//n???r???????
inline mint combination(mint n, mint r)
{
	//return facts[(size_t)(n)] * ~facts[(size_t)(n - r)] * ~facts[(size_t)r];
	return fact(n) * ~fact(n - r) * ~fact(r);
}

#include <iostream>

int main()
{
	mint h, w, a, b;
	std::cin >> h >> w >> a >> b;
	fact_set(h + w);
	mint ans;
	for (int64_t k = (int64_t)b; k < (int64_t)w; ++k)
	{
		ans += combination(mint(k) + h - a - mint(1), h - a - mint(1)) * combination(mint(-k) + w + a - 2, a - mint(1));
	}
	std::cout << ans << std::endl;
	return 0;
}