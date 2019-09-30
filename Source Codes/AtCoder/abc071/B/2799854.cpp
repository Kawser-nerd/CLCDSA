#include <iostream>
#include <map>

using namespace std;

int main() {
  string alphabet = "abcdefghijklmnopqrstuvwxyz";
  string S;
  cin >> S;
  map<char,int>freq;

  for (int i = 0; i < S.size(); i++) {
    if (freq.count(S[i]) == 0) {
      freq[S[i]] = 0;
    }
    freq[S[i]]++;
  }

  //cout << "nisdf" << endl;
  char min_alphabet;
  bool has_min_alphabet = false;
  for (int i = 0; i < alphabet.size(); i++) {
    //cout << freq.count(alphabet[i]) << endl;
    if (freq.count(alphabet[i]) == 0) {
      //cout << "====" << endl;
      //cout << alphabet[i] << endl;
      min_alphabet = alphabet[i];
      has_min_alphabet = true;
      break;
    }
  }
  if (has_min_alphabet) {
    cout << min_alphabet << endl;
  } else {
    cout << "None" << endl;
  }
}