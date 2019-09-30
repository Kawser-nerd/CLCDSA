#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int main() {
  int n;
  cin >> n;
  cout << (n&1 ? n+1 : n-1) << endl; 
  return 0;
}