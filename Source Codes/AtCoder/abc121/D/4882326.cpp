#include <iostream>
#include <string>
#include <vector>
#define range(i, l, r) for(int i=l;i<r,i++)
using namespace std;
long long retint(long long n){
  switch(n%4){
    case 0: return n;
    case 1: return 1;
    case 2: return n + 1;
    case 3: return 0;
  }
  return 0;
}
int main(int argc, char const *argv[]) {
  long long A, B;
  std::cin >> A >> B;
  std::cout << (retint(B)|((A|retint(A))-(A&retint(A)))) - (retint(B)&((A|retint(A))-(A&retint(A))))<< '\n';
  return 0;
}