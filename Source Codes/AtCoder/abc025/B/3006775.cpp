#include<iostream>
#include<string>
using namespace std;
int main(){
  int N,A,B;
  int ans=0;
  cin>>N>>A>>B;
  int d[100];
  string s[100];
  for(int i=0;i<N;i++){
    cin>>s[i]>>d[i];
  }
  for(int i=0;i<N;i++){
    if(s[i]=="East"){
      if(d[i]<=B && d[i] >= A){
        ans+=d[i];
      }
      else if(d[i]<A){
        ans+=A;
      }else{
        ans+=B;
      }
    }else{
      if(d[i]<=B && d[i] >= A){
        ans-=d[i];
      }
      else if(d[i]<A){
        ans-=A;
      }else{
        ans-=B;
      }
  }
 }
  if(ans>0){
    cout<<"East"<<" "<<ans<<endl;
  }
  else if(ans==0){
    cout<<0<<endl;
  }else{
    cout<<"West"<<" "<<-ans<<endl;
  }
  return 0;
}