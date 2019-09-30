#include <iostream>
#define int long long
using namespace std;

int f(int x){
  if(x%4==0)return x;
  if(x%4==1)return 1;
  if(x%4==2)return x+1;
  if(x%4==3)return 0;
}

signed main(){
  int a,b;
  cin>>a>>b;
  cout<<(f(b)^f(a-1))<<endl;
} ./Main.cpp:10:1: warning: control may reach end of non-void function [-Wreturn-type]
}
^
1 warning generated.