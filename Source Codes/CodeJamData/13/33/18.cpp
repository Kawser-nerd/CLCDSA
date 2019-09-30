#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <stdint.h>
#include <map>
#include <queue>

using namespace std;

typedef int64_t ll;

const int add = 200000000, m = 2 * add + 1, days = 676070;

struct attack {
  int l, r, s;

  attack(int l, int r, int s) :
    l(l), r(r), s(s)
  { }
};

struct node {
  node * l, * r;
  int min_value, push;

  node() :
    l(0), r(0), min_value(0), push(0)
  { }

  node(node * o) :
   l(o ? o->l : 0), r(o ? o->r : 0), min_value(o ? o->min_value : 0), push(o ? o->push : 0)
   { }
};

const int inf = 1e9;

void do_push(node * v) {
  if(v->push != 0) {
    if(!v->l)
      v->l = new node();
    if(!v->r)
      v->r = new node();

    if(v->l->min_value < v->push) {
      v->l->min_value = v->l->push = v->push;
    }

    if(v->r->min_value < v->push) {
      v->r->min_value = v->r->push = v->push;
    }
  }
}

node * do_push_with_create(node * v) {
  v = new node(v);

  if(v->push != 0) {
    if(!v->l)
      v->l = new node();
    if(!v->r)
      v->r = new node();

    if(v->l->min_value < v->push) {
      v->l = new node(v->l);
      v->l->min_value = v->l->push = v->push;
    }

    if(v->r->min_value < v->push) {
      v->r = new node(v->r);
      v->r->min_value = v->r->push = v->push;
    }
  }

  return v;
}

int get_min(node * v, int l, int r, int tl, int tr) {
  if(tl > tr)
    return inf;
  else if(!v)
    return 0;
  else if(l == tl && r == tr)
    return v->min_value;

  do_push(v);

  int m = (l + r) >> 1;

  return min(get_min(v->l, l, m, tl, min(tr, m)), get_min(v->r, m + 1, r, max(m + 1, tl), tr));
}

int get_value(node * v) {
  return !v ? 0 : v->min_value;
}

node * do_update(node * v, int l, int r, int tl, int tr, int new_value) {
  if(tl > tr)
    assert(false);

  int m = (l + r) >> 1;

  v = do_push_with_create(v);

  if(tl == l && tr == r) {
    if(v->min_value < new_value) {
      v->min_value = v->push = new_value;
    }
  } else {
    if(tl <= m)
      v->l = do_update(v->l, l, m, tl, min(tr, m), new_value);

    if(tr > m)
      v->r = do_update(v->r, m + 1, r, max(m + 1, tl), tr, new_value);

    v->min_value = min(get_value(v->l), get_value(v->r));
  }


  return v;
}

int solve(bool need) {
  int n;
  cin >> n;

  vector < vector < attack > > attacks(days);

  for(int i = 0; i < n; i++) {
    int start_day, number_attack, l, r, s, delta_d, delta_p, delta_s;

    cin >> start_day >> number_attack >> l >> r >> s >> delta_d >> delta_p >> delta_s;

    l += add;
    r += add;

    for(int j = 0; j < number_attack; j++) {
      assert(l >= 0 && l < m && r >= 0 && r < m && l < r);

      attacks[start_day].push_back(attack(l, r - 1, s));

      start_day += delta_d;
      l += delta_p;
      r += delta_p;
      s += delta_s;
    }
  }

  int res = 0;

  node * root = 0;

  if(need) {
  for(int day = 0; day < days; day++) {
    if(attacks[day].size() > 0) {
      node * new_root = root;

      for(vector < attack > :: const_iterator it = attacks[day].begin(); it != attacks[day].end(); ++it) {
        const attack& a = *it;

        if(get_min(root, 0, m - 1, a.l, a.r) < a.s)
          ++res;

        new_root = do_update(new_root, 0, m - 1, a.l, a.r, a.s);
      }

      root = new_root;
    }
  }
}



  return res;
}

int main() {
  int tests;
  cin >> tests;

  for(int i = 1; i <= tests; i++) {
    cout << "Case #" << i << ": " << solve(i >= 10) << endl;
  }

  return 0;
}