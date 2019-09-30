//??????????
//#define PLASMA_NO_BOOST
#if 1

#include<iostream>
#include<list>
#include<algorithm>
#include<utility>
#include<type_traits>
#include<tuple>
#include<memory>
#include<iterator>
#include<string>
#include<functional>
#include<list>
#include<array>
#include<complex>
#include<numeric>
#include<iomanip>
#include<vector>
#include<queue>
#include<random>
#include<map>
#include<chrono>

#ifndef PLASMA_NO_BOOST
#include<boost/optional.hpp>
#include<boost/optional/optional_io.hpp>
#include<boost/variant.hpp>
#include<boost/range/adaptor/transformed.hpp>
#include<boost/range/adaptor/indexed.hpp>
#include<boost/range/adaptor/filtered.hpp>
#include<boost/range/algorithm.hpp>
#include<boost/range/irange.hpp>
#include<boost/multi_array.hpp>
#include<boost/preprocessor.hpp>
#endif

typedef long long int int64;
typedef unsigned long long uint64;
typedef long double double64;
constexpr int int_max_value = 0x7FFFFFFF;
constexpr unsigned int uint_max_value = 0xFFFFFFFF;
constexpr int64 int64_max_value = 0x7FFFFFFFFFFFFFFF;
constexpr uint64 uint64_max_value = 0xFFFFFFFFFFFFFFFF;

#ifdef PLASMA_NO_BOOST
struct none_t {};
constexpr none_t none{};
template<class T>class optional
{
	union inside_t
	{
		T value;
		none_t ignore;
		constexpr inside_t(T const& v) :value(v) {}
		constexpr inside_t(T&& v) : value(std::move(v)) {}
		constexpr inside_t(none_t) : ignore(none) {}
		constexpr inside_t() : ignore(none) {}
		constexpr inside_t(inside_t const&) = default;
		inside_t(inside_t&&) = default;
		inside_t& operator=(inside_t const&) = default;
		inside_t& operator=(inside_t&&) = default;
		~inside_t() = default;
	};
	inside_t inside;
	bool flag;
public:
	void swap(optional&& v)
	{
		std::swap(this->inside, v.inside);
		std::swap(this->flag, v.flag);
	}
	void reset()
	{
		if (flag)
		{
			inside.value.~T();
			inside.ignore = none;
			flag = false;
		}
	}

	constexpr optional(T const& v) :inside(v), flag(true) {}
	constexpr optional(T&& v) : inside(std::move(v)), flag(true) {}
	constexpr optional(none_t) : inside(), flag(false) {}
	constexpr optional() : inside(), flag(false) {}
	constexpr optional(optional const& v) : inside(v.inside), flag(v.flag) {}
	optional(optional&& v) : optional()
	{
		swap(std::move(v));
	}
	optional& operator=(optional const& v)
	{
		this->inside = v.inside;
		this->flag = v.flag;
		return *this;
	}
	optional& operator=(optional&& v)
	{
		swap(std::move(v));
		v.reset();
		return *this;
	}
	optional& operator=(T const& v)
	{
		reset();
		inside.value = v;
		flag = true;
		return *this;
	}
	optional& operator=(T&& v)
	{
		reset();
		inside.value = std::move(v);
		flag = true;
		return *this;
	}
	optional& operator=(none_t)
	{
		reset();
		return *this;
	}

	constexpr operator bool()const
	{
		return flag;
	}
	constexpr T const& operator*()const
	{
		return flag ? inside.value : throw std::domain_error("optional error: dont have value");
	}
	};
template<class T>constexpr optional<typename std::remove_reference<typename std::remove_const<T>::type>::type>make_optional(T&& v)
{
	return optional<std::remove_reference_t<std::remove_const_t<T>>>(std::forward<T>(v));
}
#else
using boost::optional;
using boost::none_t;
using boost::none;
#endif

#ifndef PLASMA_NO_BOOST
namespace adaptor
{
	using namespace boost::adaptors;
}
namespace algorithm
{
	using namespace boost::range;
	template<class SinglePassRange, class Pred>bool any_of(SinglePassRange const& range, Pred pred)
	{
		return std::any_of(std::begin(range), std::end(range), pred);
	}
	template<class SinglePassRange, class Pred>bool all_of(SinglePassRange const& range, Pred pred)
	{
		return std::all_of(std::begin(range), std::end(range), pred);
	}
}
#endif
namespace math
{
	template<class T>constexpr T pow(T p, int n)
	{
		return n == 0 ? T(1) : n == 1 ? p : n == 2 ? p*p : n % 2 == 0 ? pow(pow(p, n / 2), 2) : pow(pow(p, n / 2), 2)*p;
	}

	int log(long long int p, int n)
	{
		int64 t = n;
		for (int i = 0;;++i)
		{
			if (t > p)
				return i;
			t *= n;
		}
	}

	constexpr double pi = 3.141592653589793;

	namespace detail
	{
		int gcd(int larger, int less)
		{
			return less == 0 ? larger : gcd(less, larger%less);
		}
	}

	int gcd(int lhs, int rhs)
	{
		return lhs < rhs ? detail::gcd(rhs, lhs) : detail::gcd(lhs, rhs);
	}

	void fourier_transform(
		std::vector<std::complex<double>>& vec, std::size_t N)
	{
		std::vector<std::complex<double>> butterfly;
		vec.resize(N);
		butterfly.resize(N);

		std::complex<double> half(std::cos(pi), std::sin(pi));
		for (uint64 i = 1, k = N / 2;i < N;[&]() {i *= 2;k /= 2;}())//i*k == N/4
		{
			std::complex<double> circle(std::cos(pi / i), std::sin(pi / i));
			std::complex<double> c(1.0, 0);
			for (auto count = 0ull; count < i;++count)
			{
				for (auto j = 0ull;j < k;++j)
				{
					butterfly[count*k + j] =
						vec[2 * count*k + j] + vec[2 * count*k + j + k] * c;
					butterfly[count*k + j + N / 2] =
						vec[2 * count*k + j] + vec[2 * count*k + j + k] * c*half;
				}
				c *= circle;
			}
			std::swap(vec, butterfly);
		}
	}

	class polynomial
	{
		std::vector<std::complex<double>> value;
		void swap(polynomial&& p)
		{
			std::swap(value, p.value);
		}
	public:
		polynomial() :value{ 0.0 } {}
		polynomial(polynomial const&) = default;
		polynomial(std::vector<std::complex<double>>&& vec) :value(std::move(vec)) {}
		polynomial(polynomial&& p) :polynomial()
		{
			swap(std::move(p));
		}
		polynomial(std::initializer_list<std::complex<double>> lis) :value(lis) {}
		polynomial(std::complex<double> c) :polynomial({ c }) {}

		polynomial& operator=(polynomial const&) = default;
		polynomial& operator=(polynomial&& p)
		{
			value = std::vector<std::complex<double>>{ 0.0 };
			swap(std::move(p));
			return *this;
		}

		~polynomial() = default;
		std::complex<double> operator[](std::size_t deg)const
		{
			return deg >= value.size() ? 0.0 : value[deg];
		}
		std::size_t degree()const
		{
			return value.size() - 1;
		}
		void strict_degree_set()
		{
			std::size_t N = degree();
			for (;N > 0;--N)
			{
				if (value[N] != 0.0)
					break;
			}
			value.resize(N + 1);
		}
		void integer_degree_set()
		{
			std::size_t N = degree();
			for (;N > 0;--N)
			{
				std::cout << value[N] << " " << (std::norm(value[N]) > (1.0e-20)) << std::endl;
				if (std::norm(value[N]) > (1.0e-20))
					break;
			}
			value.resize(N + 1);
		}

		friend polynomial operator*(polynomial const& lhs, polynomial const& rhs)
		{
			std::size_t N = 1;
			while (true)
			{
				N *= 2;
				if (N > (lhs.degree() + rhs.degree()))
					break;
			}
			auto lhs_ = lhs.value;
			auto rhs_ = rhs.value;
			fourier_transform(lhs_, N);
			fourier_transform(rhs_, N);
			std::vector<std::complex<double>> vec;
			vec.reserve(N);
			for (std::size_t i = 0;i < N;++i)
			{
				vec.push_back(lhs_[i] * rhs_[i]);
			}
			for (auto& v : vec)
			{
				v = 2 * v.real() - v;
			}
			fourier_transform(vec, N);
			for (auto& v : vec)
			{
				v = (2 * v.real() - v)*(1.0 / N);
			}
			std::size_t k = N;
			for (;k > 0;--k)
			{
				if (std::norm(vec[k]) > 1.0e-23)
					break;
			}
			vec.resize(k + 1);
			return polynomial(std::move(vec));
		}
	};

	int real_integer(std::complex<double> c)
	{
		int v = static_cast<int>(c.real());
		double u = c.real() - v;
		return v + static_cast<int>(2 * u);
	}

	template<class T>polynomial make_poly(std::vector<T> const& vec)
	{
		auto range = vec | adaptor::transformed([](T const& v) {return static_cast<std::complex<double>>(v);});
		std::vector<std::complex<double>> ret(std::begin(range), std::end(range));
		return polynomial(std::move(ret));
	}
	polynomial make_poly(std::initializer_list<double>init)
	{
		std::vector<std::complex<double>> vec;
		for (auto v : init)
		{
			vec.emplace_back(v);
		}
		return polynomial(std::move(vec));
	}
	polynomial make_poly(std::initializer_list<int> init)
	{
		std::vector<std::complex<double>> vec;
		for (auto v : init)
		{
			vec.emplace_back(v);
		}
		return polynomial(std::move(vec));
	}
	template<class T>class infinite_value
	{
		optional<T> val;
	public:
		infinite_value(T const& v) :val(v) {}
		infinite_value(T&& v) :val(std::move(v)) {}
		infinite_value(none_t = none) :val() {}
		infinite_value(infinite_value const&) = default;
		infinite_value(infinite_value&&) = default;
		~infinite_value() = default;

		infinite_value& operator=(T const& v)
		{
			val = v;
			return *this;
		}
		infinite_value& operator=(T&& v)
		{
			val = std::move(v);
			return *this;
		}
		infinite_value& operator=(none_t)
		{
			val = boost::none;
			return *this;
		}
		infinite_value& operator=(infinite_value const&) = default;
		infinite_value& operator=(infinite_value&&) = default;

		operator bool()const
		{
			return static_cast<bool>(val);
		}
		T const& operator*()const
		{
			return *val;
		}

		friend infinite_value operator+(infinite_value const& lhs, infinite_value const& rhs)
		{
			return lhs&&rhs ? infinite_value<T>(*lhs + *rhs) : infinite_value<T>(none);
		}
		friend infinite_value operator+(infinite_value const& lhs, T const& rhs)
		{
			return lhs ? infinite_value<T>(*lhs + rhs) : infinite_value<T>(none);
		}
		friend infinite_value operator+(T const& lhs, infinite_value const& rhs)
		{
			return lhs&&rhs ? infinite_value<T>(*lhs + *rhs) : infinite_value<T>(none);
		}
		
		friend bool operator==(infinite_value const& lhs, infinite_value const& rhs)
		{
			return (!lhs&&!rhs) || (lhs&&rhs && (*lhs == *rhs));
		}
		friend bool operator==(infinite_value const& lhs, T const& rhs)
		{
			return lhs && (*lhs == rhs);
		}
		friend bool operator==(T const& lhs, infinite_value const& rhs)
		{
			return rhs && (lhs == *rhs);
		}


		friend bool operator<(infinite_value const& lhs, infinite_value const& rhs)
		{
			return !lhs ? false : !rhs ? true : *lhs < *rhs;
		}
		friend bool operator<(infinite_value const& lhs, T const& rhs)
		{
			return !lhs ? false : *lhs < rhs;
		}
		friend bool operator<(T const& lhs, infinite_value const& rhs)
		{
			return !rhs ? true : lhs < *rhs;
		}
		friend bool operator<=(infinite_value const& lhs, infinite_value const& rhs)
		{
			return (lhs < rhs) || (lhs == rhs);
		}
		friend bool operator<=(infinite_value const& lhs, T const& rhs)
		{
			return (lhs < rhs) || (lhs == rhs);
		}
		friend bool operator<=(T const& lhs, infinite_value const& rhs)
		{
			return (lhs < rhs) || (lhs == rhs);
		}


		friend bool operator>(infinite_value const& lhs, infinite_value const& rhs)
		{
			return  !rhs ? false : !lhs ? true : *lhs > *rhs;
		}
		friend bool operator>(infinite_value const& lhs, T const& rhs)
		{
			return !lhs ? true : *lhs > rhs;
		}
		friend bool operator>(T const& lhs, infinite_value const& rhs)
		{
			return !rhs ? false : lhs > *rhs;
		}
		friend bool operator>=(infinite_value const& lhs, infinite_value const& rhs)
		{
			return (lhs > rhs) || (lhs == rhs);
		}
		friend bool operator>=(infinite_value const& lhs, T const& rhs)
		{
			return (lhs > rhs) || (lhs == rhs);
		}
		friend bool operator>=(T const& lhs, infinite_value const& rhs)
		{
			return (lhs > rhs) || (lhs == rhs);
		}

	};
	template<std::size_t Mod>class modulo_number
	{
		uint64 val = {};
		static constexpr uint64 abs(int64 n)
		{
			return n <= -1 ? n + Mod : n;
		}
	public:
		modulo_number(modulo_number const&) = default;
		modulo_number(modulo_number&&) = default;
		modulo_number& operator=(modulo_number const&) = default;
		modulo_number& operator=(modulo_number&&) = default;
		~modulo_number() = default;

		constexpr modulo_number(uint64 num = {}) : val(num%Mod) {}
		constexpr modulo_number(unsigned int num) : val(num%Mod) {}
		constexpr modulo_number(int64 num) : val(abs(num%Mod)) {}
		constexpr modulo_number(int num) : val(abs(num%Mod)) {}

		modulo_number& operator=(uint64 num)
		{
			val = num%Mod;
			return *this;
		}
		modulo_number& operator=(int64 num)
		{
			val = abs(num%Mod);
			return *this;
		}
		modulo_number& operator=(unsigned int num)
		{
			val = num%Mod;
			return *this;
		}
		modulo_number& operator=(int num)
		{
			val = abs(num%Mod);
			return *this;
		}


		constexpr uint64 get()const
		{
			return val;
		}

		friend constexpr modulo_number<Mod> operator+(modulo_number<Mod>const& lhs, modulo_number<Mod>const& rhs)
		{
			return modulo_number<Mod>((lhs.val + rhs.val) % Mod);
		}
		friend constexpr modulo_number<Mod> operator+(modulo_number<Mod>const& lhs, int const& rhs)
		{
			return lhs + modulo_number<Mod>(rhs);
		}
		friend constexpr modulo_number<Mod> operator+(modulo_number<Mod>const& lhs, unsigned int const& rhs)
		{
			return lhs + modulo_number<Mod>(rhs);
		}
		friend constexpr modulo_number<Mod> operator+(modulo_number<Mod>const& lhs, int64 const& rhs)
		{
			return lhs + modulo_number<Mod>(rhs);
		}
		friend constexpr modulo_number<Mod> operator+(modulo_number<Mod>const& lhs, uint64 const& rhs)
		{
			return lhs + modulo_number<Mod>(rhs);
		}
		friend constexpr modulo_number<Mod> operator+(int const& lhs, modulo_number<Mod>const& rhs)
		{
			return modulo_number<Mod>(lhs) + rhs;
		}
		friend constexpr modulo_number<Mod> operator+(unsigned int const& lhs, modulo_number<Mod>const& rhs)
		{
			return modulo_number<Mod>(lhs) + rhs;
		}
		friend constexpr modulo_number<Mod> operator+(int64 const& lhs, modulo_number<Mod>const& rhs)
		{
			return modulo_number<Mod>(lhs) + rhs;
		}
		friend constexpr modulo_number<Mod> operator+(uint64 const& lhs, modulo_number<Mod>const& rhs)
		{
			return modulo_number<Mod>(lhs) + rhs;
		}

		friend constexpr modulo_number<Mod> operator-(modulo_number<Mod>const& lhs, modulo_number<Mod>const& rhs)
		{
			return modulo_number<Mod>((lhs.val + Mod - rhs.val) % Mod);
		}
		friend constexpr modulo_number<Mod> operator-(modulo_number<Mod>const& lhs, int const& rhs)
		{
			return lhs - modulo_number<Mod>(rhs);
		}
		friend constexpr modulo_number<Mod> operator-(modulo_number<Mod>const& lhs, unsigned int const& rhs)
		{
			return lhs - modulo_number<Mod>(rhs);
		}
		friend constexpr modulo_number<Mod> operator-(modulo_number<Mod>const& lhs, int64 const& rhs)
		{
			return lhs - modulo_number<Mod>(rhs);
		}
		friend constexpr modulo_number<Mod> operator-(modulo_number<Mod>const& lhs, uint64 const& rhs)
		{
			return lhs - modulo_number<Mod>(rhs);
		}
		friend constexpr modulo_number<Mod> operator-(int const& lhs, modulo_number<Mod>const& rhs)
		{
			return modulo_number<Mod>(lhs) - rhs;
		}
		friend constexpr modulo_number<Mod> operator-(unsigned int const& lhs, modulo_number<Mod>const& rhs)
		{
			return modulo_number<Mod>(lhs) - rhs;
		}
		friend constexpr modulo_number<Mod> operator-(int64 const& lhs, modulo_number<Mod>const& rhs)
		{
			return modulo_number<Mod>(lhs) - rhs;
		}
		friend constexpr modulo_number<Mod> operator-(uint64 const& lhs, modulo_number<Mod>const& rhs)
		{
			return modulo_number<Mod>(lhs) - rhs;
		}

		friend constexpr modulo_number<Mod> operator*(modulo_number<Mod>const& lhs, modulo_number<Mod>const& rhs)
		{
			return modulo_number<Mod>((lhs.val*rhs.val) % Mod);
		}
		friend constexpr modulo_number<Mod> operator*(modulo_number<Mod>const& lhs, int const& rhs)
		{
			return lhs * modulo_number<Mod>(rhs);
		}
		friend constexpr modulo_number<Mod> operator*(modulo_number<Mod>const& lhs, unsigned int const& rhs)
		{
			return lhs * modulo_number<Mod>(rhs);
		}
		friend constexpr modulo_number<Mod> operator*(modulo_number<Mod>const& lhs, int64 const& rhs)
		{
			return lhs * modulo_number<Mod>(rhs);
		}
		friend constexpr modulo_number<Mod> operator*(modulo_number<Mod>const& lhs, uint64 const& rhs)
		{
			return lhs * modulo_number<Mod>(rhs);
		}
		friend constexpr modulo_number<Mod> operator*(int const& lhs, modulo_number<Mod>const& rhs)
		{
			return modulo_number<Mod>(lhs) * rhs;
		}
		friend constexpr modulo_number<Mod> operator*(unsigned int const& lhs, modulo_number<Mod>const& rhs)
		{
			return modulo_number<Mod>(lhs) * rhs;
		}
		friend constexpr modulo_number<Mod> operator*(int64 const& lhs, modulo_number<Mod>const& rhs)
		{
			return modulo_number<Mod>(lhs) * rhs;
		}
		friend constexpr modulo_number<Mod> operator*(uint64 const& lhs, modulo_number<Mod>const& rhs)
		{
			return modulo_number<Mod>(lhs) * rhs;
		}

		friend constexpr modulo_number<Mod> operator/(modulo_number<Mod>const& lhs, modulo_number<Mod>const& rhs)
		{
			return lhs*math::pow(rhs, Mod - 2);
		}
		friend constexpr modulo_number<Mod> operator/(modulo_number<Mod>const& lhs, int const& rhs)
		{
			return lhs / modulo_number<Mod>(rhs);
		}
		friend constexpr modulo_number<Mod> operator/(modulo_number<Mod>const& lhs, unsigned int const& rhs)
		{
			return lhs / modulo_number<Mod>(rhs);
		}
		friend constexpr modulo_number<Mod> operator/(modulo_number<Mod>const& lhs, int64 const& rhs)
		{
			return lhs / modulo_number<Mod>(rhs);
		}
		friend constexpr modulo_number<Mod> operator/(modulo_number<Mod>const& lhs, uint64 const& rhs)
		{
			return lhs / modulo_number<Mod>(rhs);
		}
		friend constexpr modulo_number<Mod> operator/(int const& lhs, modulo_number<Mod>const& rhs)
		{
			return modulo_number<Mod>(lhs) / rhs;
		}
		friend constexpr modulo_number<Mod> operator/(unsigned int const& lhs, modulo_number<Mod>const& rhs)
		{
			return modulo_number<Mod>(lhs) / rhs;
		}
		friend constexpr modulo_number<Mod> operator/(int64 const& lhs, modulo_number<Mod>const& rhs)
		{
			return modulo_number<Mod>(lhs) / rhs;
		}
		friend constexpr modulo_number<Mod> operator/(uint64 const& lhs, modulo_number<Mod>const& rhs)
		{
			return modulo_number<Mod>(lhs) / rhs;
		}

		template<class Rhs>decltype(auto) operator+=(Rhs const& rhs)
		{
			return *this = *this + rhs;
		}
		template<class Rhs>decltype(auto) operator*=(Rhs const& rhs)
		{
			return *this = *this * rhs;
		}
		template<class Rhs>decltype(auto) operator-=(Rhs const& rhs)
		{
			return *this = *this - rhs;
		}
		template<class Rhs>decltype(auto) operator/=(Rhs const& rhs)
		{
			return *this = *this / rhs;
		}
	};

	template<class T>constexpr T factorial(std::size_t n, std::size_t goal = 1)
	{
		return n == goal ? T(n) : n == 0 ? T(1) : factorial<T>(n, (n + goal) / 2 + 1)*factorial<T>((n + goal) / 2, goal);
	}

	namespace detail
	{
		constexpr uint64 integral_sqrt_i(uint64 v, uint64 start, uint64 end)
		{
			return start == end ? start :
				pow((start + end) / 2 + 1, 2) <= v ?
				integral_sqrt_i(v, (start + end) / 2 + 1, end) :
				integral_sqrt_i(v, start, (start + end) / 2);
		}
	}

	constexpr uint64 integral_sqrt(uint64 v)
	{
		return v == 0 ? 0 : 
			v == 1 ? 1 : 
			detail::integral_sqrt_i(v, 1, 0b100000000000000000000000000000000ull);
	}

	namespace detail
	{
		constexpr bool is_prime_i(uint64 v, uint64 start, uint64 end)
		{
			return start == end ? v%end != 0 :
				is_prime_i(v, start, (start + end) / 2) && 
				is_prime_i(v, (start + end) / 2 + 1, end);
		}
	}

	constexpr bool is_prime(uint64 v)
	{
		return v == 0 ? false :
			v == 1 ? false :
			v == 2 ? true :
			v == 3 ? true : detail::is_prime_i(v, 2, integral_sqrt(v));
	}

	class dynamic_modulo
	{
		uint64 value;
		uint64 mod;
		static constexpr uint64 abs(int64 v, uint64 mod)
		{
			return v <= -1 ? v + mod : v;
		}
	public:
		constexpr dynamic_modulo() :value(), mod(2) {}
		constexpr dynamic_modulo(uint64 v, uint64 m) : value(v), mod(m) {}
		dynamic_modulo(dynamic_modulo const&) = default;
		dynamic_modulo(dynamic_modulo&&) = default;
		dynamic_modulo& operator=(dynamic_modulo const&) = default;
		dynamic_modulo& operator=(dynamic_modulo&&) = default;
		~dynamic_modulo() = default;

		constexpr uint64 get()const
		{
			return value;
		}

		constexpr friend auto operator+(dynamic_modulo const& lhs, dynamic_modulo const& rhs)
		{
			return lhs.mod != rhs.mod ? 
				throw std::logic_error("math::dynamic_modulo mod number error") :
				dynamic_modulo((lhs.value + rhs.value) % lhs.mod, lhs.mod);
		}
		constexpr friend auto operator+(dynamic_modulo const& lhs, uint64 const& rhs)
		{
			return dynamic_modulo((lhs.value + rhs) % lhs.mod, lhs.mod);
		}
		constexpr friend auto operator+(dynamic_modulo const& lhs, int64 const& rhs)
		{
			return dynamic_modulo(abs((lhs.value + rhs) % lhs.mod, lhs.mod), lhs.mod);
		}
		constexpr friend auto operator+(dynamic_modulo const& lhs, unsigned int const& rhs)
		{
			return dynamic_modulo((lhs.value + rhs) % lhs.mod, lhs.mod);
		}
		constexpr friend auto operator+(dynamic_modulo const& lhs, int const& rhs)
		{
			return dynamic_modulo(abs((lhs.value + rhs) % lhs.mod, lhs.mod), lhs.mod);
		}
		constexpr friend auto operator+(uint64 const& rhs, dynamic_modulo const& lhs)
		{
			return dynamic_modulo((lhs.value + rhs) % lhs.mod, lhs.mod);
		}
		constexpr friend auto operator+(int64 const& rhs, dynamic_modulo const& lhs)
		{
			return dynamic_modulo(abs((lhs.value + rhs) % lhs.mod, lhs.mod), lhs.mod);
		}
		constexpr friend auto operator+(unsigned int const& rhs, dynamic_modulo const& lhs)
		{
			return dynamic_modulo((lhs.value + rhs) % lhs.mod, lhs.mod);
		}
		constexpr friend auto operator+(int const& rhs, dynamic_modulo const& lhs)
		{
			return dynamic_modulo(abs((lhs.value + rhs) % lhs.mod, lhs.mod), lhs.mod);
		}

		constexpr friend auto operator*(dynamic_modulo const& lhs, dynamic_modulo const& rhs)
		{
			return lhs.mod != rhs.mod ?
				throw std::logic_error("math::dynamic_modulo mod number error") :
				dynamic_modulo((lhs.value * rhs.value) % lhs.mod, lhs.mod);
		}
		constexpr friend auto operator*(dynamic_modulo const& lhs, uint64 const& rhs)
		{
			return dynamic_modulo((lhs.value * rhs) % lhs.mod, lhs.mod);
		}
		constexpr friend auto operator*(dynamic_modulo const& lhs, int64 const& rhs)
		{
			return dynamic_modulo(abs((lhs.value * rhs) % lhs.mod, lhs.mod), lhs.mod);
		}
		constexpr friend auto operator*(dynamic_modulo const& lhs, unsigned int const& rhs)
		{
			return dynamic_modulo((lhs.value * rhs) % lhs.mod, lhs.mod);
		}
		constexpr friend auto operator*(dynamic_modulo const& lhs, int const& rhs)
		{
			return dynamic_modulo(abs((lhs.value * rhs) % lhs.mod, lhs.mod), lhs.mod);
		}
		constexpr friend auto operator*(uint64 const& rhs, dynamic_modulo const& lhs)
		{
			return dynamic_modulo((lhs.value * rhs) % lhs.mod, lhs.mod);
		}
		constexpr friend auto operator*(int64 const& rhs, dynamic_modulo const& lhs)
		{
			return dynamic_modulo(abs((lhs.value * rhs) % lhs.mod, lhs.mod), lhs.mod);
		}
		constexpr friend auto operator*(unsigned int const& rhs, dynamic_modulo const& lhs)
		{
			return dynamic_modulo((lhs.value * rhs) % lhs.mod, lhs.mod);
		}
		constexpr friend auto operator*(int const& rhs, dynamic_modulo const& lhs)
		{
			return dynamic_modulo(abs((lhs.value * rhs) % lhs.mod, lhs.mod), lhs.mod);
		}

		constexpr friend auto operator-(dynamic_modulo const& lhs, dynamic_modulo const& rhs)
		{
			return lhs.mod != rhs.mod ?
				throw std::logic_error("math::dynamic_modulo mod number error") :
				dynamic_modulo(abs((lhs.value - rhs.value) % lhs.mod, lhs.mod), lhs.mod);
		}
		constexpr friend auto operator-(dynamic_modulo const& lhs, uint64 const& rhs)
		{
			return dynamic_modulo(abs((lhs.value - rhs) % lhs.mod, lhs.mod), lhs.mod);
		}
		constexpr friend auto operator-(dynamic_modulo const& lhs, int64 const& rhs)
		{
			return dynamic_modulo(abs((lhs.value - rhs) % lhs.mod, lhs.mod), lhs.mod);
		}
		constexpr friend auto operator-(dynamic_modulo const& lhs, unsigned int const& rhs)
		{
			return dynamic_modulo(abs((lhs.value - rhs) % lhs.mod, lhs.mod), lhs.mod);
		}
		constexpr friend auto operator-(dynamic_modulo const& lhs, int const& rhs)
		{
			return dynamic_modulo(abs((lhs.value - rhs) % lhs.mod, lhs.mod), lhs.mod);
		}
		constexpr friend auto operator-(uint64 const& rhs, dynamic_modulo const& lhs)
		{
			return dynamic_modulo(abs((lhs.value - rhs) % lhs.mod, lhs.mod), lhs.mod);
		}
		constexpr friend auto operator-(int64 const& rhs, dynamic_modulo const& lhs)
		{
			return dynamic_modulo(abs((lhs.value - rhs) % lhs.mod, lhs.mod), lhs.mod);
		}
		constexpr friend auto operator-(unsigned int const& rhs, dynamic_modulo const& lhs)
		{
			return dynamic_modulo(abs((lhs.value - rhs) % lhs.mod, lhs.mod), lhs.mod);
		}
		constexpr friend auto operator-(int const& rhs, dynamic_modulo const& lhs)
		{
			return dynamic_modulo(abs((lhs.value - rhs) % lhs.mod, lhs.mod), lhs.mod);
		}

		template<class Rhs>dynamic_modulo& operator+=(Rhs const& rhs)
		{
			return *this = *this + rhs;
		}
		template<class Rhs>dynamic_modulo& operator-=(Rhs const& rhs)
		{
			return *this = *this - rhs;
		}
		template<class Rhs>dynamic_modulo& operator*=(Rhs const& rhs)
		{
			return *this = *this * rhs;
		}
	};
}
namespace string
{
	namespace detail
	{
		struct substring
		{
			std::string const& str_;
			std::size_t start_;
			std::size_t size_;

			bool operator==(substring const& rhs)const
			{
				if (size_ != rhs.size_)
					return false;
				for (std::size_t i = 0;i < size_;++i)
				{
					if (rhs.str_[rhs.start_ + i] != str_[start_ + i])
						return false;
				}
				return true;
			}
			bool operator!=(substring const& rhs)const
			{
				return !(rhs.operator==(*this));
			}
			std::string str()const
			{
				return str_.substr(start_, size_);
			}
		};

		struct substring_iterator :std::iterator<std::input_iterator_tag, substring>
		{
			std::string const& str_;
			std::size_t start_;
			std::size_t size_;
			substring_iterator(std::string const& str, std::size_t start, std::size_t size) :str_(str), start_(start), size_(size) {}
			substring_iterator(substring_iterator&&) = default;
			substring_iterator(substring_iterator const&) = default;
			substring_iterator& operator=(substring_iterator&&) = default;
			substring_iterator& operator=(substring_iterator const&) = default;
			~substring_iterator() = default;

			substring_iterator& operator++()
			{
				++start_;
				return *this;
			}
			substring_iterator operator++(int)
			{
				auto ret = *this;
				++start_;
				return ret;
			}
			substring operator*()const
			{
				return substring{ str_,start_,size_ };
			}

			bool operator==(substring_iterator const& rhs)const
			{
				return &str_ == &str_ &&
					start_ == rhs.start_&&
					size_ == rhs.size_;
			}
			bool operator!=(substring_iterator const& rhs)const
			{
				return !rhs.operator==(*this);
			}
		};
	}
	class substring_adaptor
	{
		std::string const& str_;
		std::size_t size_;
	public:
		substring_adaptor(std::string const& str, std::size_t size) :str_(str), size_(size) {}
		substring_adaptor(substring_adaptor&&) = default;
		substring_adaptor(substring_adaptor const&) = default;
		substring_adaptor& operator=(substring_adaptor&&) = default;
		substring_adaptor& operator=(substring_adaptor const&) = default;
		~substring_adaptor() = default;

		detail::substring_iterator begin()const
		{
			if (str_.size() < size_)
				return detail::substring_iterator(str_, 0, 0);
			return detail::substring_iterator(str_, 0, size_);
		}
		detail::substring_iterator end()const
		{
			if (str_.size() < size_)
				return detail::substring_iterator(str_, 0, 0);
			return detail::substring_iterator(str_, str_.size() - size_ + 1, size_);
		}
	};
	
}
namespace geometry
{
	template<class Type>struct point
	{
		Type x, y;
	};
	template<class Type>auto make_point(Type x, Type y)
	{
		return point<Type>{x, y};
	}
	template<class Type>auto operator+(point<Type>const& lhs, point<Type>const& rhs)
	{
		return make_point(lhs.x + rhs.x, lhs.y + rhs.y);
	}
	template<class Type>auto operator-(point<Type>const& lhs, point<Type>const& rhs)
	{
		return make_point(lhs.x - rhs.x, lhs.y - rhs.y);
	}
	template<class Point>struct box
	{
		Point small, large;
	};
	template<class Point>auto make_box(Point a, Point b)
	{
		return box<Point>{
			make_point(std::min(a.x, b.x), std::min(a.y, b.y)),
			make_point(std::max(a.x, b.x), std::max(a.y, b.y))};
	}
#ifndef  PLASMA_NO_BOOST
	template<class Point>boost::optional<box<Point>> hit_check(box<Point> a, box<Point> b)
	{
		if (a.small.x > b.small.x)
			std::swap(a, b);
		if (a.large.x < b.small.x)
			return boost::none;
		auto small_x = b.small.x;
		auto large_x = std::min(b.large.x, a.large.x);
		if (a.small.y < b.small.y)
		{
			if (b.small.y < a.large.y)
				return make_box(
					make_point(small_x, b.small.y), 
					make_point(large_x, std::min(a.large.y, b.large.y)));
			else
				return boost::none;
		}
		else 
		{
			if (a.small.y < b.large.y)
				return make_box(
					make_point(small_x, a.small.y),
					make_point(large_x, std::min(a.large.y, b.large.y)));
			else
				return boost::none;
		}
	}
#endif
}
namespace iostream
{
	namespace detail
	{
		template<class T>std::enable_if_t<
			std::is_same<decltype(std::declval<T>().read()), void>::value,
			std::true_type> has_read(T const&);
		std::false_type has_read(...);
		template<class T>std::enable_if_t<
			std::is_same<decltype(std::cin >> std::declval<T&>()), std::istream&>::value,
			std::true_type> has_operator_bit_shift(T const&);
		std::false_type has_operator_bit_shift(...);
	}
	template<class T>struct has_read :
		decltype(detail::has_read(std::declval<T>()))
	{

	};
	template<class T>struct has_operator_bit_shift :
		decltype(detail::has_operator_bit_shift(std::declval<T>()))
	{

	};
	struct cin_t
	{
		template<class T>std::enable_if_t<
			has_read<T>::value,cin_t> 
			operator()(T& v)const
		{
			v.read();
			return *this;
		}
		template<class T>std::enable_if_t<
			has_operator_bit_shift<T>::value, cin_t>
			operator()(T& v)const
		{
			std::cin >> v;
			return *this;
		}
		template<class T>auto operator()(std::vector<T>& vec, uint64 size)const
		{
			vec.resize(size);
			for (auto& v : vec)
			{
				this->operator()(v);
			}
			return *this;
		}
	};
	const cin_t reader{};
	
	namespace detail
	{
		template<class T>std::enable_if_t<
			std::is_same<decltype(std::declval<T>().write()), void>::value,
			std::true_type> has_write(T const&);
		std::false_type has_write(...);
		template<class T>std::enable_if_t<
			std::is_same<decltype(std::cout << std::declval<T>()), std::ostream&>::value,
			std::true_type> has_operator_bit_shift2(T const&);
		std::false_type has_operator_bit_shift2(...);
	}
	template<class T>struct has_write :
		decltype(detail::has_write(std::declval<T>()))
	{

	};
	template<class T>struct has_operator_bit_shift2 :
		decltype(detail::has_operator_bit_shift2(std::declval<T>()))
	{

	};
	struct cout_t
	{
		template<class T>std::enable_if_t<has_write<T>::value, cout_t>operator()(T const& v)const
		{
			v.write();
			return *this;
		}
		template<class T>std::enable_if_t<has_operator_bit_shift2<T>::value, cout_t>operator()(T const& v)const
		{
			std::cout << v;
			return *this;
		}
		template<class T, class... Ts>cout_t operator()(T const& v, Ts const&... vs)const
		{
			this->operator()(v);
			std::cout << " ";
			return this->operator()(vs...);
		}
	};
	const cout_t print{};
	struct coutendl_t
	{
		template<class T>auto operator()(std::vector<T>const& vec)const
		{
			for (auto const& v : vec)
			{
				print(v);
				std::cout << "\n";
			}
			return *this;
		}
		template<class... Ts>coutendl_t operator()(Ts const&... vs)const
		{
			print(vs...);
			std::cout << "\n";
			return *this;
		}
	};
	const coutendl_t println{};
}
namespace graph_traits
{
	class graph
	{
		std::vector<int64> node_data;
		std::vector<std::vector<std::pair<int, int64>>> edge_data;
	public:
		graph() = default;
		graph(std::vector<int64>&& n) :node_data(std::move(n)), edge_data{} 
		{
			edge_data.resize(node_data.size());
		}
		graph(std::size_t size) :node_data(size), edge_data{}
		{

		}

		void resize(int size)
		{
			node_data.resize(size);
			edge_data.resize(size);
		}
		void edge_reserve(int size)
		{
			for (auto& v : edge_data)
			{
				v.reserve(size);
			}
		}

		void add_node(int64 data)
		{
			node_data.emplace_back(data);
			edge_data.emplace_back();
		}
		void add_edge(int from, int to, int64 data)
		{
			edge_data[from].emplace_back(to, data);
		}
		std::vector<math::infinite_value<int64>> dijkstra(int from)const
		{
			struct compare
			{
				bool operator()(
					std::pair<int, math::infinite_value<int64>>const& lhs,
					std::pair<int, math::infinite_value<int64>>const& rhs)const
				{
					return lhs.second > rhs.second;
				}
			};
			std::priority_queue<
				std::pair<int, math::infinite_value<int64>>,
				std::vector<std::pair<int, math::infinite_value<int64>>>,
				compare>nodes;
			std::vector<math::infinite_value<int64>> ret(node_data.size());
			for (int i{};i < node_data.size();++i)
			{
				nodes.emplace(i, math::infinite_value<int64>());
			}
			nodes.emplace(from, int());

			while (nodes.size())
			{
				auto p = nodes.top();
				nodes.pop();
				if (ret[p.first] <= p.second)
					continue;
				ret[p.first] = p.second;
				for (auto const& d : edge_data[p.first])
				{
					nodes.emplace(d.first, std::min(ret[d.first], ret[p.first] + d.second));
				}
			}
			return ret;
		}

		int64 operator[](int n)const
		{
			return node_data[n];
		}
	};
}


void Main(std::integral_constant<int, 1>);
void Main(std::integral_constant<int, 2>);
void Main(std::integral_constant<int, 3>);
void Main(std::integral_constant<int, 4>);
void Main(std::integral_constant<int, 5>);
#endif//??????????
//????????
constexpr int problem = 2;

//?????????
int main()
{
	std::cin.sync_with_stdio(false);
	std::cout << std::setprecision(std::numeric_limits<long double>::digits10 + 1);
	Main(std::integral_constant<int, problem>{});
}
using iostream::reader;
using iostream::print;
using iostream::println;

void Main(std::integral_constant<int, 1>)
{
	std::string str;
	std::string ret;
	std::cin >> str;
	for (int i{};i < str.size();++i)
	{
		if (str[i] >= '0'&&str[i] <= '9')
		{
			ret += str[i];
			if (i + 1 < str.size() && str[i + 1] >= '0'&&str[i + 1] <= '9')
			{
				ret += str[i + 1];
			}
			break;
		}
	}
	std::cout << ret << std::endl;
}

void Main(std::integral_constant<int, 2>)
{
	struct data_t
	{
		int X;
		int R;
		int H;
		void read()
		{
			std::cin >> X >> R >> H;
		}
	};
	struct query_t
	{
		int A;
		int B;
		void read()
		{
			std::cin >> A >> B;
		}
	};
	std::vector<data_t> datas;
	std::vector<query_t> querys;
	int N;
	std::cin >> N;
	int Q;
	std::cin >> Q;
	reader(datas, N);
	std::vector<double> size;
	for (auto const& d : datas)
	{
		size.emplace_back(d.R*d.R*d.H / 3.);
	}
	reader(querys, Q);
	for (auto const& q : querys)
	{
		double ret{};
		for (int i{};i < size.size();++i)
		{
			double a = std::max(std::min(datas[i].X + datas[i].H - q.A, datas[i].H), 0);
			double b = std::max(std::min(datas[i].X + datas[i].H - q.B, datas[i].H), 0);
			ret += (size[i] * math::pow(a / datas[i].H, 3) - size[i] * math::pow(b / datas[i].H, 3));
		}
		std::cout << ret*math::pi << std::endl;
	}
}

void Main(std::integral_constant<int, 3>)
{
	
}

void Main(std::integral_constant<int, 4>)
{

}

void Main(std::integral_constant<int, 5>)
{

}