#include <iostream>
using namespace std;
typedef long long unsigned int ll;
 
int main() {
 
  int N,K,X,Y;
  cin >> N;
  cin >> K;
  cin >> X;
  cin >> Y;
  if(N>=K){
  cout << K*X+(N-K)*Y <<endl;
  }else{
	cout << N*X<<endl;
  }
    return 0;
}