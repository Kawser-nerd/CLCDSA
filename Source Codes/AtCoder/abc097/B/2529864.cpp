#include <iostream>
#include <vector>
using namespace std;
#define rep(i,N) for(i=0;i<N;i++)
int main(){
  int X;

  //input X
  cin >> X;
  vector <bool > expo(X+1);
  //i = 1 expo[1] = 1;
  expo[1] = 1;
  // X>=i>=2 : X ????????????
  for(int i = 2;i<=X;i++){
    int a = i * i;
    while(a<=X){
      expo[a] = 1;
      a *= i;
    }
  }

  //output
  for(int i=X;i >=1; i--)
    if(expo[i]) {
      cout << i << endl;
      return 0;
    }
}