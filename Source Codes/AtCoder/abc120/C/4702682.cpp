#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <math.h>

using namespace std;
using ll = long long int;

int main()
{
  string s;
  cin >> s;
  int zero, one;
  zero = one = 0;
  for(int i = 0; i < s.size(); i++)
  {
    if(s[i] == '0') {
      zero++;
    }else{
      one++;
    }
  }
  cout << min(zero, one) * 2 << endl;
}