#include <iostream>
#include <map>
#include <set>

#define KEY_LEN 20
#define KEY_NUM 12

static char KEYS[] = {'W', 'B', 'W', 'B', 'W', 'W', 'B', 'W', 'B', 'W', 'B', 'W'};

int main()
{
  std::string input;

  std::cin >> input;

  std::set<std::string> key_names = {"Do", "Re", "Mi", "Fa", "So", "La", "Si"};

  std::map<std::string, int> key_offset =
  {
    {"Do", 0},
    {"Re", 2},
    {"Mi", 4},
    {"Fa", 5},
    {"So", 7},
    {"La", 9},
    {"Si", 11},
  };

  for (int i = 0; i < KEY_LEN; i++) {
    char c = input[i];
    std::set<std::string> failed;
    for (std::string key : key_names) {
      int offset = (key_offset.at(key) + i) % KEY_NUM;
      if (KEYS[offset] != c) {
        failed.insert(key);
      }
    }

    for (std::string key : failed) {
      key_names.erase(key);
    }

    if (key_names.size() == 1) {
      break;
    }
  }

  for (std::string key : key_names) {
    std::cout << key << std::endl;
  }
}