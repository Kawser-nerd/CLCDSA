#include <cstdio>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
using namespace std;

long long gen[600000];
long long tab[600000];

int heap[1200000];

int lson(int i) {
  return 2 * i;
}

int rson(int i) {
  return 2 * i + 1;
}

int parent(int i) {
  return i / 2;
}

const int mod = 1000000007;

void upheap(int i) {
  if (i == 1)
    return;

  heap[parent(i)] = (heap[lson(parent(i))] + heap[rson(parent(i))]) % mod;
  upheap(parent(i));
}

const int magic = (1 << 19);

int main() {
  int zz;
  scanf("%d", &zz);

  for (int z = 1; z <= zz; ++z) {
    int n, m, X, Y, Z;
    scanf("%d%d%d%d%d", &n, &m, &X, &Y, &Z);

    for (int i = 0; i < m; ++i) {
      scanf("%I64d", &gen[i]);
    }

    for (int i = 0; i < n; ++i) {
      tab[i] = gen[i % m];

      gen[i % m] = (X * gen[i % m] + (long long) Y * (i + 1)) % Z;
    }

    set<int> S;
    map<int, int> M;
    for (int i = 0; i < n; ++i)
      S.insert((int) tab[i]);

    int ii = 0;

    for (set<int>::iterator it = S.begin(); it != S.end(); ++it, ++ii) {
      M[*it] = ii;
    }

    for (int i = 0; i < n; ++i)
      tab[i] = M[tab[i]];

    for (int i = 0; i < 2 * magic; ++i)
      heap[i] = 0;

    int res = 0;

    for (int i = 0; i < n; ++i) {
      int smaller = 0;

      int cur = magic + tab[i];

      while (cur != 1) {
        if (cur == rson(parent(cur))) {
          smaller += heap[lson(parent(cur))];
          smaller %= mod;
        }

        cur = parent(cur);
      }

      heap[magic + tab[i]] += (smaller + 1);
      heap[magic + tab[i]] %= mod;
      upheap(magic + tab[i]);

      res += smaller + 1;
      res %= mod;
    }

    printf("Case #%d: %d\n", z, res);
  }

  return 0;
}