#include <iostream>
#include <vector>
#include <cassert>

inline unsigned long long rot90(unsigned long long x) {
  return (x << 16) | (x >> 48);
}

inline bool same180(unsigned long long x) {
  return (x >> 32) == ((x << 32) >> 32);
}

inline bool same90(unsigned long long x) {
  return (x >> 48) == ((x << 48) >> 48);
}

inline void multi(unsigned long long side, long& cnt) {
  if (same180(side)) {
    cnt *= 2;
    if (same90(side)) {
      cnt *= 2;
    }
  }
}

inline unsigned long long get_min(unsigned long long a,
                                  unsigned long long b,
                                  unsigned long long c,
                                  unsigned long long d) {
  assert(a < (1 << 16));
  assert(b < (1 << 16));
  assert(c < (1 << 16));
  assert(d < (1 << 16));
  return std::min(
      {
          (a << 48) | (b << 32) | (c << 16) | d,
          (b << 48) | (c << 32) | (d << 16) | a,
          (c << 48) | (d << 32) | (a << 16) | b,
          (d << 48) | (a << 32) | (b << 16) | c
      }
  );
}

inline unsigned long long get0(unsigned long long x) { return x >> 48; }
inline unsigned long long get1(unsigned long long x) { return (x << 16) >> 48; }
inline unsigned long long get2(unsigned long long x) { return (x << 32) >> 48; }
inline unsigned long long get3(unsigned long long x) { return (x << 48) >> 48; }

int main() {
  unsigned N;
  std::cin >> N;
  std::vector<unsigned long long> tile(N);
  for (unsigned i = 0; i < N; ++i) {
    unsigned long long a, b, c, d;
    std::cin >> a >> b >> c >> d;
    tile[i] = get_min(a, b, c, d);
  }
  std::sort(tile.begin(), tile.end());
  unsigned long long ans = 0ull;
  for (auto p0 = tile.begin(); p0 < tile.end(); ++p0) {
    for (auto p1 = p0 + 1; p1 < tile.end(); ++p1) {
      //0
      unsigned long long x = *p0;
      unsigned long long y = *p1;
      unsigned long long a, b, c, d;
      auto yy = y;
      for (unsigned k = 0; k < 4; ++k) {
        a = get_min(get1(x), get0(x), get1(y), get0(y));
        b = get_min(get2(x), get1(x), get0(y), get3(y));
        c = get_min(get3(x), get2(x), get3(y), get2(y));
        d = get_min(get0(x), get3(x), get2(y), get1(y));
        auto s = std::upper_bound(p0 + 1, tile.end(), a) - std::lower_bound(p0 + 1, tile.end(), a);
        auto t = std::upper_bound(p0 + 1, tile.end(), b) - std::lower_bound(p0 + 1, tile.end(), b);
        auto q = std::upper_bound(p0 + 1, tile.end(), c) - std::lower_bound(p0 + 1, tile.end(), c);
        auto r = std::upper_bound(p0 + 1, tile.end(), d) - std::lower_bound(p0 + 1, tile.end(), d);
        if (yy == a) { --s; };
        if (yy == b) { --t; };
        if (a == b) { --t; };
        if (yy == c) { --q; };
        if (a == c) { --q; };
        if (b == c) { --q; };
        if (yy == d) { --r; };
        if (a == d) { --r; };
        if (b == d) { --r; };
        if (c == d) { --r; };
        multi(a, s);
        multi(b, t);
        multi(c, q);
        multi(d, r);
        ans += s * t * q * r;
        y = rot90(y);
      }
    }
  }
  std::cout << ans << std::endl;
}