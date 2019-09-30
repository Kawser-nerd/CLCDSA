#include <iostream>
using namespace std;
typedef long long unsigned int ll;
 
int main() {
 
  string a,b,c,d;
  cin >> a;
  cin >>b;
  cin >>c;
  if(a[a.size()-1]==b[0]&&b[b.size()-1]==c[0]){
	cout << "YES" <<endl;
  }else{
	cout << "NO" <<endl;
  }
    return 0;
}