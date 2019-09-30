#include <iostream>
using namespace std;
int main(){
  int n,m=0;
  cin>>n;
  int tmp=n;
  do{
    m+=tmp%10;
    tmp/=10;
    
  }while(tmp!=0);
  cout<<(n%m==0 ? "Yes" : "No")<<endl; 

}