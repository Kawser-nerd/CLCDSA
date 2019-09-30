#include <iostream>
using namespace std;

int main()
{
  string W,S="";
  cin >> W;
  for (int i=0; i<W.size(); i++) {
    if (W[i] != 'a' && W[i] != 'i' &&
        W[i] != 'u' && W[i] != 'e' && W[i] != 'o')
      S += W[i];
  }
  cout << S << endl;
  return 0;
}