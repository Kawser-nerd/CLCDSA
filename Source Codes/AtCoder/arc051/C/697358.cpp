#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

#define SREP(s,i,m) for(unsigned int i = s; i < m; ++i)
#define REP(i,m) SREP(0,i,m)

using namespace std;
#ifdef _MSC_VER
using LONG = __int64;
#else
using LONG = long long int;
#endif

class Data {
public:
  LONG a; int t;

  bool operator<(const Data &left) const {
    return t != left.t ? t < left.t : a < left.a;
  }
};

int N, A, B;
vector<Data> darray;
const LONG DIVIDER = 1000000000 + 7;

void balance(void) {
  for (;;) {
    bool comp = true;
    sort(darray.begin(), darray.end());
    LONG max_a = darray[darray.size() - 1].a;
    if (max_a >= darray[0].a * A && B > 0) {
      darray[0].a *= A;
      B--;
    }
    else break;
  }
}

// b^e (mod m) ????
LONG modpow(LONG b, LONG e, LONG m) {
  LONG result = 1;
  while (e > 0) {
    if ((e & 1) == 1) result = (result * b) % m;
    e >>= 1;
    b = (b * b) % m;
  }
  return result;
}

int main(void) {
  cin >> N >> A >> B;
  darray.resize(N);
  REP(i, N) {
    cin >> darray[i].a;
    darray[i].t = 0;
  }
  if (A != 1) {
    balance();
    sort(darray.begin(), darray.end());
    int q, r;
    q = B / N;
    r = B % N;
    B = r;
    REP(i, N) darray[i].t += q;
    REP(i, B) {
      darray[i].t++;
    }
  }
  sort(darray.begin(), darray.end());

  REP(i, N) {
    cout << (((darray[i].a % DIVIDER) * (modpow(A, darray[i].t, DIVIDER))) % DIVIDER) << endl;
  }

  return 0;
}