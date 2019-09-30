#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

int main() {
  int T;
  std::cin >> T;
  for (int tcase = 1; tcase <= T; ++tcase) {
    int r, c;
    std::cin >> r >> c;
    vector<string> x;
    for (int i = 0; i < r; ++i) {
      string s;
      std::cin >> s;
      x.push_back(s);
    }

    bool good = true;
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
	if (x[i][j] == '#') {
	  if (j + 1 < c && i + 1 < r && x[i][j + 1] == '#'
	      && x[i + 1][j] == '#' && x[i + 1][j + 1] == '#') {

	    x[i][j] = '/';
	    x[i][j+1] = '\\';
	    x[i+1][j] = '\\';
	    x[i+1][j+1] = '/';	    


	  } else {
	    good = false;
	    goto blah;
	  }
	}
      }
    }

  blah:

    std::cout << "Case #" << tcase << ":\n";

    if (good) {
      for (int i = 0; i < r; ++i) {
	std::cout << x[i] << "\n";
      }
    } else {
      std::cout << "Impossible\n";
    }
  }
}

