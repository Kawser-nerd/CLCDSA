#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
  string S;
  cin >> S;

  string vowels = "aiueo";

  auto result = remove_if(begin(S), end(S),
                    [&](char c) { return vowels.find(c) != string::npos; });

  cout << string(begin(S), result) << endl;
}