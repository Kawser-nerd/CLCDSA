#include<iostream>
using namespace std;

int main(){
  int h,w,res;
  cin >> h>>w;
  res = (h-1)*w+(w-1)*h;
  cout << res << endl;
  return 0;
}