#include <iostream>
using namespace std;
typedef long long unsigned int ll;
 
int main() {
 
  string a,b,c,d;
  cin >> a;
  cin >>b;
  cin >>c;
  int offset;
  offset='A'-'a';
  cout << char (a[0]+offset) <<char ( b[0]+offset)<<char( c[0]+offset)<<endl;
    return 0;
}