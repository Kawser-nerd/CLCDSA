#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
  int A, B, C;
   std::cin >> A >> B >> C;
   if(B/A > C){
     std::cout << C << '\n';
   }else{
     std::cout << B/A << '\n';
   }
  return 0;
}