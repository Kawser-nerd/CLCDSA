#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[]) {
  int s,k,cnt=0;
  std::cin >> k >> s;
  for(int i=0; i<=k; i++){
    for(int j=0; j<=k; j++){

        int l=s-i-j;
        if(l>=0 && l<=k) cnt++;

    }
  }

  std::cout << cnt << endl;
  return 0;
}