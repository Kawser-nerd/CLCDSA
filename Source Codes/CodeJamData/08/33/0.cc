/* GCJ'08
 * Author: Per Austrin
 *
 * (Treap code adapted from the Three-headed Monkey Treasure Trove (TM))
 */
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <algorithm>
//#include <string>
//#include <map>
//#include <vector>

using namespace std;
#define dprintf debug && printf
bool debug = false;
typedef long long ll;

void init() {
}

int seq[1000000], A[1000000];
int seqs[1000000], tail[1000000];
int n, m;
ll X, Y, Z;

const int MOD = 1000000007;


struct Tree {
  Tree *l, *r;
  int v;
  ll w;
  int prio;
  ll sz;

  Tree() : l(0), r(0), v(1<<30), w(0), prio(rand()), sz(0) { }
  Tree(int v, ll w) : l(0), r(0), v(v), w(w), prio(rand()), sz(w) { }
  ~Tree() { if (l) delete l; if (r) delete r; }

  Tree *rotateRight() {
    Tree *temp = l;
    l = l->r;
    temp->r = this;
    sz = (lsize() + rsize() + w) % MOD;
    temp->sz = (temp->lsize() + temp->rsize() + temp->w) % MOD;
    return temp;
  }

  Tree *rotateLeft() {
    Tree *temp = r;
    r = r->l;
    temp->l = this;
    sz = (lsize() + rsize() + w) % MOD;
    temp->sz = (temp->lsize() + temp->rsize() + temp->w) % MOD;
    return temp;
  }

  ll lsize() { return l ? l->size() : 0; }
  ll rsize() { return r ? r->size() : 0; }
  ll size() { return sz; }
};

struct Treap {

  ll insert(int v, ll w) {
    pair<ll, Tree *> ret = addnode(new Tree(v, w), root);
    root = ret.second;
    return ret.first;
  }

  ll get(int v) {
    return get(v, root);
  }

  ll get(int v, Tree *t) {
    if (!t) return 0;
    if (v <= t->v) return get(v, t->l);
    return (t->lsize() + t->w + get(v, t->r)) % MOD;
  }

  Treap() : root(0) { }

  ~Treap() {
    delete root;
  }


  pair<ll, Tree*> addnode(Tree *node, Tree *t) {
    ll ret = 0;

    if(t == 0) {
      return pair<ll, Tree*>(0, node);
    }

    (t->sz += node->sz) %= MOD;
    if(node->v < t->v) {
      pair<ll, Tree*> p = addnode(node, t->l);
      ret = p.first;
      t->l = p.second;
      if(t->prio > t->l->prio) {
	t = t->rotateRight();
      }
    } else {
      pair<ll, Tree*> p = addnode(node, t->r);
      ret = (t->lsize() + t->w + p.first) % MOD;
      t->r = p.second;
      if(t->prio > t->r->prio) {
	t = t->rotateLeft();
      }
    }
    return pair<ll, Tree*>(ret, t);
  }

private:
  Tree *root;
};


void solve(int P) {
  
  scanf("%d%d%lld%lld%lld", &n, &m, &X, &Y, &Z);

  for (int i = 0; i < m; ++i) scanf("%d", A+i);

  for (int i = 0; i < n; ++i) {
    seq[i] = A[i % m];
    A[i % m] = (X * A[i % m] + Y * (i+1)) % Z;
  }

  memset(seqs, 0, sizeof(seqs));
  

  int L = 0;
  Treap T;

  for (int i = 0; i < n; ++i) {
    int v = (T.get(seq[i]) + 1) % MOD;
    T.insert(seq[i], v);
    (L += v) %= MOD;
  }

  printf("Case #%d: %d\n", P, L);
  fprintf(stderr, "Case #%d: %d\n", P, L);
}

int main() {
  int n;
  scanf("%d", &n);
  init();
  for (int i = 1; i <= n; ++i) solve(i);
  return 0;
}

