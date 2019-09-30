#include <iostream>
using namespace std;
#define S(x) ((x)*(x))
int main()
{
  ios::sync_with_stdio(false);
  int x1, y1, r, x2, y2, x3, y3;
  cin >> x1 >> y1 >> r >> x2 >> y2 >> x3 >> y3;
  if( S(x1-x2) + S(y1-y2) <= S(r) && S(x1-x2) + S(y1-y3) <= S(r) && S(x1-x3) + S(y1-y2) <= S(r) && S(x1-x3) + S(y1-y3) <= S(r) ){
    cout << "YES" << endl << "NO" << endl; return 0;
  }
  if( x1-r >= x2 && x1+r <= x3 && y1-r >= y2 && y1+r <= y3 ){
    cout << "NO" << endl << "YES" << endl; return 0;
  }
  cout << "YES" << endl << "YES" << endl; return 0;
}