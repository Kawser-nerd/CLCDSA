#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[]) {
  int n,ans=0,max=0;
  std::cin >> n;
  string s;
  std::cin >> s;

  for(int i=0; i<n; i++){
    if(s[i]=='I'){
      ans++;
      if(ans>max) max=ans;
    }
    else ans--;
  }

  std::cout << max << endl;
  return 0;
}