#define NDEBUG
#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <array>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>
constexpr double PI = 3.1415926535897932;

using int32 = std::int_fast32_t;
using int64 = std::int_fast64_t;
using uint32 = std::uint_fast32_t;
using uint64 = std::uint_fast64_t;
using intl32 = std::int_least32_t;
using intl64 = std::int_least64_t;
using uintl32 = std::uint_least32_t;
using uintl64 = std::uint_least64_t;

void yes(bool c) { puts(c ? "yes" : "no"); }
void Yes(bool c) { puts(c ? "Yes" : "No"); }
void YES(bool c) { puts(c ? "YES" : "NO"); }
void pos(bool c) { puts(c ? "possible" : "impossible"); }
void Pos(bool c) { puts(c ? "Possible" : "Impossible"); }
void POS(bool c) { puts(c ? "POSSIBLE" : "IMPOSSIBLE"); }
template<class T>bool bmaxi(T&a, const T&b) { if (b<a)return 0;a = b;return 1; }
template<class T>bool bmini(T&a, const T&b) { if (a<b)return 0;a = b;return 1; }
template<class T>bool nmaxi(T&a, const T&b) { if (a<b) { a = b;return 1; }return 0; }
template<class T>bool nmini(T&a, const T&b) { if (b<a) { a = b;return 1; }return 0; }
template<typename T>auto scan(T&d)->typename std::enable_if<std::is_signed<T>::value>::type
{
	d = 0;int c = fgetc(stdin);bool f = 0;while (c<'0' || '9'<c) { if (c == '-')f = 1;c = fgetc(stdin); }
	while (c != ' '&&c != '\n') { d = d * 10 + c - '0';c = fgetc(stdin); }if (f)d = -d;
}
template<typename T>auto scan(T&d)->typename std::enable_if<!std::is_signed<T>::value>::type
{
	d = 0;int c = fgetc(stdin);while (c == ' ' || c == '\n')c = fgetc(stdin);
	while (c != ' '&&c != '\n') { d = d * 10 + c - '0';c = fgetc(stdin); }
}
void scan(char&d) { d = fgetc(stdin);while (d == ' ' || d == '\n')d = fgetc(stdin); }
void scan(double&d) { scanf("%lf", &d); }void scan(std::string&d) {
	d.clear();int c = fgetc(stdin);
	while (c == ' ' || c == '\n')c = fgetc(stdin);while (c != ' '&&c != '\n') { d.push_back(c);c = fgetc(stdin); }
}
template<typename F, typename...R>void scan(F&f, R&...r) { scan(f);scan(r...); }
template<typename T>T input() { T d;scan(d);return d; }
template <typename T>auto print(T d)->typename std::enable_if<std::is_signed<T>::value>::type
{
	static int c[20];int i = 0;bool f = 0;if (d<0) { f = 1;d = -d; }while (d) { c[i++] = d % 10;d /= 10; }
	if (!i)c[i++] = 0;if (f)fputc('-', stdout);while (i--)fputc(c[i] + '0', stdout);
}
template<typename T>auto print(T d)->typename std::enable_if<!std::is_signed<T>::value>::type
{
	static int c[20];int i = 0;while (d) { c[i++] = d % 10;d /= 10; }
	if (!i)c[i++] = 0;while (i--)fputc(c[i] + '0', stdout);
}
void print(const char d) { fputc(d, stdout); }void print(const double d) { printf("%f", d); }
void print(const char *c) { while (*c != '\0')fputc(*(c++), stdout); }
template<typename F, typename...R>void print(F f, R...r) { print(f);print(r...); }
template<typename...R>void println(R...r) { print(r...);fputc('\n', stdout); }

int main(void) {
	uint32 n, ans = 0;
	scan(n);
	std::vector<uint32> a(n), b(n), c(n), d(n);
	for (auto &x : a)scan(x);
	for (auto &x : b)scan(x);
	if (n & 1) {
		for (const auto x : a)ans ^= x;
		for (const auto x : b)ans ^= x;
	}
	for (auto &x : a)x = ~x;
	for (uint32 i = 0;i < 28;++i) {
		const uint32 pbit = (uint32)1 << i;
		uint32 midA = n, midB = n;
		for (const auto x : a) if (x&pbit)--midA;
		for (const auto x : b) if (x&pbit)--midB;
		uint32 lA = 0, lB = 0;
		for (const auto x : a)c[x & pbit ? midA++ : lA++] = x;
		for (const auto x : b)d[x & pbit ? midB++ : lB++] = x;
		std::swap(a, c);std::swap(b, d);
		lA = 0;lB = 0;
		const uint32 mask = (pbit << 1) - 1;
		while (lA < n) {
			while (lB < n && (a[lA] & mask) >= (b[lB] & mask)) ++lB;
			if (n - lB & 1)ans ^= pbit << 1;
			++lA;
		}
	}
	println(ans);
	return 0;
}