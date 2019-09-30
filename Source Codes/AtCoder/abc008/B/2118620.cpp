#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  vector<int> vote(n);

  int i,j;
  for (i = 0; i < n; i++) {
    cin >> s[i];
    for (j = 0; j < i; j++) {
      if (s[j] == s[i]) {
        vote[j]++;
        break;
      }
    }
  }

  int max = distance(vote.begin(), max_element(vote.begin(), vote.end()));

  cout << s[max] << "\n";
  return 0;
}