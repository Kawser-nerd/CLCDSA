#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
 
  vector<string> hands(3);
  cin>>hands[0]>>hands[1]>>hands[2];
  int turn_mng=0,next_turn;
  while(1){
  	if(hands[turn_mng].empty()){
    	cout<<(char)('A'+turn_mng)<<endl;
    	return 0;
    }else{
      next_turn=*hands[turn_mng].begin()-'a';
      hands[turn_mng].erase(hands[turn_mng].begin());
      turn_mng=next_turn;
      
    }
    
  }
  
  return 0;
}