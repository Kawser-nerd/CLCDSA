#include<algorithm>
#include<iostream>
#include<functional>
#include<cmath>
using namespace std;
int main(){
  int ans[4];
  char x[1000];
  int n,a=0,b=0,c=0,d=0;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>x[i];
    char aa=x[i];
    if(aa=='1')
      a++;
    else if(aa=='2')
      b++;
    else if(aa=='3')
      c++;
    else if(aa=='4')
      d++;
  }
  ans[0]=a;
  ans[1]=b;
  ans[2]=c;
  ans[3]=d;
  sort(ans,ans+4);
  cout<<ans[3]<<" "<<ans[0]<<endl;
}