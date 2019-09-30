#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t; cin >> t;
  for (int test = 1; test <= t; ++test) {
    vector<pair<double, bool> > rocks;
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
      double curr; cin >> curr;
      rocks.push_back(make_pair(curr, 1));
    }
    for (int i = 0; i < n; ++i) {
      double curr; cin >> curr;
      rocks.push_back(make_pair(curr, 0));
    }
    sort(rocks.begin(), rocks.end());

    int my_rocks = 0;
    int sad_points = n;
    for (int i = 0; i < rocks.size(); ++i) {
      pair<double, bool> curr = rocks[i];
      if (curr.second) { // my rock
        my_rocks++;
      } else { // your rock
        if (my_rocks > 0) {
          sad_points--;
          my_rocks--;
        }
      }
    }
    int happy_points = 0;
    my_rocks = 0;
    for (int i = rocks.size()-1; i >= 0; --i) {
      pair<double, bool> curr = rocks[i];
      if (curr.second) { // my rock
        my_rocks++;
      } else { // your rock
        if (my_rocks > 0) {
          happy_points++;
          my_rocks--;
        }
      }
    }

    cout << "Case #" << test << ": "
         << happy_points << " "
         << sad_points << endl;
  }
  return 0;
}