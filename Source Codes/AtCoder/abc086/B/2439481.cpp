#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<climits>
#include<cstdlib>
#include<map>
#include<math.h>
#include<utility>
using namespace std;
typedef long long ll;

int main(){
  string a, b;
  cin >> a >> b;
  int num = stoi(a+b);
  bool flag = false;
  for(int i=1; i<1000; i++){
    if(i*i==num) flag = true;
  }
  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;
}