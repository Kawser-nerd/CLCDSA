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
#define PROBLEM_ID "B"

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<bool> vb;
typedef long long ll;
typedef pair<int, int> pii;

string get_best_word(const vector<string>& words, const string& order) {
  map<string, vector<int> > current_words;
  vector<int> score(words.size(), 0);
  vector< vector<bool> > has_letter(words.size(), vector<bool>(26, false));
  for (int i = 0; i < words.size(); ++i) {
    for (int j = 0; j < words[i].length(); ++j) {
      has_letter[i][words[i][j] - 'a'] = true;
    }
  }
  for (int i = 0; i < words.size(); ++i) {
    string key = "";
    for (int j = 0; j < words[i].length(); ++j) {
      key += '_';
    }
    current_words[key].push_back(i);
  }
  for (int letter_index = 0; letter_index < order.length(); ++letter_index) {
    int letter = order[letter_index] - 'a';
    map<string, vector<int> > next_map;
    for (map<string, vector<int> >::const_iterator it = current_words.begin();
         it != current_words.end();
         ++it) {
      const vector<int>& word_indices = it->second;
      bool choose_letter = false;
      for (int index = 0; index < word_indices.size(); ++index) {
        int word_index = word_indices[index];
        if (has_letter[word_index][letter]) {
          choose_letter = true;
          break;
        }
      }
      if (choose_letter) {
        for (int index = 0; index < word_indices.size(); ++index) {
          int word_index = word_indices[index];
          string new_key = it->first;
          bool in_this_word = false;
          for (int position = 0; position < words[word_index].length(); ++position) {
            if (words[word_index][position] - 'a' == letter) {
              new_key[position] = words[word_index][position];
              in_this_word = true;
            }
          }
          next_map[new_key].push_back(word_index);
          if (!in_this_word) {
            score[word_index]++;
          }
        }
      } else {
        next_map[it->first] = it->second;
      }
    }
    current_words.swap(next_map);
  }
  int best_position = -1;
  int best_score = -1;
  for (int word_index = 0; word_index < words.size(); ++word_index) {
    if (score[word_index] > best_score) {
      best_score = score[word_index];
      best_position = word_index;
    }
  }
  return words[best_position];
}

int main() {
  freopen(PROBLEM_ID".in", "r", stdin);
  freopen(PROBLEM_ID".out", "w", stdout);
  int test_count;
  cin >> test_count;
  for (int test_index = 0; test_index < test_count; ++test_index) {
    int n, m;
    cin >> n >> m;
    vector<string> words(n);
    for (int i = 0; i < n; ++i) {
      cin >> words[i];
    }
    vector<string> orders(m);
    for (int i = 0; i < m; ++i) {
      cin >> orders[i];
    }
    cout << "Case #" << test_index + 1 << ":";
    for (int order_index = 0; order_index < m; ++order_index) {
      cout << ' ' << get_best_word(words, orders[order_index]);
    }
    cout << endl;
    cerr << "Case #" << test_index + 1 << " done" << endl;
  }
  return 0;
}
