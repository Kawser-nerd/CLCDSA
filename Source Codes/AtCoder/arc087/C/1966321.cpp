#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

struct Trie {
  Trie *children[2];
  Trie() {
    fill(children, children+2, nullptr);
  }
  void add(const string &s) {
    Trie *cur = this;
    for (char ch : s) {
      int d = ch - '0';
      if (!cur->children[d]) {
        cur->children[d] = new Trie();
      }
      cur = cur->children[d];
    }
  }
};

long long dfs(Trie *r, int lv, long long L) {
  if (lv == L) {
    return 0;
  }
  if (!r->children[0] && !r->children[1]) {
    return 0;
  }
  long long Xor = 0;
  for (int d = 0; d < 2; d++) {
    if (r->children[d]) {
      Xor ^= dfs(r->children[d], lv + 1, L);
    } else {
      long long h = L - lv;
      int p = 0;
      while (h > 0 && h % 2 == 0) {
        p++;
        h /= 2;
      }
      Xor ^= (1LL << p);
    }
  }
  return Xor;
}

const int N = int(1e5);
char s[N+1];

int main(void) {
  int n; long long L;
  scanf("%i %lld", &n, &L);
  
  Trie *tree = new Trie();
  for (int i = 0; i < n; i++) {
    scanf("%s", s);
    tree->add(string(s));
  }
  
  puts(dfs(tree, 0, L) ? "Alice" : "Bob");
  
  return 0;
}