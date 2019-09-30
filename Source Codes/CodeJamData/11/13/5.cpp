#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <limits>
#include <numeric>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define MP make_pair
#define all(v) (v).begin(), (v).end()
#define PROBLEM_ID "C"

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<bool> vb;
typedef long long ll;
typedef pair<int, int> pii;

struct card {
  int c;
  int s;
  int t;

  card(int c_, int s_, int t_) : c(c_), s(s_), t(t_) {}
  card(): c(-1), s(-1), t(-1) {}
};

int GetResGreedy(const vector<card>& cards, int hand, int turns, vector<bool>& played) {
  if (turns == 0) {
    return 0;
  }
  int res = 0;
  for (int i = 0; i < hand; ++i) {
    if (cards[i].t >= 1 && !played[i]) {
      played[i] = true;
      res += cards[i].s;
      turns += cards[i].t - 1;
      hand += cards[i].c;
      if (hand > cards.size()) {
        hand = cards.size();
      }
    }
  }
  int res2 = 0;
  vector<int> scores;
  for (int i = 0; i < hand; ++i) {
    if (!played[i] && cards[i].c == 0) {
      scores.push_back(cards[i].s);
    }
  }
  sort(scores.rbegin(), scores.rend());
  for (int i = 0; i < turns && i < scores.size(); ++i) {
    res2 += scores[i];
  }
  int max_score = -1;
  int index_max_score = -1;
  for (int i = 0; i < hand; ++i) {
    if (!played[i] && cards[i].c == 1) {
      if (cards[i].s > max_score) {
        max_score = cards[i].s;
        index_max_score = i;
      }
    }
  }
  int res3 = 0;
  if (index_max_score != -1) {
    res3 = max_score;
    played[index_max_score] = true;
    res3 += GetResGreedy(cards, min(hand + 1, (int)cards.size()), turns - 1, played);
    played[index_max_score] = false;
  }
  res += max(res2, res3);
  return res;
}

int GetResStupid(const vector<card>& cards, int hand) {
  vector<bool> played(cards.size(), false);
  return GetResGreedy(cards, hand, 1, played);
}

int main() {
  freopen(PROBLEM_ID".in", "r", stdin);
  freopen(PROBLEM_ID".out", "w", stdout);
  int test_count;
  cin >> test_count;
  for (int test_index = 0; test_index < test_count; ++test_index) {
    int n;
    cin >> n;
    vector<card> cards(n);
    for (int i = 0; i < n; ++i) {
      cin >> cards[i].c >> cards[i].s >> cards[i].t;
    }
    int m;
    cin >> m;
    cards.resize(n + m);
    for (int i = 0; i < m; ++i) {
      cin >> cards[i + n].c >> cards[i + n].s >> cards[i + n].t;
    }
    int res = GetResStupid(cards, n);
    cout << "Case #" << test_index + 1 << ": " << res << endl;
    cerr << "Case #" << test_index + 1 << ": " << res << endl;
  }
  return 0;
}
