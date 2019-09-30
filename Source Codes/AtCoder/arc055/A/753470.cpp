#include <iostream>
#include <cstring>
 
using namespace std;
 
int main(){
	int N,i;
	//unsigned long long x,y;
	string x;
	x = '1';
	cin>>N;
	
	N--;
	for(i=0;i<N;i++){
		//x = x*10;
		x+='0';
	}
	
	
 
	//y = x+7;
	x+='7';

	cout<<x<<endl;
 
	return 0;
}