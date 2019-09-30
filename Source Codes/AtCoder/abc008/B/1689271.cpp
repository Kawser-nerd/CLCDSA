#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

int main(int argc, char const *argv[]) {
  int N;
  std::string s = "";
  std::cin >> N;
  std::unordered_map<std::string, int> table = *new std::unordered_map<std::string, int>();

  for(int i = 0; i < N; i++){
    std::cin >> s;
    if(table.find(s) != table.end()){
      table[s] += 1;
    }else{
      table[s] = 1;
    }
  }

  unsigned max = 0;
  std::string max_key = "";

  for(auto itr = table.begin(); itr != table.end(); ++itr) {
    if(itr->second > max){
      max_key = itr->first;
      max = itr->second;
    }
  }
  std::cout << max_key << '\n';

  return 0;
}