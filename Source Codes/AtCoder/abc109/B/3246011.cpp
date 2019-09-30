#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const* argv[])
{
  int n;
  cin >> n;
  n--;

  string w;
  char head_char;
  char tail_char;

  map<string, int> m;
  cin >> w;
  m.insert(pair<string, int>(w, 1));

  head_char = w.front();
  tail_char = w.back();

  while(n--) {
    cin >> w;
    head_char = w.front();

    if (head_char != tail_char) {
      cout << "No" << endl;
      return 0;
    }

    tail_char = w.back();

    if ((int)m.count(w) == 0) {
      m.insert(pair<string, int>(w, 1));
    } else {
      cout << "No" << endl;
      return 0;
    }

  }

  cout << "Yes" << endl;
  return 0;
}