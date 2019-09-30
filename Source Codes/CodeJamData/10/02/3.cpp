#include "cassert"
#include "climits"
#include "cmath"
#include "cstdio"
#include "algorithm"
#include "map"
#include "numeric"
#include "queue"
#include "set"
#include "stack"
#include "string"
#include "utility"
#include "vector"
using namespace std;
typedef long long i64;

////////////////////////////////////////////////////////////////////////////////
struct BigInteger {
  vector<int> digits;
  static const int BASE, DIGITS;
  BigInteger(int value = 0);
  BigInteger(const char* str);
  int get(int k) const;
  void set(int k, int value);
  void normalize();
  string toString() const;
};
const int BigInteger::BASE = 10000;
const int BigInteger::DIGITS = 4;

BigInteger::BigInteger(int value) {
  for (; value > 0; value /= BASE)
    digits.push_back(value % BASE);
}
BigInteger::BigInteger(const char* str) {
  char buffer[DIGITS + 1]; memset(buffer, '\0', sizeof(buffer));
  for (int length = (int)strlen(str); length > 0; length -= DIGITS) {
    const int digitSize = min(DIGITS, length);
    memcpy(buffer, &str[length - digitSize], digitSize * sizeof(char));
    buffer[digitSize] = '\0';
    digits.push_back(atoi(buffer));
  }
  normalize();
}
int BigInteger::get(int k) const {
  if (k >= (int)digits.size()) return 0;
  else return digits[k];
}
void BigInteger::set(int k, int value) {
  if (k >= (int)digits.size()) digits.resize(k + 1, 0);
  digits[k] = value;
}
void BigInteger::normalize() {
  while (!digits.empty() && digits.back() == 0)
    digits.pop_back();
}
string BigInteger::toString() const {
  if (digits.empty()) return string("0", 1);
  char buffer[DIGITS + 1];
  const int length = sprintf(buffer, "%d", digits.back());
  string str(buffer, length);
  for (int k = (int)digits.size() - 2; k >= 0; --k) {
    sprintf(buffer, "%0*d", DIGITS, digits[k]);
    str.append(buffer, DIGITS);
  }
  return str;
}
BigInteger operator <<(const BigInteger& b1, int offset) {
  BigInteger b2; b2.digits.insert(b2.digits.end(), offset, 0);
  b2.digits.insert(b2.digits.end(), b1.digits.begin(), b1.digits.end());
  b2.normalize(); return b2;
}
BigInteger& operator <<=(BigInteger& b1, int offset) {
  b1.digits.insert(b1.digits.begin(), offset, 0);
  b1.normalize(); return b1;
}
BigInteger operator >>(const BigInteger& b1, int offset) {
  BigInteger b2; if (offset < (int)b1.digits.size())
    b2.digits.insert(b2.digits.begin(), b1.digits.begin() + offset, b1.digits.end());
  return b2;
}
BigInteger operator >>=(BigInteger& b1, int offset) {
  if ((int)b1.digits.size() <= offset) b1.digits.clear();
  else b1.digits.erase(b1.digits.begin(), b1.digits.begin() + offset);
  return b1;
}
bool operator <(const BigInteger& b1, const BigInteger& b2) {
  if (b1.digits.size() < b2.digits.size()) return true;
  if (b2.digits.size() < b1.digits.size()) return false;
  for (int k = b1.digits.size() - 1; k >= 0; --k) {
    if (b1.digits[k] < b2.digits[k]) return true;
    if (b2.digits[k] < b1.digits[k]) return false;
  }
  return false;
}
bool operator >(const BigInteger& b1, const BigInteger& b2) {return b2 < b1;}
bool operator <=(const BigInteger& b1, const BigInteger& b2) {return !(b2 < b1);}
bool operator >=(const BigInteger& b1, const BigInteger& b2) {return !(b1 < b2);}
bool operator ==(const BigInteger& b1, const BigInteger& b2) {return b1.digits == b2.digits;}
bool operator !=(const BigInteger& b1, const BigInteger& b2) {return !(b1 == b2);}

BigInteger operator +(const BigInteger& b1, const BigInteger& b2) {
  BigInteger b3; int carry = 0;
  for (int k = 0; carry > 0 || k < (int)b1.digits.size() || k < (int)b2.digits.size(); ++k) {
    const int value = b1.get(k) + b2.get(k) + carry;
    b3.digits.push_back(value % BigInteger::BASE);
    carry = value / BigInteger::BASE;
  }
  return b3;
}
BigInteger& operator +=(BigInteger& b1, const BigInteger& b2) {
  int carry = 0;
  for (int k = 0; carry > 0 || k < (int)b2.digits.size(); ++k) {
    const int value = b1.get(k) + b2.get(k) + carry;
    b1.set(k, value % BigInteger::BASE);
    carry = value / BigInteger::BASE;
  }
  return b1;
}
BigInteger operator -(const BigInteger& b1, const BigInteger& b2) {
  BigInteger b3; int borrow = 0;
  for (int k = 0; k < (int)b1.digits.size() || k < (int)b2.digits.size(); ++k) {
    const int value = BigInteger::BASE + b1.get(k) - b2.get(k) - borrow;
    b3.digits.push_back(value % BigInteger::BASE);
    borrow = 1 - value / BigInteger::BASE;
  }
  return b3.normalize(), b3;
}
BigInteger& operator -=(BigInteger& b1, const BigInteger& b2) {
  int borrow = 0;
  for (int k = 0; k < (int)b1.digits.size() || k < (int)b2.digits.size(); ++k) {
    const int value = BigInteger::BASE + b1.get(k) - b2.get(k) - borrow;
    b1.set(k, value % BigInteger::BASE);
    borrow = 1 - value / BigInteger::BASE;
  }
  return b1.normalize(), b1;
}
BigInteger operator *(const BigInteger& b1, int X) {
  BigInteger b2; int carry = 0;
  for (int k = 0; k < (int)b1.digits.size(); ++k) {
    const int value = b1.digits[k] * X + carry;
    b2.digits.push_back(value % BigInteger::BASE);
    carry = value / BigInteger::BASE;
  }
  if (carry > 0) b2.digits.push_back(carry);
  return b2.normalize(), b2;
}
BigInteger& operator *=(BigInteger& b1, int X) {
  int carry = 0;
  for (int k = 0; k < (int)b1.digits.size(); ++k) {
    const int value = b1.digits[k] * X + carry;
    b1.digits[k] = value % BigInteger::BASE;
    carry = value / BigInteger::BASE;
  }
  if (carry > 0) b1.digits.push_back(carry);
  return b1.normalize(), b1;
}
BigInteger operator *(const BigInteger& b1, const BigInteger& b2) {
  BigInteger b3;
  for (int k = 0; k < (int)b2.digits.size(); ++k)
    b3 += (b1 * b2.digits[k]) << k;
  return b3;
}

BigInteger operator *=(BigInteger& b1, const BigInteger& b2) {
  BigInteger b3;
  for (int k = 0; k < (int)b2.digits.size(); ++k)
    b3 += (b1 * b2.digits[k]) << k;
  return b1 = b3;
}

BigInteger operator /(const BigInteger& b1, int X) {
  assert(X > 0);
  BigInteger b2; b2.digits.resize(b1.digits.size());
  for (int k = (int)b1.digits.size() - 1, carry = 0; k >= 0; --k) {
    carry = carry * BigInteger::BASE + b1.digits[k];
    b2.digits[k] = carry / X;
    carry %= X;
  }
  return b2.normalize(), b2;
}
BigInteger& operator /=(BigInteger& b1, int X) {
  assert(X > 0);
  for (int k = (int)b1.digits.size() - 1, carry = 0; k >= 0; --k) {
    carry = carry * BigInteger::BASE + b1.digits[k];
    b1.digits[k] = carry / X;
    carry %= X;
  }
  return b1.normalize(), b1;
}
int operator %(const BigInteger& b1, int X) {
  assert(X > 0);
  int carry = 0;
  for (int k = (int)b1.digits.size() - 1; k >= 0; --k)
    carry = (carry * BigInteger::BASE + b1.digits[k]) % X;
  return carry;
}
BigInteger& operator %=(BigInteger& b1, int X) {
  assert(X > 0);
  int carry = 0;
  for (int k = (int)b1.digits.size() - 1; k >= 0; --k)
    carry = (carry * BigInteger::BASE + b1.digits[k]) % X;
  b1.digits.resize(1); b1.digits[0] = carry;
  return b1.normalize(), b1;
}
BigInteger operator /(const BigInteger& b1, const BigInteger& b2) {
  assert(b2.digits.size() > 0);
  BigInteger b3, carry; b3.digits.resize(b1.digits.size());
  for (int k = (int)b1.digits.size() - 1; k >= 0; --k) {
    carry <<= 1; carry.set(0, b1.digits[k]);
    int lower = 0, upper = BigInteger::BASE;
    while (lower < upper) {
      const int middle = (lower + upper) / 2;
      if (b2 * middle <= carry) lower = middle + 1;
      else upper = middle;
    }
    b3.digits[k] = lower - 1;
    carry -= b2 * b3.digits[k];
  }
  return b3.normalize(), b3;
}
BigInteger operator /=(BigInteger& b1, const BigInteger& b2) {
  assert(b2.digits.size() > 0); BigInteger carry;
  for (int k = (int)b1.digits.size() - 1; k >= 0; --k) {
    carry <<= 1; carry.set(0, b1.digits[k]);
    int lower = 0, upper = BigInteger::BASE;
    while (lower < upper) {
      const int middle = (lower + upper) / 2;
      if (b2 * middle <= carry) lower = middle + 1;
      else upper = middle;
    }
    b1.digits[k] = lower - 1;
    carry -= b2 * b1.digits[k];
  }
  return b1.normalize(), b1;
}
BigInteger operator %(const BigInteger& b1, const BigInteger& b2) {
  assert((int)b2.digits.size() > 0); BigInteger carry;
  for (int k = (int)b1.digits.size() - 1; k >= 0; --k) {
    carry <<= 1; carry.set(0, b1.digits[k]);
    int lower = 0, upper = BigInteger::BASE;
    while (lower < upper) {
      const int middle = (lower + upper) / 2;
      if (b2 * middle <= carry) lower = middle + 1;
      else upper = middle;
    }
    carry -= b2 * (lower - 1);
  }
  return carry;
}
BigInteger operator %=(BigInteger& b1, const BigInteger& b2) {
  assert((int)b2.digits.size() > 0);
  BigInteger carry;
  for (int k = (int)b1.digits.size() - 1; k >= 0; --k) {
    carry <<= 1; carry.set(0, b1.digits[k]);
    int lower = 0, upper = BigInteger::BASE;
    while (lower < upper) {
      const int middle = (lower + upper) / 2;
      if (b2 * middle <= carry) lower = middle + 1;
      else upper = middle;
    }
    carry -= b2 * (lower - 1);
  }
  return b1 = carry, b1;
}
////////////////////////////////////////////////////////////////////////////////
template <class T>
T GCD(T a, T b) {
  if (b > a) swap(a, b);
  while (b != 0) {a %= b; swap(a, b);}
  return a == 0 ? 1 : a;
}
////////////////////////////////////////////////////////////////////////////////
const BigInteger ZERO(0);

int main() {
  int T; scanf("%d", &T);
  for (int Ti = 1; Ti <= T; ++Ti) {
    int n; scanf("%d", &n);
    vector<BigInteger> v;
    for (int i = 0; i < n; ++i) {
      static char str[100]; scanf("%s", str);
      v.push_back(BigInteger(str));
    }
    sort(v.begin(), v.end());
    BigInteger d = v[n - 1] - v[0];
    for (int i = 0; i < n - 1; ++i)
      for (int j = i + 1; j < n; ++j)
        d = GCD(d, v[j] - v[i]);
    BigInteger y = v[0] % d;
    if (y != ZERO) y = d - y;
    printf("Case #%d: %s\n", Ti, y.toString().c_str());
  }
  return 0;
}
