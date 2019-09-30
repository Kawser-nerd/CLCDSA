#include <iostream>
#include <string>

using namespace std;

int main(){

  string w;
  cin >> w;
  string v = w;

  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());

  char t;
  int count;
  int flag;

  for (int i = 0; i < v.size(); i++){
    t = v[i];
    count = 0;
    for (int j = 0; j < w.size(); j++){
      if (w[j] == t){
        count += 1;
      }
    }

    if ((count % 2) != 0){
      cout << "No" << endl;
      return 0;
    }
  }

  /*
  if (flag == 0){
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
  */

  cout << "Yes" << endl;

  return 0;
}