#ifndef GATILOV_INTEGER_LONG_ARITHMETICS_192768
#define GATILOV_INTEGER_LONG_ARITHMETICS_192768

#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
#undef min
#undef max

#define USE_INT64

class LongInteger {
public:
    typedef LongInteger Lint;
#ifdef USE_INT64
	typedef long long int64;
	static const int DIGITS = 9;
	static const int BASE = 1000000000;
#else
	typedef int int64;
	static const int DIGITS = 4;
	static const int BASE = 10000;
#endif

	char sign;			// (-1 / 0 / 1)
	std::vector<int> arr;

    inline const int &operator[] (int ind) const { return arr[ind]; }
	inline int &operator[] (int ind) { return arr[ind]; }

	inline void CutTrailingZeros();
	inline int UnsignedCompare(const Lint &other) const;
	inline void UnsignedAdd(const Lint &base, const Lint &other);
	inline void UnsignedSub(const Lint &base, const Lint &other);
	inline void AddSub(const Lint &other, char othersign);

	inline void ShiftSub(const Lint &other, int shift);
	inline bool ShiftNotLess(const Lint &other, int shift) const;
	inline double GetDoubleApprox(int level) const;
	
	inline void PureMultDigit(const Lint &base, int digit);
	inline int PureDivideDigit(const Lint &base, int digit);

	template<class T> inline const T DullConverter() const;
	template<class T> inline void DullConstructor(T x);
	static int ScanDigit(const char *s, const char *t);

public:
	inline LongInteger() : sign(0), arr() {}
	inline LongInteger(const LongInteger &x) : sign(x.sign), arr(x.arr) {}
	inline LongInteger &operator= (const Lint &x) { sign = x.sign;  arr = x.arr;  return *this; }
	inline operator int() const { return DullConverter<int>(); }
	inline operator long long() const { return DullConverter<long long>(); }
	inline operator double() const { return DullConverter<double>(); }
	inline LongInteger(int x) { DullConstructor<int>(x); }
	inline LongInteger(long long x) { DullConstructor<long long>(x); }

	inline int Compare(const Lint &other) const;
	inline const Lint operator<< (int digs) const;
	inline const Lint operator>> (int digs) const;
	inline Lint &operator+= (const Lint &other) { AddSub(other,  other.sign);  return *this; }
	inline Lint &operator-= (const Lint &other) { AddSub(other, -other.sign);  return *this; }
	inline void operator++ () { *this += 1; }
	inline void operator-- () { *this -= 1; }
	inline void operator++ (int) { *this += 1; }
	inline void operator-- (int) { *this -= 1; }
	inline void Divide(const Lint &other, Lint &div, Lint &rem) const;
	inline const Lint operator* (const Lint &other) const;
	inline const Lint operator/ (const Lint &other) const { Lint div, rem;  Divide(other, div, rem);  return div; }
	inline const Lint operator% (const Lint &other) const { Lint div, rem;  Divide(other, div, rem);  return rem; }
	inline Lint &operator*= (int other);
	inline Lint &operator/= (int other);
	inline int operator% (int other) const;
	inline Lint SquareRoot() const;

	inline int GetSign() const { return sign; }
	inline Lint &Negate() { sign = -sign;   return *this; }
	inline Lint &Absolute() { if (sign < 0) sign = -sign;  return *this; }
	inline const Lint operator- () const { return Lint(*this).Negate(); }

	inline bool operator< (const Lint &other) const { return Compare(other) < 0; }
	inline bool operator> (const Lint &other) const { return Compare(other) > 0; }
	inline bool operator== (const Lint &other) const { return Compare(other) == 0; }
	inline bool operator<= (const Lint &other) const { return Compare(other) <= 0; }
	inline bool operator>= (const Lint &other) const { return Compare(other) >= 0; }
	inline bool operator!= (const Lint &other) const { return Compare(other) != 0; }
	inline Lint &operator<<= (int digs) { *this = *this << digs;  return *this; }
	inline Lint &operator>>= (int digs) { *this = *this >> digs;  return *this; }
	inline const Lint operator+ (const Lint &other) const { return Lint(*this) += other; }
	inline const Lint operator- (const Lint &other) const { return Lint(*this) -= other; }
	inline Lint &operator*= (const Lint &other) { *this = *this * other;  return *this; }
	inline Lint &operator/= (const Lint &other) { *this = *this / other;  return *this; }
	inline Lint &operator%= (const Lint &other) { *this = *this % other;  return *this; }
	inline const Lint operator* (int other) const { return Lint(*this) *= other; }
	inline const Lint operator/ (int other) const { return Lint(*this) /= other; }
	inline Lint &operator%= (int other) { *this = *this % other;  return *this; }

	inline operator std::string() const;
	inline LongInteger(const std::string &s);
	inline void Print(FILE *f = stdout) const;
	inline void Scan(FILE *f = stdin);
	friend inline void swap(LongInteger &a, LongInteger &b);
};

namespace std {
	inline const LongInteger abs(const LongInteger &f) {
		return LongInteger(f).Absolute();
	}
	inline void swap(LongInteger &a, LongInteger &b) {
		std::swap(a.sign, b.sign);
		std::swap(a.arr, b.arr);
	}
};


//Implementation
inline const LongInteger LongInteger::operator<< (int digs) const {
	assert(digs >= 0);
	if (sign == 0) return Lint();
	Lint res;
	res.sign = sign;
	res.arr.resize(arr.size() + digs);
	int i;
	for (i = res.arr.size()-1; i-digs>=0; i--) res.arr[i] = arr[i-digs];
	for (; i>=0; i--) res.arr[i] = 0;
	return res;
}

inline const LongInteger LongInteger::operator>> (int digs) const {
	assert(digs >= 0);
	if (sign == 0 || arr.size() < digs) return Lint();
	Lint res;
	res.sign = sign;
	res.arr.resize(arr.size() - digs);
	int i;
	for (i = 0; i<res.arr.size(); i++) res.arr[i] = arr[i+digs];
	return res;
}

inline void LongInteger::CutTrailingZeros() {
	while (arr.size() && !arr.back()) arr.pop_back();
	if (arr.empty()) sign = 0;
}

inline int LongInteger::UnsignedCompare(const Lint &other) const {
	if (arr.size() != other.arr.size()) return (arr.size() < other.arr.size() ? -1 : 1);
	for (int i = arr.size()-1; i>=0; i--)
		if (arr[i] != other[i])
			return (arr[i] < other[i] ? -1 : 1);
	return 0;
}

inline void LongInteger::UnsignedAdd(const Lint &base, const Lint &other) {
	int buff = 0;
	int sz = std::max(base.arr.size(), other.arr.size());
	arr.resize(sz);
	for (int i = 0; i<sz; i++) {
		arr[i] = (i<base.arr.size() ? base[i] : 0) + (i<other.arr.size() ? other[i] : 0) + buff;
		if (arr[i] >= BASE) {
			arr[i] -= BASE;
			buff = 1;
		}
		else buff = 0;
	}
	if (buff) arr.push_back(buff);
}

inline void LongInteger::UnsignedSub(const Lint &base, const Lint &other) {
	int buff = 0;
	assert(base.arr.size() >= other.arr.size());
	int sz = base.arr.size();
	arr.resize(sz);
	for (int i = 0; i<sz; i++) {
		arr[i] = base[i] - (i<other.arr.size() ? other[i] : 0) - buff;
		if (arr[i] < 0) {
			arr[i] += BASE;
			buff = 1;
		}
		else buff = 0;
	}
	assert(!buff);
	CutTrailingZeros();
}

inline void LongInteger::AddSub(const Lint &other, char othersign) {
	if (othersign == 0) return;
	if (sign == 0) {
		*this = other;
		sign = othersign;
		return;
	}
	if (sign == othersign) {
		UnsignedAdd(*this, other);
		return;
	}
	int t = UnsignedCompare(other);
	if (t==0) { *this = 0;  arr.clear(); }
	else {
		if (t>0) UnsignedSub(*this, other);
		else {
			UnsignedSub(other, *this);
			sign = othersign;
		}
	}
}

inline void LongInteger::PureMultDigit(const Lint &base, int digit) {
	int64 buff = 0;
	int sz = base.arr.size();
	arr.resize(sz + 1);
	for (int i = 0; i<sz; i++) {
		buff += int64(base[i]) * digit;
		arr[i] = buff % BASE;
		buff /= BASE;
	}
	arr[sz] = buff;
	CutTrailingZeros();
}

inline int LongInteger::PureDivideDigit(const Lint &base, int digit) {
	assert(digit);
	int64 buff = 0;
	arr.resize(base.arr.size());
	for (int i = base.arr.size()-1; i>=0; i--) {
		buff *= BASE;
		buff += base[i];
		arr[i] = buff / digit;
		buff %= digit;
	}
	CutTrailingZeros();
	return buff;
}

inline LongInteger &LongInteger::operator*= (int other) {
	int sgn = (other ? (other<0 ? -1 : 1) : 0);
	sign *= sgn;
	if (sign == 0) return *this;
	other *= sgn;
	if (other < BASE) PureMultDigit(*this, other);
	else *this *= Lint(other);
	return *this;
}

inline LongInteger &LongInteger::operator/= (int other) {
	int sgn = (other ? (other<0 ? -1 : 1) : 0);
	assert(sgn);
	sign *= sgn;
	if (sign == 0) return *this;
	other *= sgn;
	if (other < BASE) PureDivideDigit(*this, other);
	else *this /= Lint(other);
	return *this;
}

inline int LongInteger::operator% (int other) const {
	int sgn = (other ? (other<0 ? -1 : 1) : 0);
	assert(sgn);
	if (sign == 0) return 0;
	other *= sgn;
	if (other < BASE) {
		Lint temp;
		return sign * temp.PureDivideDigit(*this, other);
	}
	else {
		other *= sgn;
		return *this % Lint(other);
	}
}

inline const LongInteger LongInteger::operator* (const Lint &other) const {
	static const int TIMES = 9;
	Lint res;
	res.sign = sign * other.sign;
	if (res.sign == 0) return res;

	int tsz = arr.size();
	int osz = other.arr.size();
	int rsz = tsz + osz;
	res.arr.resize(rsz);

	int64 buff, mega;
	mega = 0;
	for (int i = 0; i<rsz; i++) {
		int cnt = 0;
		buff = mega;
		mega = 0;
		for (int j = std::max(0, i-osz+1); j<=std::min(i, tsz-1); j++) {
			buff += int64(arr[j]) * other[i-j];
			if ((++cnt) == TIMES) {
				mega += buff / BASE;
				buff %= BASE;
				cnt = 0;
			}
		}
		mega += buff / BASE;
		res.arr[i] = buff % BASE;
	}
	assert(mega == 0);
	res.CutTrailingZeros();
	return res;
}

inline bool LongInteger::ShiftNotLess(const Lint &other, int shift) const {
	if (arr.size() != other.arr.size() + shift) return (arr.size() >= other.arr.size() + shift);
	for (int i = arr.size()-1; i>=shift; i--)
		if (arr[i] != other[i-shift])
			return arr[i] >= other[i-shift];
	return true;
}
inline void LongInteger::ShiftSub(const Lint &other, int shift) {
	int buff = 0;
	assert(other.sign == 0 || arr.size() >= other.arr.size() + shift);
	int sz = arr.size();
	for (int i = shift; i<sz; i++) {
		arr[i] -= (i-shift < other.arr.size() ? other[i-shift] : 0) + buff;
		if (arr[i] < 0) {
			arr[i] += BASE;
			buff = 1;
		}
		else buff = 0;
	}
	assert(!buff);
	CutTrailingZeros();
}
/*inline void LongInteger::Divide(const Lint &other, Lint &div, Lint &rem) const {		//variant with binary search
	assert(other.sign);
	int tsz = arr.size();
	int osz = other.arr.size();
	if (sign == 0 || tsz < osz) {
		div = Lint();	//zero
		rem = *this;
		return;
	}

	div.arr.resize(tsz - osz + 1);
	Lint ost = *this;
	for (int i = tsz - osz; i>=0; i--) {
		int left = 0;
		int right = BASE;
		int middle;
		Lint tmult;
		while (right - left > 1) {
			middle = (left + right) >> 1;
			Lint tmult;
			tmult.PureMultDigit(other, middle);
			if (ost.ShiftNotLess(tmult, i)) left = middle;
			else right = middle;
		}
		div[i] = left;
		tmult.PureMultDigit(other, left);
		ost.ShiftSub(tmult, i);
	}
	rem = ost;

	div.sign = sign * other.sign;
	rem.sign = sign;
	div.CutTrailingZeros();
	rem.CutTrailingZeros();
}*/
inline double LongInteger::GetDoubleApprox(int level) const {
	double res = 0.0;
	for (int j = arr.size() - 1; j>=level; j--) {
		res *= BASE;
		if (j >= 0) res += arr[j];
	}
	return res;
}
inline void LongInteger::Divide(const Lint &other, Lint &div, Lint &rem) const {
	static const double EPS = std::max(3.0 / BASE, 1e-15 * BASE);
	assert(other.sign);
	int tsz = arr.size();
	int osz = other.arr.size();
	if (sign == 0 || tsz < osz) {
		div = Lint();	//zero
		rem = *this;
		return;
	}

	div.arr.resize(tsz - osz + 1);
	Lint ost = *this;
	double dother = other.GetDoubleApprox(osz - 3);
	for (int i = tsz - osz; i>=0; i--) {
		double dcurr = ost.GetDoubleApprox(i + osz - 3) / dother;
		int curr = int(dcurr);
		double diff = dcurr - curr;

		bool canbeless = (diff<EPS && curr>0);
		bool canbegreater = (diff>1.0-EPS && curr<BASE-1);

		Lint tmult;
		tmult.sign = 1;
		if (canbegreater) curr++;
		tmult.PureMultDigit(other, curr);
		if ((canbegreater || canbeless) && !ost.ShiftNotLess(tmult, i)) {
			curr--;
			tmult.UnsignedSub(tmult, other);
		}
		div[i] = curr;
		ost.ShiftSub(tmult, i);
	}
	rem = ost;

	div.sign = sign * other.sign;
	rem.sign = sign;
	div.CutTrailingZeros();
	rem.CutTrailingZeros();
}

inline LongInteger LongInteger::SquareRoot() const {
	static const int LOGBASE2 = int(log(double(BASE))/log(2.0) / 2) + 1;
	assert(sign >= 0);
	if (sign == 0) return Lint();
	Lint left, right, middle;
	Lint lsqr, rsqr, msqr, prod;
	int power = arr.size() + 1;
	right = 1;
	for (int i = 0; i<power; i++) right *= (1<<LOGBASE2);
	rsqr = right*right;
	while (right - left > Lint(1)) {
		middle = (left + right) / 2;
		msqr = (lsqr + prod + rsqr) / 4;
		if (*this < msqr) {
			right = middle;
			rsqr = msqr;
			prod /= 2;
			prod += lsqr;
		}
		else {
			left = middle;
			lsqr = msqr;
			prod /= 2;
			prod += rsqr;
		}
	}
	return left;
}

inline int LongInteger::Compare(const Lint &other) const {
	if (sign != other.sign) return (sign < other.sign ? -1 : 1);
	if (sign == 0) return 0;
	return sign * UnsignedCompare(other);
}

template<class T> inline const T LongInteger::DullConverter() const {
	T res = 0;
	if (sign == 0) return res;
	for (int i = arr.size()-1; i>=0; i--) {
		res *= BASE;
		res += arr[i];
	}
	return res * sign;
}

template<class T> inline void LongInteger::DullConstructor(T x) {
	if (x == T(0)) { sign = 0;  return; }
	if (x < T(0)) {
		sign = -1;
		x = -x;
	}
	else sign = 1;

	if (x < T(BASE)) arr.push_back(x);
	else {
		while (x != T(0)) {
			arr.push_back(x % BASE);
			x /= BASE;
		}
	}
}

inline LongInteger::operator std::string() const {
	if (sign == 0) return "0";
	std::string res;
	char buff[32];
	if (sign < 0) res += "-";
    sprintf(buff, "%d", arr.back());
    res += buff;

    char mask[] = "%00d";  mask[2] += DIGITS;
    for (int i = arr.size() - 2; i>=0; i--) {
		sprintf(buff, mask, arr[i]);
		res += buff;
    }
    return res;
}

int LongInteger::ScanDigit(const char *s, const char *t) {
	int l = t-s;
	int res = 0;
	for (int i = 0; i<l; i++) {
		res *= 10;
		res += (s[i]-'0');
	}
	return res;
}
inline LongInteger::LongInteger(const std::string &s) {
	const char *str = s.c_str();
	int curr = 0;
	if (str[curr] == '-') {
		sign = -1;
		curr++;
	}
	else sign = 1;

	int digits = (s.size() - curr - 1) / DIGITS;
	int first = (s.size() - curr - 1) % DIGITS + 1;
	arr.resize(digits + 1);
	arr[digits] = ScanDigit(str + curr, str + curr+first);
	curr += first;
	for (int i = digits-1; i>=0; i--) {
		arr[i] = ScanDigit(str + curr, str + curr + DIGITS);
		curr += DIGITS;
	}
	assert(curr == s.size());
	CutTrailingZeros();
}

inline void LongInteger::Print(FILE *f) const {
	std::string s = std::string(*this);
	fprintf(f, "%s\n", s.c_str());
}

inline void LongInteger::Scan(FILE *f) {
	std::string str;
	fscanf(f, " ");
	int curr;
	while (1) {
		curr = fgetc(f);
		if (curr == EOF) break;
		if (isspace(curr)) {
			ungetc(curr, f);
			break;
		}
		str += curr;
	}
	*this = Lint(str);
}

#endif
