#include<algorithm>
#include<iostream>
#include<functional>
using namespace std;
int main(){
  int num[200];
  int n,count=0,ans=0;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>num[i];
  }
  sort(num,num+n);
  reverse(num,num+n);
  for(int j=0;j<n;j++){
    if(ans!=num[j]){
      count++;
    }
    ans=num[j];
  }
  cout<<count<<endl;
}