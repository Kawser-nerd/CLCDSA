#include <iostream>
#include <string>
//#include <algorithm>
//#include <vector>
//#include <numeric>
//#include <tuple>
#include <cstdio>

typedef long long ll;
using namespace std;
string s;

int main() {
   cin >> s;
   if (s.size() == 1) {
      cout << 0 << endl;
      return 0;
   }
   
   int bc = 0;
   long long co = 0;
   //cout << s.size() << endl;
   for (int i=(int)s.length()-1;i>=0;i--) {
      if (s[i] == 'B') {
         bc++;
         co += (long long)(s.size() - i-bc);
      }
   }
   cout << co << endl;
}