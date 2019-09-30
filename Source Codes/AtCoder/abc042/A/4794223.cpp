#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long unsigned int ll;

int main() {

  vector<int> A(3);
  cin >> A[0];
  cin >> A[1];
  cin >> A[2];
  
  sort(A.begin(),A.end());
  if(A[0]==5&&A[1]==5&&A[2]==7){
	cout << "YES" <<endl;
  }else{
    cout <<"NO" <<endl;
  }
}