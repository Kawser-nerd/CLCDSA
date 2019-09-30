#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long int LL;

const int MAX_S = 30;

LL gcd(LL a, LL b) {
  while (b) {
    a %= b; swap(a, b);
    }
  return a;
  }

struct ratio {
  LL num, den;
  ratio(LL num_ = 0, LL den_ = 1) : num(num_), den(den_) {
    if (den < 0) {
      num = -num;
      den = -den;
      }
    LL g = gcd(abs(num), abs(den));
    num /= g; den /= g;
    }
  };

ratio operator-(const ratio &p) { return ratio(-p.num, p.den); }
ratio operator+(const ratio &p, const ratio &q) { return ratio(p.num*q.den + q.num*p.den, p.den*q.den); }
ratio operator-(const ratio &p, const ratio &q) { return ratio(p.num*q.den - q.num*p.den, p.den*q.den); }
ratio operator*(const ratio &p, const ratio &q) { return ratio(p.num*q.num, p.den*q.den); }
ratio operator/(const ratio &p, const ratio &q) { return ratio(p.num*q.den, p.den*q.num); }

bool operator==(const ratio &p, const ratio &q) { return (p.num == q.num) && (p.den == q.den); }
bool operator<(const ratio &p, const ratio &q) { return p.num*q.den < q.num*p.den; }

ostream& operator<<(ostream &out, const ratio &p) { return out << p.num << '/' << p.den; }

ratio nextF(ratio t, int dt) {
  if (!dt) return ratio(1LL << 60);

  LL quot = ((dt > 0) ? (2*t.num + t.den) : (2*t.num - 1)) / t.den;
  return (ratio(quot, 2) - t) / dt;
  }

bool doReflect(const char room[MAX_S][MAX_S], const ratio &curX, const ratio &curY, int &dx, int &dy) {
  int rX, rY;
  if (curX.den == 1)
    rX = curX.num - (dx < 0);
  else
    rX = curX.num / curX.den;

  if (curY.den == 1)
    rY = curY.num - (dy < 0);
  else
    rY = curY.num / curY.den;

  if ((curX.den == 1) && (curY.den == 1)) {
    if (room[rX][rY] == '#') {
      int rpX = rX + ((dx > 0) ? -1 : 1);
      int rpY = rY + ((dy > 0) ? -1 : 1);
      bool mX = room[rpX][rY] == '#', mY = room[rX][rpY] == '#';

      if (!mX && !mY) return false;

      if (mX) dy = -dy;
      if (mY) dx = -dx;
      }
    }
  else if ((curX.den == 1) && (room[rX][rY] == '#'))
    dx = -dx;
  else if ((curY.den == 1) && (room[rX][rY] == '#'))
    dy = -dy;
  return true;
  }

int rayCast(const char room[MAX_S][MAX_S], int px, int py, int dx, int dy, int d) {
  ratio tx, ty, curX = ratio(1, 2) + px, curY = ratio(1, 2) + py;
  ratio stX = curX, stY = curY;

  while (!(d*d < tx*tx + ty*ty)) {
    if ((tx.num || ty.num) && ((curX == stX) && (curY == stY)))
      return 1;
    
    ratio f = min(nextF(curX, dx), nextF(curY, dy));

    tx = tx + f * abs(dx); ty = ty + f * abs(dy);
    curX = curX + f * dx; curY = curY + f * dy;

    if (!doReflect(room, curX, curY, dx, dy))
      return 0;
    }

  return 0;
  }

int main() {
  int nc; cin >> nc;
  for (int cur = 1; cur <= nc; ++cur) {
    int h, w, d; cin >> h >> w >> d;

    char room[MAX_S][MAX_S];
    int px, py;
    for (int i = 0; i < h; ++i)
      for (int j = 0; j < w; ++j) {
        cin >> room[i][j];
        if (room[i][j] == 'X') {
          px = i; py = j;
          }
        }

    int count = 0;
    for (int dx = 0; dx <= 2*d; ++dx)
      for (int dy = 0; (dx*dx + dy*dy <= 4*d*d); ++dy)
        if (gcd(dx, dy) == 1) {
          count += rayCast(room, px, py, dx, dy, d);
          if (dy) count += rayCast(room, px, py, dx, -dy, d);
          if (dx) count += rayCast(room, px, py, -dx, dy, d);
          if (dx && dy) count += rayCast(room, px, py, -dx, -dy, d);
          }

    cout << "Case #" << cur << ": " << count << '\n';
    }
  }
