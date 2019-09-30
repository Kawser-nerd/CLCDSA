#include <iostream>
#include <map>



using namespace std;

int main(){
  
  long long int n,k;
  cin>>n>>k;
  
  map<int,long long int> checker;
  int tmp_key,tmp_num;
  for(int i=0;i<n;i++){
    cin>>tmp_key>>tmp_num;
    checker[tmp_key]+=tmp_num;
  }
  for(pair<int,long long int> p:checker){
   
    k-=p.second;
     
    if(k<=0){
      
      cout<<p.first<<endl;
      return 0;
    }
  }


  return 0;
}