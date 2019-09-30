#include <iostream>

using namespace std;

int main(){
  int n,x;
  cin>>n>>x;
  int tub=1,result=0;
  char tmp;
  scanf("%c",&tmp);
  while(n--){
    scanf("%c",&tmp);
    if(tmp=='-'){
      tub--;
    }else{
      tub++;
    }
    if(tub>x){
      result++;
      tub=1;
    }
    
  }
cout<<result<<endl;
}