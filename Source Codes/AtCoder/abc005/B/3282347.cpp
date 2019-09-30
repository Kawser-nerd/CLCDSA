#include <iostream>

int t[100];
int min = 100;
int n;

int main(){
  std::cin >> n;
  for(int i = 0; i < n; i++){
    std::cin >> t[i];
    if(min > t[i]){
      min = t[i];
    }
  }
  std::cout << min << std::endl;
  return 0;
}