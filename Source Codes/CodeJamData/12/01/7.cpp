#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>

#include "Integer.h"
#include "Rational.h"

using namespace std;

int main(void) {
  string line, line2;

  int iTest, nTests; cin >> nTests; getline(cin, line);

  string mapping = "*************************************************************************************************yhesocvxduiglbkrztnwjpfmaq*************************************************************************************************************************************";

  for (iTest = 1; iTest <= nTests; ++iTest) {
    cerr << iTest << "/" << nTests << "\n";

    getline(cin, line);

    int i, n = line.length();
    for (i = 0; i < n; ++i)
      if (line[i]!=' ')
	line[i] = mapping[line[i]];

    cout << "Case #" << iTest << ": ";
    cout << line;

    cout << "\n";
  }

  return 0;
}
