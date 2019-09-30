#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long unsigned int ll;
 
int main() {
 
  vector<int> N(3);
  cin >> N[0];
  cin >> N[1];
  cin >> N[2];
  sort(N.begin(),N.end());
  if(N[2]==N[0]+N[1]){
  	cout << "Yes"<<endl;
  }else{
	cout << "No" <<endl;
  }
  
    return 0;
}