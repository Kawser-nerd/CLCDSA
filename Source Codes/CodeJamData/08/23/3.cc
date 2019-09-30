// another fine solution by misof
// #includes {{{
#include <algorithm>
#include <numeric>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cassert>

#include <cmath>
#include <complex>
using namespace std;
// }}}

/////////////////// PRE-WRITTEN CODE FOLLOWS, LOOK DOWN FOR THE SOLUTION ////////////////////////////////

// pre-written code {{{
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);++i)
#define SIZE(t) ((int)((t).size()))
// }}}

/////////////////// CODE WRITTEN DURING THE COMPETITION FOLLOWS ////////////////////////////////

// {{{
template<class T> class __splayTree { public: __splayTree *left, *right, *up; T value; int count; int subtreeSize; __splayTree() { this->left = this->right = this->up = NULL; this->count=1; } void updateSubtreeSize() { this->subtreeSize=this->count; if (this->left) this->subtreeSize += (this->left)->subtreeSize; if (this->right) this->subtreeSize += (this->right)->subtreeSize; } };
template<class T> inline void __rotate(__splayTree<T> *t) { __splayTree<T> *p = t->up; if (!p) return; __splayTree<T> *g = p->up; int lp = ( ((p)->up) && (((p)->up)->left == (p)) ); if (( ((t)->up) && (((t)->up)->left == (t)) )) { __splayTree<T> *B = t->right; p->left = B; if (B) B->up = p; t->right = p; p->up = t; t->up = g; if (g) { if (lp) g->left = t; else g->right = t; } } else { __splayTree<T> *B = t->left; p->right = B; if (B) B->up = p; t->left = p; p->up = t; t->up = g; if (g) { if (lp) g->left = t; else g->right = t; } } p->updateSubtreeSize(); t->updateSubtreeSize(); }
template<class T> inline __splayTree<T> * __splay(__splayTree<T> *t, const T &x) { __splayTree<T> *v = t; while (1) { if ((v->value) == x) break; if ((v->value) > x) { if (v->left) v=v->left; else break; } else { if (v->right) v=v->right; else break; } } while (1) { if (!(v->up)) break; if (!((v->up)->up)) { __rotate(v); break; } __splayTree<T> *p = v->up; if (( ((v)->up) && (((v)->up)->left == (v)) ) == ( ((p)->up) && (((p)->up)->left == (p)) )) { __rotate(p); __rotate(v); } else { __rotate(v); __rotate(v); } } return v; }
template<class T> inline __splayTree<T> * __insert(__splayTree<T> *t, const T &x) { if (!t) { t = new __splayTree<T>(); t->value = x; t->updateSubtreeSize(); return t; } t = __splay(t,x); if (t->value == x) { t->count++; t->updateSubtreeSize(); return t; } __splayTree<T> *r = new __splayTree<T>(); r->value = x; if (x < t->value) { r->right = t; t->up = r; r->left = t->left; if (t->left) (t->left)->up = r; t->left = NULL; } else { r->left = t; t->up = r; r->right = t->right; if (t->right) (t->right)->up = r; t->right = NULL; } t->updateSubtreeSize(); r->updateSubtreeSize(); return r; }
template<class T> inline __splayTree<T> * __erase(__splayTree<T> *t, const T &x, bool all=false) { if (!t) return NULL; t = __splay(t,x); if (!(t->value == x)) return t; if (all) t->count=0; else t->count--; if (t->count) { t->updateSubtreeSize(); return t; } if (t->left) { __splayTree<T> *l = t->left; l->up = NULL; l = __splay(l,x); __splayTree<T> *r = t->right; if (r) r->up = l; l->right = r; delete(t); l->updateSubtreeSize(); return l; } else { __splayTree<T> *r = t->right; if (r) r->up = NULL; delete(t); return r; } } 
template<class T> inline T __kThElement(__splayTree<T> *t, int k) { while (1) { if (t==NULL) assert(false); if (t->left) { if (t->left->subtreeSize >= k) { t=t->left; continue; } k -= t->left->subtreeSize; } if (t->count >= k) return t->value; k -= t->count; t = t->right; } }
template<class T> inline void __toVector(__splayTree<T> *t, vector<T> &V) { if (!t) return; __toVector(t->left,V); for (int i=0; i<(t->count); i++) V.push_back(t->value); __toVector(t->right,V); }
// }}}

template<class T> class splayTree {
  __splayTree<T> *root;
  public:
    splayTree() { root = NULL; }
    inline void insert(const T &val) { root = __insert(root,val); }
    inline void erase(const T &val, bool all=false) { root = __erase(root,val,all); }
    inline T kThElement(int k) { return __kThElement(root,k); }
    inline T countLess(const T &val) { if (root == NULL) return 0; root = __splay(root,val); if (root->left == NULL) return 0; return (root->value < val ? root->count : 0) + root->left->subtreeSize; }
    inline int size() { return root == NULL ? 0 : root -> subtreeSize; }
    inline vector<T> toVector() { vector<T> res; __toVector(root,res); return res; } 
};

int main() {
  int T;
  cin >> T;
  FOR(t,1,T) {
    int K;
    cin >> K;
    splayTree<int> S;
    for (int i=0; i<K; i++) S.insert(i);
    int lastIndex = 1;
    vector<int> deck(K);
    for (int i=1; i<=K; i++) {
      int newIndex = (lastIndex + i - 1) % SIZE(S);
      if (newIndex == 0) newIndex = SIZE(S);
      int pos = S.kThElement(newIndex);
      S.erase(pos);
      deck[pos] = i;
      lastIndex = newIndex;
    }
    deque<int> check(deck.begin(),deck.end());
    int N;
    cin >> N;
    cout << "Case #" << t << ":";
    while (N--) {
      int d;
      cin >> d;
      cout << " " << deck[d-1];
    }
    cout << endl;
  }
  return 0;
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
