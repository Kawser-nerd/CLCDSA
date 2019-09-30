#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
typedef long long unsigned int ll;
 
int main() {
 
  int a=0;
  char s;
  for(int i=0;i<4 ;i++){
    cin >>s;
    if(s=='+'){
		a++;
    }else{
		a--;
    }
  }	
  cout <<a<<endl;
  
   return 0;
}