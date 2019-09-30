#include <iostream>
#include <vector>
#include <queue>

class Line {
 public:
  Line(unsigned t, unsigned c) : t(t), c(c), done(false) {}
  unsigned t;
  unsigned c;
  bool done;
  bool operator<(const Line &l) const { return c < l.c; }
};

class Town {
 public:
  Town() : rank(1000000), done(false) {}
  std::vector<Line> line;
  int rank;
  bool done;
  void sort() { std::sort(line.begin(), line.end()); }
};

void dfs(Line &l, std::queue<unsigned> &queue, std::vector<Town> &town) {
  if (l.done) { return; }
  else { l.done = true; }
  auto pl = std::lower_bound(town[l.t].line.begin(), town[l.t].line.end(), l);
  if (pl->done) { return; }
  auto pu = std::upper_bound(town[l.t].line.begin(), town[l.t].line.end(), l);
  for (auto p = pl; p < pu; ++p) {
    if (!town[p->t].done) {
      town[p->t].done = true;
      town[p->t].rank = town[l.t].rank;
      queue.push(p->t);
      dfs(*p, queue, town);
    } else if (town[p->t].rank == town[l.t].rank) {
      dfs(*p, queue, town);
    }
    p->done = true;
  }
}

int main() {
  unsigned N, M;
  std::cin >> N >> M;
  std::vector<Town> town(N + 1);
  for (unsigned i = 0; i < M; ++i) {
    unsigned p, q, c;
    std::cin >> p >> q >> c;
    town[p].line.push_back(Line(q, c));
    town[q].line.push_back(Line(p, c));
  }
  for (auto &i : town) { i.sort(); }
  std::queue<unsigned> queue;
  town[1].done = true;
  town[1].rank = 0;
  queue.push(1);
  while (!queue.empty()) {
    auto x = queue.front();
    queue.pop();
    for (auto &l : town[x].line) {
      if (l.done) { continue; }
      if (!town[l.t].done) {
        town[l.t].rank = town[x].rank + 1;
        town[l.t].done = true;
        queue.push(l.t);
        dfs(l, queue, town);
      } else if (town[l.t].rank == town[x].rank + 1) {
        dfs(l, queue, town);
      }
      l.done = true;
    }
  }
  std::cout << (town[N].rank == 1000000 ? -1 : town[N].rank) << std::endl;
  return 0;
}