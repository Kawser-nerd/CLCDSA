#include <iostream>
#include <list>

using namespace std;


typedef uint64_t INT;

class Tree;
INT countWhite(Tree &top);
INT countAll(Tree &top);

#define P 1000000007;
int N;
list<int> BRIDGE[100001];

INT CACHEWHITE[100001];

class Tree {
public:
  Tree() = delete;
  explicit Tree(int v) : val(v) {};
  int val;
  list<void*> children;
};


Tree* buildTree(int val, int parent) {

  Tree *t = new Tree(val);

  for (auto c : BRIDGE[val]) {
    if (c == parent) continue;

    auto child = buildTree(c, val);
    t->children.push_back((void*)child);
  }

  return t;
}


INT countWhite(Tree &top) {
  if (0 < CACHEWHITE[top.val]) {
    return CACHEWHITE[top.val];
  }

  INT sum = 1;

  for (auto c : top.children) {
    sum *= countAll(*(Tree*)c);
    sum %= P;
  }

  CACHEWHITE[top.val] = sum;

  return sum;
}


INT countAll(Tree &top) {

  INT sum = 1;

  for (auto c : top.children) {
    sum *= countWhite(*(Tree*)c);
    sum %= P;
  }

  sum += countWhite(top);
  sum %= P;

  return sum;
}


int main() {

  cin >> N;

  int a, b;
  for (int i=1; i<N; ++i) {
    cin >> a >> b;

    BRIDGE[a].push_back(b);
    BRIDGE[b].push_back(a);
  }

  auto top = buildTree(1, 0);

  INT ret = countAll(*top);
  cout << ret << endl;

  return 0;
}