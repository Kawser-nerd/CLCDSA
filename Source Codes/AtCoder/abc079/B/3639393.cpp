#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n;
  cin>>n;
  vector<long long int> v(n+1);
  for(int i=0;i<=n;i++){
    if(i==0){
      v[0]=2;
    }else if(i==1){
    v[1]=1;
    }else{
      v[i]=v[i-1]+v[i-2];
    
    }
  }
cout<<v[n]<<endl;
}