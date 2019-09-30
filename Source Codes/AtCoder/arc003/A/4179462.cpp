#include<algorithm>
#include<iostream>
#include<functional>
#include<iomanip>
using namespace std;
int main(){
  double n,count=0;
  char s[200];
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>s[i];
    char x=s[i];
    if(x=='A'){
      count+=4;
    }
    else if(x=='B'){
      count+=3;
    }
    else if(x=='C'){
      count+=2;
    }
    else if(x=='D'){
      count++;
    }
  }
  cout<<setprecision(10)<<count/n<<endl;
}