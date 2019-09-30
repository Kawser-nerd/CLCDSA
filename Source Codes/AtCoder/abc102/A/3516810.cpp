#include<cstdio>
using namespace std;
int main(){
  long n;
  scanf("%ld",&n);
  if(n%2==1)
    n*=2;
  printf("%ld\n",n);
}