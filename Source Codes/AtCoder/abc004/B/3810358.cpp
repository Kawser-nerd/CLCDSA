#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	char c[16];
	for(int i=0;i<16;i++){
		cin >> c[i];
	}
	
	for(int j=15;j>=0;j--){
		cout << c[j] << " ";
		if(j%4 == 0){
			cout << endl;
		}
	}
	
	return 0;
}