#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string get_unique(string str) {
  string sort_str = str;
  std::sort(sort_str.begin(), sort_str.end());
  sort_str.erase(std::unique(sort_str.begin(), sort_str.end()), sort_str.end());
  return sort_str;
}

int main() {
  int N = 0;
  std::cin >> N;
  std::string str;
  std::string str_1;
  std::string str_2;
  std::string uni_str_1;
  std::string uni_str_2;
  std::cin >> str;
  std::vector<int> Ascee_vec(N, 0);

  int Max_count = 0;
  for (int i = 0; i < str.size(); i++) {
    str_1 = str.substr(0, i);
    str_2 = str.substr(i);

    uni_str_1 = get_unique(str_1);
    uni_str_2 = get_unique(str_2);

    int tmp_counter = 0;
    for (int i = 0; i < uni_str_1.size(); i++) {
      for (int j = 0; j < uni_str_2.size(); j++) {
        if (uni_str_1[i] == uni_str_2[j]) {
          tmp_counter += 1;
        }
      }
    }
    if (Max_count < tmp_counter) {
      Max_count = tmp_counter;
    }
  }
 std::cout << Max_count << std::endl;

  return 0;
}