#include <iostream>



using namespace std;

int main(){
  int n,a,b;
  cin>>n>>a>>b;
  int result = 0,tmp_int;
  for(int i=1;i<=n;i++){
    tmp_int=(i%10)+((i/10)%10)+((i/100)%10)+((i/1000)%10)+((i/10000)%10);
    if(a<=tmp_int&&tmp_int<=b){
      result+=i;
    }
  
  }
  cout<<result<<endl;

  return 0;
}