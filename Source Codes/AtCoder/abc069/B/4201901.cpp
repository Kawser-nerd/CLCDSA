#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
using namespace std;

int main(){
  string miria;
  cin >> miria;
  cout << miria[0] << miria.length()-2 << miria[miria.length()-1] << endl;
  return 0;
}