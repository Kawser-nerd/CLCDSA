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
#define PROBLEM_ID "A"

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<bool> vb;
typedef long long ll;
typedef pair<int, int> pii;

struct TreeNode {
  string feature;
  int left, right;
  double weight;

  TreeNode(): feature(""), left(-1), right(-1), weight(-1) {}
};

void AddNode(vector<TreeNode>* tree) {
  tree->push_back(TreeNode());
}

int BuildTree(istringstream& in, vector<TreeNode>* tree) {
  int index = tree->size();
  AddNode(tree);
  string bracket;
  in >> bracket;
  assert(bracket == "(");
  in >> tree->back().weight;
  in >> tree->back().feature;
  if (tree->back().feature == ")") {
    tree->back().feature = "";
    return index;
  }
  tree->at(index).left = BuildTree(in, tree);
  tree->at(index).right = BuildTree(in, tree);
  in >> bracket;
  assert(bracket == ")");
  return index;
}

void BuildTree(const string& tree_string, vector<TreeNode>* tree) {
  string new_tree_string;
  for (int i = 0; i < tree_string.length(); ++i) {
    if (tree_string[i] == ')') {
      new_tree_string += ' ';
    }
    new_tree_string += tree_string[i];
    if (tree_string[i] == '(') {
      new_tree_string += ' ';
    }
  }
  istringstream in(new_tree_string);
  BuildTree(in, tree);
}

double GetScore(const set<string>& features, const vector<TreeNode>& tree) {
  double result = 1;
  int node = 0;
  while (node != -1) {
    result *= tree[node].weight;
    if (features.find(tree[node].feature) != features.end()) {
      node = tree[node].left;
    } else {
      node = tree[node].right;
    }
  }
  return result;
}

int main() {
  freopen(PROBLEM_ID".in", "r", stdin);
  freopen(PROBLEM_ID".out", "w", stdout);
  int tests;
  cin >> tests;
  for (int test_number = 0; test_number < tests; ++test_number) {
    int lines;
    cin >> lines;
    string tree_string = "";
    char buf[10000];
    gets(buf);
    for (int line = 0; line < lines; ++line) {
      string s;
      gets(buf);
      s = buf;
      if (line > 0) {
        tree_string += " ";
      }
      tree_string += s;
    }
    vector<TreeNode> tree;
    BuildTree(tree_string, &tree);
    int animals;
    cin >> animals;
    cout << "Case #" << test_number + 1 << ":" << endl;
    for (int animal = 0; animal < animals; ++animal) {
      string name;
      cin >> name;
      int feature_count;
      cin >> feature_count;
      set<string> features;
      for (int feature_index = 0; feature_index < feature_count; ++feature_index) {
        string feature;
        cin >> feature;
        features.insert(feature);
      }
      printf("%.10lf\n", GetScore(features, tree));
    }
  }
  return 0;
}
