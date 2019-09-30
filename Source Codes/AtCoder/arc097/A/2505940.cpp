#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[]){
  std::string s;
  int n;
  std::getline(std::cin, s);
  std::cin >> n;
  std::vector<std::string> ss;

  for (std::size_t i = 0; i < s.length(); i++) {
    for (std::size_t len = 1; len <= s.length() ; len++){
      if (len + i > s.length()){
        break;
      }
      std::string a = s.substr(i, len);
      if(ss.size() == 0){
        ss.push_back(a);
      } else if (ss.size() >= 5){
        if (ss[4] <= a){
          break;
        }
      }
      for (size_t order = 0; order < 5; order++){
        if (ss[order] > a){
          ss.insert(ss.begin() + order, a);
          break;
        } else if (ss[order] == a) {
          break;
        } else if (order == ss.size() - 1){
          ss.push_back(a);
          break;
        }
      }

    }
  }

  std::cout << ss[n - 1] << std::endl;

  return 0;
}