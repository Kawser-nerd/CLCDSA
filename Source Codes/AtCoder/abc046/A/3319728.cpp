#include<iostream>

int main(){
  int x;
  int a[3];
  int i=0;
  int cnt=0;

  while(std::cin>>x){
    for(int j=0;j<i;j++){ 
      if(a[j]==x){
        cnt++;
      }
    }
    if(cnt==0){
      a[i]=x;
      i++;
    }
    cnt=0;

  }


  std::cout<<i<<std::endl;
  return 0;
}