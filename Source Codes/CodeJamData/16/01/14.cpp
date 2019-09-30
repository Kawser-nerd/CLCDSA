#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;
  for (int ta=1; ta<=t; ++ta) {
    cout << "Case #" << ta << ": ";
    int n;
    cin >> n;
    if (n == 0) {
      cout << "INSOMNIA" << endl;
    } else {
      int c = 0;
      vector<bool> seen(10,false);
      int nseen=0;
      while (nseen < 10) {
        c++;
        int cn = c*n;
        while (cn > 0) {
          if (!seen[cn%10])
            nseen++;
          seen[cn%10] = true;
          cn /= 10;
        }
      }
      cout << c*n << endl;
    }
  }
}