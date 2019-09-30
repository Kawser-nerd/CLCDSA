#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
char b;

int main(){
  cin >> b;
  switch(b){
    case 'A':
      cout << 'T' << endl;
      break;
    case 'T':
      cout << 'A' << endl;
      break;
    case 'G':
      cout << 'C' << endl;
      break;
    case 'C':
      cout << 'G' << endl;
      break;
    default:
      break;
  }

  return 0;
}