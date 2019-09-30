#include <iostream>
using namespace std;
typedef long long unsigned int ll;
 
int main() {
 
  char N;
  cin >> N;
  if(N=='a'||N=='i'||N=='u'||N=='e'||N=='o'){
	
  	cout << "vowel"<<endl;
  }else{
	cout << "consonant"<<endl;
  }
    return 0;
}