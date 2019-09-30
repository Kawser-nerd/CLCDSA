#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;

int main(){
  string a, b;
  cin >> a >> b;
  cout << ((a.length() > b.length())? a : b) << endl;
}