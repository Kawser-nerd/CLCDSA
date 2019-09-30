#include <iostream>
#include <iomanip>

using namespace std;

const char pText[] = "our language is impossible to understand there are twenty six factorial possibilities so it is okay"
                     "if you want to just give up a zoo q";
const char gText[] = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya"
                     "kw aej tysr re ujdr lkgc jv y qee z";

int main() {
  int nc; cin >> nc;
  for (int cur = 1; cur <= nc; ++cur) {
    cout << "Case #" << cur << ": ";
    char c;
    while ((cin >> c >> noskipws) && (c != '\n')) {
      int i = 0;
      while (gText[i] != c) ++i;
      cout << pText[i];
      }
    cout << '\n';
    }
  }

