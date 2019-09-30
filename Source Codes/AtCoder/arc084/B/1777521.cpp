#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <deque>
using namespace std;

const int MAX_K = 100000;
vector< pair<int, int> > V[MAX_K];
bool reached[MAX_K];

void make_graph(unsigned int k) {
  //cout << "make graph" << endl;
  for (unsigned int i = 1; i < k; i++) {
    V[i].push_back(make_pair((i+1) % k, 1));
    if (i*10 %k != i) {
      V[i].push_back(make_pair(i*10 % k, 0));
    }
  }
  // for (unsigned int i = 0; i < k; i++) {
  //   for (auto itr = V[i].begin(); itr != V[i].end(); ++itr) {
  //     cout << i << "->" << itr->first << ": " << itr->second << ' ';
  //   }
  //   cout << endl;
  // }
}

int bfs (unsigned int k) {

  pair<int, int> node = make_pair(1, 1);
  deque<pair<int, int>> queue; // first: node, second: cumulative cost
  fill(reached, reached+k, false);

  while (node.first > 0) {
    //cout << node.first << ": " << node.second << endl;
    reached[node.first] = true;

    for (auto i = V[node.first].begin(); i != V[node.first].end(); ++i) {
      pair<int, int> next_node = *i;
      if (!reached[next_node.first]) {

	  if (next_node.second == 0) {
	    queue.push_front(make_pair(next_node.first, node.second));
	  }
	  else if (next_node.second == 1) {
	    queue.push_back(make_pair(next_node.first, node.second + 1));
	  }

      }
    }
    // for (auto itr = queue.begin(); itr != queue.end(); ++itr) {
    //   cout << itr->first << ": " << itr->second << ' ';
    // }
    //cout << endl;
    //cout << endl;
    node = queue.front();
    queue.pop_front();
  }
  return node.second;
}

int main() {
  unsigned int k;
  cin >> k;
  make_graph(k);
  cout << bfs(k) << endl;
}