#include<iostream>
#include<algorithm>
using namespace std;
int main(){
  int num[1000];
  int n,y=0,count=0;
  cin>>n;
    for(int i=0;i<n;i++){
      cin>>num[i];
    }
  for(int j=0;j<100000;j++){
    for(int k=0;k<n;k++){
      if(num[k]%2==1){
        y++;
        break;
      }
      else{
        count++;
      num[k]/=2;
      }
    }
    if(y==1)
      break;
  }
  cout<<count/n<<endl;
}