#include<algorithm>
#include<iostream>
#include<functional>
using namespace std;

int main(){
  int num[200];
  int n,count,ans;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>num[i];
  }
  sort(num,num+n);
  count=num[0];
  reverse(num,num+n);
  ans=num[0];
  cout<<ans-count<<endl;
}