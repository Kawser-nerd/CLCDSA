#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
  int n;
  cin >> n;

  vector<string> S(n);
  for(int i = 0; i < n; i++) cin >> S[i];

  array<vector<int>, 26> count;
  for(auto& v : count) v.resize(n);
  for(int i = 0; i < n; i++){
    for(char c : S[i]){
      count[c - 'a'][i]++;
    }
  }

  array<int, 26> result;
  transform(count.begin(), count.end(), result.begin(), [](vector<int> const& v){return *std::min_element(v.begin(), v.end());});
  for(int i = 0; i < 26; i++) while(result[i]--) cout << (char)('a' + i);
  cout << endl;
}