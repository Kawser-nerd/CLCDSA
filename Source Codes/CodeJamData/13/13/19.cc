#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <cmath>

using namespace std;

const int MAXN = 12;

int sets, set_size, max_digit, num_samples;

int members[MAXN];

struct Set {
  int members[MAXN];
  string str() {
    stringstream ss;
    for (int i = 0; i < set_size; i++) {
      ss << members[i];
    }
    return ss.str();
  }
  int64_t ways;
};

map<int, map<Set*, int64_t>> evidence;

void ProcessSet() {
  int64_t ways = 1;
  for (int i = 1; i <= set_size; i++) {
    ways *= i;
  }

  for (int i = 2; i <= max_digit; i++) {
    int num = 0;
    for (int j = 0; j < set_size; j++) {
      if (members[j] == i) {
        num++;
      }
    }

    int64_t divisor = 1;
    for (int j = 1; j <= num; j++) {
      divisor *= j;
    }

    ways /= divisor;
  }

  Set* ref = new Set();
  for (int i = 0; i < set_size; i++) {
    ref->members[i] = members[i];
  }
  ref->ways = ways;

  for (int subset = 0; subset < (1 << set_size); subset++) {
    int product = 1;
    for (int i = 0; i < set_size; i++) {
      if (subset & (1 << i)) {
        product *= members[i];
      }
    }
    evidence[product][ref] += 1;
  }
}

void Generate(int i, int current_digit) {
  if (i == set_size) {
    ProcessSet();
  } else {
    for (; current_digit <= max_digit; current_digit++) {
      members[i] = current_digit;
      Generate(i + 1, current_digit);
    }
  }
}

void Solve() {
  cin >> sets >> set_size >> max_digit >> num_samples;

  Generate(0, 2);

  cout << "\n";

  for (int i = 0; i < sets; i++) {
    map<Set*, double> here;

    //cerr << "starting..." << endl;

    for (int j = 0; j < num_samples; j++) {
      int product;
      cin >> product;

      //cerr << "sample " << j << ": " << product << endl;

      if (j == 0) {
        for (auto it : evidence[product]) {
          here[it.first] = log2(it.second) + log2(it.first->ways);
          //cerr << it.first->str() << " " << here[it.first] << endl;
        }
      } else {
        map<Set*, double> new_here;
        for (auto it : here) {
          int64_t m = evidence[product][it.first];
          if (m > 0) {
            new_here[it.first] = it.second + log2(m);
          }
          //cerr << it.first->str() << " " << new_here[it.first] << endl;
        }
        std::swap(here, new_here);
      }
    }

    double max_here = -1;
    Set* best_set = nullptr;

    for (auto it : here) {
      //cout << it.first->str() << " " << here[it.first] << endl;
      if (it.second >= max_here) {
        // pick random?
        best_set = it.first;
        max_here = it.second;
      }
    }

    if (best_set == nullptr) {
      for (int j = 0; j < set_size; j++) {
        cout << "2";
      }
    } else {
      for (int j = 0; j < set_size; j++) {
        cout << best_set->members[j];
      }
    }
    cout << "\n";
  }
}

int main() {
  int num_cases;
  cin >> num_cases;
  for (int i = 1; i <= num_cases; i++) {
    cout << "Case #" << i << ": ";
    Solve();
  }
}

