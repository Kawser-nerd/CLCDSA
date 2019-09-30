#include <iostream>
#include <string>

int main(void)
{
  std::string str;
  int a[4];
  std::cin >> str;
  std::cin >> a[0];
  std::cin >> a[1];
  std::cin >> a[2];
  std::cin >> a[3];
  for (int i = 0; i < 4; i++)
  {
    int x = a[i] + i;
    str = str.substr(0, x) + "\"" + str.substr(x);
  }
  std::cout << str << std::endl;
}