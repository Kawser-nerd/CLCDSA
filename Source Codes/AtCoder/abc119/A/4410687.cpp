#include <iostream>
#include <string>

int main(int argc, char* args[]) {
  using std::string;
  string str;
  std::cin >> str;
  
  string year = string(str.begin(), str.begin() + 4);
  string month = string(str.begin()+5, str.begin() + 7);
  string day = string(str.begin()+8, str.end());

  string ymd_str = year + month + day;
  int ymd = atoi(ymd_str.c_str());

  if (ymd <= 20190430) {
    std::cout << "Heisei";
  } else {
    std::cout << "TBD";
  }
  return 0;
}