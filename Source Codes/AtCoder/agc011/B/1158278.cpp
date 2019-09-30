#include <iostream>
#include <vector>
#include <algorithm>

int main(){
  unsigned N;
  std::cin>>N;
  std::vector<unsigned long> A(N);
  for(auto &a:A)
    std::cin>>a;

  std::sort(A.begin(),A.end());

  unsigned long sum = A[0];
  unsigned i,j=0;
  for(i=1;i<N;++i){
    if(sum*2<A[i]){
      j=i;
    }
    sum += A[i];
  }
  
  if(j==0){
    std::cout<<N<<std::endl;
  }else{
    std::cout<<N-j<<std::endl;
  }
  return 0;
}