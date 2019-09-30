#include <iostream>

int main(){
  long n, x;
  long a[100000];
  long eat = 0;
  std::cin >> n >> x;
  for(int i = 0; i < n; i++){
    std::cin >> a[i];
  }

  for(int i = 0; i < n - 1; i++){
    if(a[i] > x){
      eat += a[i] + a[i + 1] - x;
      a[i] = x;
      a[i + 1] = 0;
    }
    else if(a[i] + a[i + 1] > x){
      eat += a[i] + a[i + 1] - x;
      a[i + 1] = x - a[i];
    }
  }

  std::cout << eat << std::endl;
}