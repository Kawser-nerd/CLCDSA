#include<iostream>
using namespace std;
int main(){
  int n,b,count=0;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>b;
    count+=b;
  }
  cout<<count-n<<endl;
}