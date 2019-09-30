#include <iostream>

using namespace std;

int main(){
  int n, x;
  cin>>n>>x;
  if(n-x > x-1){
    cout<<x-1<<endl;
  }else{
    cout<<n-x<<endl;
  }

  return 0;
}