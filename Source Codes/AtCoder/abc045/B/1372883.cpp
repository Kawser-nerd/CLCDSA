#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main(){
  
  vector<string> v(3);

  for(int i = 0; i < 3; i++) cin >> v[i];
  int cur = 0;
  while(true){
    
    if(v[cur].length() == 0){
      if(cur == 0){
        cout << 'A' << endl;
      }else if(cur == 1){
        cout << 'B' << endl;
      }else{
        cout << 'C' << endl;
      }
      return 0;
    }
    int c = v[cur][0] - 'a';
    v[cur] = v[cur].substr(1);
    cur = c;
  }
  return 0;
}