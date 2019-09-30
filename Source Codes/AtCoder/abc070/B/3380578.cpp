#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  
  cout<<(((min(b,d))-(max(a,c))>=0)?((min(b,d))-(max(a,c))):0)<<endl;

  return 0;
}