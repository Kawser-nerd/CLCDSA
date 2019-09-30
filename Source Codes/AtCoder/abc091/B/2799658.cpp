#include <iostream>
#include <map>

using namespace std;

int main() {
  int n,m;
  map<string,int> freq;
  cin >> n;
  //cout << "kimsdgoewq";
  //cout << n << endl;
  //cout << "kimsdgoewq";
  for (int i = 0; i < n; i++) {
    //cout << "--------" << endl;
    string s;
    cin >> s;
    if (freq.count(s) == 0) {
      freq[s] = 0;
    }
    freq[s]++;
  }
  //cout << "===============";
  cin >> m;
  for (int i = 0; i < m; i++) {
    string s;
    cin >> s;
    if (freq.count(s) == 0) {
      freq[s] = 0;
    }
    freq[s]--;
  }
  int max_count = 0;
  for (auto i = freq.begin(); i != freq.end(); i++) {
    if (i->second > max_count) {
      max_count = i->second;
    }
  }
  cout << max_count << endl;
}