#include<iostream>
using namespace std;
int main(){
  int b[10000];
  int n,count=0;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>b[i];
    count+=b[i];
  }
  cout<<count-n<<endl;
}