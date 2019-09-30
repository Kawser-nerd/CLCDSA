#include <iostream>
#include <iomanip>
#include <string>
#include <set>
#include <utility>
using namespace std;

int main()
{
  int n;
  cin >> n;

  multiset<pair<int, int>> rain;

  for(int i = 0; i < n; ++i) {
    string str;
    cin >> str;
    int start = stoi(str.substr(0, 2))*60 + stoi(str.substr(2, 2));  // ????????
    int end = stoi(str.substr(5, 2))*60 + stoi(str.substr(7, 2));  // ????????

    // start ????5?????????? rain ???
    rain.emplace((start/5)*5, 0);
    // end ????5?????????? rain ???
    rain.emplace(((end+4)/5)*5, 1);
  }

  // ????????????
  int count = 0;
  int start;
  for(auto tm : rain) {
    if(tm.second == 0) {
      ++count;
      if (count == 1) {
        // ???? start ?????????
        start = tm.first;
      }
    }
    else {  // tm.second == 1
      --count;
      if (count == 0) {
        // ????
        int& end = tm.first;
        cout << setfill('0') << setw(2) << start / 60;
        cout << setfill('0') << setw(2) << start % 60;
        cout << "-";
        cout << setfill('0') << setw(2) << end / 60;
        cout << setfill('0') << setw(2) << end % 60 << endl;;
      }
    }
  }
}